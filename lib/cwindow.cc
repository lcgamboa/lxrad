/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001  Luis Claudio Gamboa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */

#include<stdio.h>

#include"../include/cwindow.h"
#include"../include/cmenu.h"
#include"../include/capplication.h"
#include"../include/newcontrolbycname.h"


//CWindow _______________________________________________________________

CWindow::CWindow (void)
{
  SetClass (wxT("CWindow"));
  Win = NULL;
  SetX (0);
  SetY (0);
  SetWidth (300);
  SetHeight (200);
  SetBorder (1);
  Visible = 1;
  Title = wxT("LXRAD Window");
  WParent = NULL;
  OverrideRedirect = false;
//events
  EvOnCreate = NULL;
  EvOnDestroy = NULL;
  EvOnShow = NULL;
  EvOnHide = NULL;
  EvOnEnter = NULL;
  EvOnLeave = NULL;
//  CanDestroy= true;
  modalmode=NULL;
};

CWindow::~CWindow (void)
{
};


int
CWindow::Create (CControl * control)
{
  Win=this;
  if(!OverrideRedirect)
  {
  Widget = new wxFrame(NULL,GetWid(),Title,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxDEFAULT_FRAME_STYLE,GetName());
   }
   else
  {
  Widget = new wxFrame(NULL,GetWid(),Title,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()), wxFRAME_SHAPED | wxNO_BORDER | wxFRAME_NO_TASKBAR | wxSTAY_ON_TOP,GetName());
 
   }

    //Widget->SetIcon(wxICON(sample));
 

    //TODO map event direct to the handle
    Widget->Bind(wxEVT_SIZE,&CWindow::Event,this,GetWid()); 
    Widget->Bind(wxEVT_MAXIMIZE,&CWindow::Event,this,GetWid()); 
//    Widget->Bind(wxEVT_DESTROY,&CWindow::Event,this,GetWid()); 
    Widget->Bind(wxEVT_CLOSE_WINDOW,&CWindow::Event,this,GetWid()); 



  
  return CControl::Create (control);
  
};



int CWindow::CEvent (int event)
{
if(event == wxEVT_DESTROY)return lxEVT_DESTROY;
if(event == wxEVT_MAXIMIZE)return lxEVT_MAXIMIZE;
if(event == wxEVT_SIZE)return lxEVT_SIZE;
if(event == wxEVT_CLOSE_WINDOW)return lxEVT_CLOSE_WINDOW;

return CControl::CEvent(event);
};


void
CWindow::WCreate (int WN, CWindow * window)
{
  WNumber = WN;
  SetWid(WN);
/*
  if (OverrideRedirect)
    WWindow = gtk_window_new (GTK_WINDOW_POPUP);
  else
    WWindow = gtk_window_new (GTK_WINDOW_TOPLEVEL);
*/
/*
  gtk_widget_realize (WWindow);

  gtk_window_set_title (GTK_WINDOW (WWindow), Title.c_str ());

  gtk_window_move (GTK_WINDOW (WWindow), X, Y);
  gtk_window_resize (GTK_WINDOW (WWindow), Width, Height);

  gtk_container_set_border_width (GTK_CONTAINER (WWindow), 2);

  WBox = gtk_vbox_new (false, 0);

  WFixed = gtk_fixed_new ();

  gtk_box_pack_start (GTK_BOX (WBox), WFixed, true, true, 0);

  gtk_container_add (GTK_CONTAINER (WWindow), WBox);
*/

  Win = this;

  Create (this);
  Draw ();
  on_create ();
  if (Visible)
    Show ();

};

void
CWindow::Destroy (void)
{
//  Win = NULL;
//  WWindow = NULL;
  on_destroy ();
  CControl::Destroy ();
  //DestroyChilds();
  
   if (Widget)
   {
     Widget->Close(true);
     Widget=NULL;
   }
   
};


void
CWindow::Draw (void)
{
  CControl::Draw ();
};


void
CWindow::DestroyChild (CControl * control)
{
  CControl::DestroyChild (control);
};

void
CWindow::DestroyChilds (void)
{
  CControl::DestroyChilds ();
};



void
CWindow::WDestroy (void)
{
  Hide ();
  
  Application->ADestroyWindow (Wid);
};

void
CWindow::Show (void)
{
  SetVisible (true);
  if (GetWWidget() != NULL)
    {
      ((wxFrame*)GetWWidget())->Show(true);
      ((wxFrame*)GetWWidget())->Raise();
    };
};

void
CWindow::ShowExclusive (void)
{
  Show ();
  CanExitExclusive = true;
  modalmode = new wxWindowDisabler(GetWWidget()); 

};

void
CWindow::Hide (void)
{
  if (GetWWidget() != NULL)
    {
      SetVisible (false);
      ((wxFrame*)GetWWidget())->Show(false);
    };
};

void
CWindow::HideExclusive (void)
{
  if(modalmode)
  {
    delete modalmode;
    modalmode=NULL;
  }
  Hide ();
  CanExitExclusive = false;
};

void
CWindow::Update (void)
{
  CControl::Update ();
};


int
CWindow::GetWNumber (void)
{
  return WNumber;
};


void
CWindow::SetOverrideRedirect (bool redirect)
{
  OverrideRedirect = redirect;
};

bool CWindow::GetOverrideRedirect (void)
{
  return OverrideRedirect;
};

bool 
CWindow::GetCanExitExclusive(void)
{
  return CanExitExclusive;
};

void
CWindow::SetSaveUnder (bool saveunder)
{
};


void
CWindow::Event (wxEvent & event)
{

   //FIXME clean the code
   switch (CEvent(event.GetEventType()))
    { 
    case lxEVT_DESTROY:
      on_destroy ();
      return;
      break;
    case lxEVT_MAXIMIZE:
//    case lxEVT_PAINT:
    case lxEVT_SIZE:
      on_show ();
      break;
    case lxEVT_CLOSE_WINDOW:
      on_hide ();
      //FIXME call applicatina::wdelete callback!!!!!!!!
       if(Application->ADestroyWindow ((wxCloseEvent*) &event)) 
       {
/*
         if (!((wxCloseEvent*) &event)->CanVeto()) 
         {
           ((wxCloseEvent *)&event)->Skip();
         }
         else
         {
           ((wxCloseEvent *)&event)->Veto(); 
         };
*/
        }
      return; 
      break;
      /*
    case lxEVT_SET_FOCUS:
      on_enter ();
      return 1;
      break;
    case lxEVT_KILL_FOCUS:
      on_leave ();
      return 1;
      break;
      */
/*
  case GDK_FOCUS_CHANGE:
         if (WWindow != NULL)
	 {
         gtk_window_get_position (GTK_WINDOW (WWindow), &X, &Y);
         gtk_window_get_size (GTK_WINDOW (WWindow), (int*)&Width,(int*)&Height);
	 };
         CControl::Event (widget, event);
      return 1;
  
      break;
*/

    default:
      //return CControl::Event (widget, event);
      break;
    };

   CControl::Event(event);
}


CStringList
CWindow::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Title"), wxT("String"), GetTitle ()));
  Context.AddLine (xml_out (wxT("OverrideRedirect"), wxT("bool"), itoa (GetOverrideRedirect ())));
  //events 
  Context.AddLine (xml_out (wxT("EvOnCreate"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnDestroy"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnShow"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnHide"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnEnter"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnLeave"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CWindow::SetContext (CStringList context)
{
  String name, type, value;
  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Title")) == 0)
	SetTitle (value);
      if (name.compare (wxT("OverrideRedirect")) == 0)
	SetOverrideRedirect (atoi (value));
      if (name.compare (wxT("EvOnCreate")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnDestroy")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnShow")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnHide")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnEnter")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnLeave")) == 0)
	SetEv (atob (value));
    };
};

int
CWindow::LoadXMLContextAndCreateChilds (String filename, CControl* ctrl)
{
  wxTextFile file2;
  CStringList list;
  String line;

  file2.Open (filename);
  file2.GoToLine (-1);

  

  if (file2.IsOpened ())
    {

      if(ctrl == NULL)//for owner window
      {
        if(fgetline (file2, line))
        {
          ctrl = this;
          ctrl->SetName(line.substr (1, line.size () - 2));//Get Window name
          file2.GoToLine (-1);
        }
      }

      list.Clear ();
      while (fgetline (file2, line))
        {
          if (line.compare (wxT ("<") + ctrl->GetName () + wxT (">")) == 0)
            {
              fgetline (file2, line);
              do
                {
                  list.AddLine (line);
                  fgetline (file2, line);
                }
              while (line[0] == ' ');
              ctrl->SetContext (list);

              while (line.compare (wxT ("</") + ctrl->GetName () + wxT (">")) != 0)
                {
                  String controlclass, ctype, name, cname;

                  cname = line.substr (1, line.size () - 2);
                  fgetline (file2, line);
                  xml_in (line, name, ctype, controlclass);

                  CControl *ch = newcontrolbycname (controlclass);
                  ch->SetName (cname);
                  ch->SetFOwner (ctrl);
                 
		  /* 
		  if (ch->GetClass ().compare (wxT ("CItemMenu")) == 0)
                    {
                      ch->SetVisible (false, false);
                    };
                  */
                  ctrl->CreateChild (ch);

                  if (ch != NULL)
                    LoadXMLContextAndCreateChilds (filename, ch);
                  else
                    printf ("Child Not Found! %s \n", (char*) name.char_str ());

                  do
                    {
                      fgetline (file2, line);
                    }
                  while ((line.compare (wxT ("</") + cname + wxT (">")) != 0));
                  fgetline (file2, line);
                };

            };

        };

      file2.Close ();
      return 1;
    }
  else
    printf ("File (%s) not found!\n",(char *)filename.char_str());

  return 0;
};


void
CWindow::SetFocus (void)
{
  GetWWidget()->SetFocus();
};

void
CWindow::SetControlOnFocus (CControl * control)

{
  if((control != NULL)&&(control->GetWidget()))
  {
    ControlOnFocus=control;
    if(control->GetCanVisible())
      control->GetWidget()->SetFocus();
  }
  else
  {
      GetWidget()->SetFocus();
      ControlOnFocus=NULL;
  };

};

CControl *
CWindow::GetControlOnFocus (void)
{

  if(GetWWidget())
  {	
      if(GetWWidget()->FindFocus())
        ControlOnFocus=GetChildByWidget(GetWWidget()->FindFocus());
      else
        ControlOnFocus=this;
  }
  /*
  GtkWidget *control;
 
  control = gtk_window_get_focus (GTK_WINDOW (Widget));
  if (control != NULL)
    {
      for (int i = 0; i <= ChildCount; i++)
	{
	  if (Child[i]->GetWidget () == control)
	  {
	     ControlOnFocus=Child[i];
	     return Child[i];
	  };
	};
    };
  */
  return ControlOnFocus;
};

wxWindow *
CWindow::GetWWidget (void)
{
  if (Widget != NULL)
    return Widget;
  else
    return NULL;
};


//propiedades

void
CWindow::SetCanDestroy (bool candestroy)
{
  CanDestroy = candestroy;
};

bool CWindow::GetCanDestroy (void)
{
  return CanDestroy;
};

void
CWindow::SetTitle (const String & title)
{
  Title = title;

if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->SetTitle(Title.c_str ());

};

String
CWindow::GetTitle (void)
{
  return Title;
};

void
CWindow::SetX (int x)
{
  X = x;

if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);
};

int
CWindow::GetX (void)
{
  if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->GetPosition(&X,&Y);
  
  return X;
};

void
CWindow::SetY (int y)
{
  Y = y;

if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);
};

int
CWindow::GetY (void)
{
  if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->GetPosition(&X,&Y);

  return   Y;
};

void
CWindow::SetWidth (uint width)
{
  Width = width;

if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);

};
  
uint 
CWindow::GetWidth (void)
{
  if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->GetSize((int*)&Width,(int*)&Height);
  
  return Width;
};

void
CWindow::SetHeight (uint height)
{
  Height = height;

if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);
};

uint 
CWindow::GetHeight(void)
{
if (GetWWidget() != NULL)
    ((wxFrame*)GetWWidget())->GetSize((int*)&Width,(int*)&Height);
   
   return Height;
};

int CWindow::GetVScale (int h)
{
  return (int) (h * VScale + 0.5);
};

int CWindow::GetHScale (int w)
{
  return (int) (w * HScale + 0.5);
};


//operators

void *
CWindow::operator new (size_t sz)
{
  CWindow *m = (CWindow *) calloc (sz, 1);
  if (!m)
    puts ("out of memory");
  m->Dynamic = true;
  m->CanDestroy = true;
  return (void *) m;
};


void 
CWindow::operator
delete (void * p)
{
  CWindow* pc = static_cast<CWindow*>(p);
  free(pc);
};


//eventos

void
CWindow::on_create (void)
{
  if ((FOwner) && (EvOnCreate))
    (FOwner->*EvOnCreate) (this);
};

void
CWindow::on_destroy (void)
{
  if ((FOwner) && (EvOnDestroy))
    (FOwner->*EvOnDestroy) (this);
};

void
CWindow::on_show (void)
{
  if ((FOwner) && (EvOnShow))
    (FOwner->*EvOnShow) (this);
};

void
CWindow::on_hide (void)
{
  if ((FOwner) && (EvOnHide))
    (FOwner->*EvOnHide) (this);
};

void
CWindow::on_enter (void)
{
  if ((FOwner) && (EvOnEnter))
    (FOwner->*EvOnEnter) (this);
};

void
CWindow::on_leave (void)
{
  if ((FOwner) && (EvOnLeave))
    (FOwner->*EvOnLeave) (this);
};

