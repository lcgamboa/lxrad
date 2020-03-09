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

#include"../include/ccontrol.h"
#include"../include/cwindow.h"
#include"../include/cpmenu.h"
#include"../include/capplication.h"



extern CApplication *Application;

#include<stdio.h>

// CControl______________________________________________________________


CControl::CControl (void)
{
  //Dynamic = false;
  Widget = NULL;
//  SWidget = NULL;
  Owner = NULL;
  Win = NULL;
  ChildCount = -1;
  Child = NULL;
  SetX (0);
  SetY (0);
  Border = 1;
  Width = 10;
  Height = 10;
  Visible = true;
  Tag = 0;
  Wid=0;	
  CanExecuteEvent = true;
  CanFocus = true;
  CanVisible = true;
  Enable = true;
  FOwner = NULL;
  FontName = wxT("-misc-fixed-medium-r-normal--10-100-75-75-c-60-iso8859-1");
  SetClass (wxT("CControl"));
  PopupMenu = NULL;
  SetHint (wxT(""));

  EvMouseMove = NULL;
  EvMouseButtonPress = NULL;
  EvMouseButtonRelease = NULL;
  EvMouseButtonClick = NULL;
  EvMouseButtonDoubleClick = NULL;
  EvKeyboardPress = NULL;
  EvKeyboardRelease = NULL;
  EvOnDraw = NULL;
  EvOnFocusIn = NULL;
  EvOnFocusOut = NULL;

  //CFont = NULL;
  ColorName = wxT("");
  ColorRGB[0]=0;
  ColorRGB[1]=0;
  ColorRGB[2]=1;
};

CControl::~CControl ()
{
//  eprint("~"+GetClass()+"\n");
  if (Child)
    {
      for (int c = 0; c <= ChildCount; c++)
	{
	  if (Child[c]->GetDynamic ())
	    delete Child[c];
	  Child[c] = NULL;
	};
      ChildCount = -1;
      delete[]Child;
      Child = NULL;
    };
};

int
CControl::Create (CControl * control)
{
  SetOwner (control);
  
  if(FOwner == NULL)SetFOwner(control);


  Win = control->Win;
  SetName (Name);
 
#ifdef _DEBUG_ 
#ifdef __UNICODE__
  printf("creating %ls->%ls->%lu  %p\n",(const wchar_t *)Class.c_str(),(const wchar_t *)Name.c_str(),Wid,GetWidget());
#else
  printf("creating %s->%s->%lu  %p\n",(const char*)Class.c_str(),(const char*)Name.c_str(),Wid,GetWidget());
#endif
#endif

/*
  if(SWidget != NULL)
    widget=SWidget;
  else
    widget=Widget;
*/



  if ((CanExecuteEvent) && (Widget != NULL))
    {

    //TODO map event direct to the handle
    Widget->Bind(wxEVT_PAINT,&CControl::Event,this,GetWid());
    Widget->Bind(wxEVT_KEY_DOWN,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_KEY_UP,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_LEFT_DOWN,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_LEFT_UP,&CControl::Event,this,GetWid()); 
    //Widget->Bind(wxEVT_LEFT_DCLICK,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_RIGHT_DOWN,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_RIGHT_UP,&CControl::Event,this,GetWid()); 
    //Widget->Bind(wxEVT_RIGHT_DCLICK,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_MOTION,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_ENTER_WINDOW,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_LEAVE_WINDOW,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_SET_FOCUS,&CControl::Event,this,GetWid()); 
    Widget->Bind(wxEVT_KILL_FOCUS,&CControl::Event,this,GetWid()); 


  
    }  


  if (ChildCount > -1)
    {
      for (int i = 0; i <= ChildCount; i++)
	{
	  CreateChild (Child[i], true);
	};
    };

  if (!Enable)
    {
      Enable = true;
      SetEnable (false);
    };

  if (Visible)
    SetVisible (Visible);
  else
    Erase();

  SetHint (Hint);

  if(ColorName.size() > 0)
     SetColorName(ColorName);
  
  if(ColorRGB[0]+ColorRGB[1]+ColorRGB[2] != 1)  
    SetColor(ColorRGB[0],ColorRGB[1],ColorRGB[2]);  

  return 1;
};



void
CControl::Destroy (void)
{
#ifdef _DEBUG_
  mprint(wxT("Destruindo: ")+Class+wxT("   ")+Name+wxT("\n"));
#endif

  DestroyChilds ();

  if (Widget != NULL)
    {
      Widget->Destroy();
      //delete Widget;
    }
  Widget = NULL;


};



wxWindow *
CControl::GetWidget (void)
{
  if (Widget != NULL)
    return Widget;
  else
    return NULL;
};


CWindow *
CControl::GetWin (void)
{
  return Win;
};

void
CControl::SetWin (CWindow * win)
{
  Win = win;
};

void
CControl::SetName (const String name)
{
  Name = name;
  if (Widget != NULL)
    Widget->SetName(Name.c_str ());
};

String CControl::GetName (void)
{
  return Name;
};

void
CControl::Draw (void)
{
  if ((!Visible))
    return;

  if (Widget != NULL)
      Widget->Refresh();

/*  
     if (ChildCount != -1)
     for (int i = 0; i <= ChildCount; i++)
     {
        Child[i]->Draw ();
     }
     Update ();
  */ 
}

void
CControl::Update (void)
{
   if(Widget)
      Widget->Update();
};

void
CControl::Erase (void)
{
    if ((Widget != NULL)&& (CanVisible == true))
      Widget->Hide();

};




int CControl::CEvent (int event)
{

if(event == wxEVT_MOTION)return lxEVT_MOTION;
if(event == wxEVT_KEY_DOWN)return lxEVT_KEY_DOWN;
if(event == wxEVT_KEY_UP)return lxEVT_KEY_UP;
if(event == wxEVT_LEFT_DOWN)return lxEVT_LEFT_DOWN;
if(event == wxEVT_LEFT_UP)return lxEVT_LEFT_UP;
if(event == wxEVT_LEFT_DCLICK)return lxEVT_LEFT_DCLICK;
if(event == wxEVT_RIGHT_DOWN)return lxEVT_LEFT_DOWN;
if(event == wxEVT_RIGHT_UP)return lxEVT_LEFT_UP;
if(event == wxEVT_RIGHT_DCLICK)return lxEVT_LEFT_DCLICK;
if(event == wxEVT_ENTER_WINDOW)return lxEVT_ENTER_WINDOW;
if(event == wxEVT_LEAVE_WINDOW)return lxEVT_LEAVE_WINDOW;
if(event == wxEVT_PAINT)return lxEVT_PAINT;
if(event == wxEVT_SET_FOCUS)return lxEVT_SET_FOCUS;
if(event == wxEVT_KILL_FOCUS)return lxEVT_KILL_FOCUS;

return -1;
}




void
CControl::Event ( wxEvent & event)
{
      event.Skip();   	 


//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_MOTION:
	  mouse_move ((wxMouseEvent* ) &event);
	  break;
	case lxEVT_KEY_DOWN:
	  key_press ((wxKeyEvent *) &event);
	  break;
	case lxEVT_KEY_UP:
	  key_release ((wxKeyEvent *) &event);
	  break;
	case lxEVT_LEFT_DOWN:
	case lxEVT_RIGHT_DOWN:
    	  button_press ((wxMouseEvent *) &event);
	  break;
	case lxEVT_LEFT_UP:
	case lxEVT_RIGHT_UP:
	  button_release ((wxMouseEvent *) &event);
	  break;

	case lxEVT_ENTER_WINDOW:
    	case lxEVT_SET_FOCUS:
	    focus_in ((wxMouseEvent *) &event);
	  break;
    	case lxEVT_KILL_FOCUS:
	case lxEVT_LEAVE_WINDOW:
	    focus_out ((wxMouseEvent *) &event);
	  break;
	    
	case lxEVT_PAINT:
	  on_draw ((wxPaintEvent *) &event);
	  break;
	default:
	  //printf("default !!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
	  break;
	};

};


void
CControl::DestroyChilds (void)
{
  for (int c = 0; c <= ChildCount; c++)
    {
      //Child[c]->SetVisible (false);
      Child[c]->Destroy ();
      if (Child[c]->GetDynamic ())
	delete Child[c];
      Child[c] = NULL;
    };
  ChildCount = -1;
  delete[]Child;
  Child = NULL;

};

void
CControl::CreateChild (CControl * control, bool onlyput)
{
  if (!onlyput)
    {
      ChildCount++;
      CControl **Child1;
      Child1 = new CControl *[ChildCount + 1];
      for (int c = 0; c < ChildCount; c++)
	Child1[c] = Child[c];
      Child1[ChildCount] = control;
      //control->SetWid(this->GetWid()+ChildCount+1);
      control->SetWid(wxNewId());
      if (Child)
	delete[]Child;
      Child = Child1;
    };
  
     if (Win != NULL)
     control->Create (this);
   

};

void
CControl::DestroyChild (CControl * control)
{
  int childn = -1;
  for (int f = 0; f <= ChildCount; f++)
    if (Child[f] == control)
      {
	childn = f;
	break;
      };
  if (childn != -1)
    {
      //Child[childn]->Eraser ();
      Child[childn]->Destroy ();
      if (Child[childn]->GetDynamic ())
	delete Child[childn];
      for (int c = childn; c < ChildCount; c++)
	Child[c] = Child[c + 1];

      Child[ChildCount] = NULL;
      ChildCount--;
    };
};


CStringList
CControl::GetContext (void)
{
  CObject::GetContext ();
//propierties
  Context.AddLine (xml_out (wxT("X"), wxT("int"), itoa (GetX ())));
  Context.AddLine (xml_out (wxT("Y"), wxT("int"), itoa (GetY ())));
  Context.AddLine (xml_out (wxT("Width"), wxT("uint"), itoa (GetWidth ())));
  Context.AddLine (xml_out (wxT("Height"), wxT("uint"), itoa (GetHeight ())));
  Context.AddLine (xml_out (wxT("Hint"), wxT("String"), GetHint ()));
  Context.AddLine (xml_out (wxT("Enable"), wxT("bool"), itoa (GetEnable ())));
  Context.AddLine (xml_out (wxT("Visible"), wxT("bool"), itoa (GetVisible ())));
  Context.AddLine (xml_out (wxT("Color"), wxT("String"), GetColor ().GetAsString (wxC2S_HTML_SYNTAX) ));

  if (PopupMenu)
    Context.AddLine (xml_out (wxT("PopupMenu"), wxT("PopupMenu"), PopupMenu->GetName ()));
  else
    Context.AddLine (xml_out (wxT("PopupMenu"), wxT("PopupMenu"), wxT("NULL")));

//events  
  Context.AddLine (xml_out (wxT("EvMouseMove"), wxT("Event"), btoa (GetEv (true))));
  Context.AddLine (xml_out (wxT("EvMouseButtonPress"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvMouseButtonRelease"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvMouseButtonClick"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvMouseButtonDoubleClick"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvKeyboardPress"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvKeyboardRelease"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnDraw"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnFocusIn"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnFocusOut"), wxT("Event"), btoa (GetEv ())));


  return Context;
};

void
CControl::SetContext (CStringList context)
{
  String name, type, value;

#ifdef _DEBUG_
#ifdef __UNICODE__
  printf("##########SetContext(%ls)\n",(const wchar_t*)GetName().c_str());	
#else
  printf("##########SetContext(%s)\n",(const char *)GetName().c_str());	
#endif
#endif
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
     
      //printf("Set%ls\n",name.c_str()); 
 
      if (name.compare (wxT("X")) == 0)
	SetX (atoi (value));
      if (name.compare (wxT("Y")) == 0)
	SetY (atoi (value));
      if (name.compare (wxT("Width")) == 0)
	SetWidth (atoi (value));
      if (name.compare (wxT("Height")) == 0)
	SetHeight (atoi (value));
      if (name.compare (wxT("Hint")) == 0)
	SetHint (value);
      if (name.compare (wxT("Enable")) == 0)
	SetEnable (atoi (value));
      if (name.compare (wxT("Visible")) == 0)
      {
	SetVisible (!(atoi (value)),false);
	SetVisible (atoi (value));
      }
      if (name.compare (wxT("Color")) == 0)
	if(value.compare(wxT("#000001")) != 0 )//color not defined      
	   SetColor (wxColor(value));
      if (name.compare ("PopupMenu") == 0)
	if (value.compare ("NULL") != 0)
	  SetPopupMenu (dynamic_cast < CPMenu * >(Win->GetChildByName (value)));
      if (name.compare (wxT("EvMouseMove")) == 0)
	SetEv (atob (value), true);
      if (name.compare (wxT("EvMouseButtonPress")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvMouseButtonRelease")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvMouseButtonClick")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvMouseButtonDoubleClick")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvKeyboardPress")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvKeyboardRelease")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnDraw")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnFocusIn")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnFocusOut")) == 0)
	SetEv (atob (value));
    };
};

void
CControl::WriteXMLContext (String filename, bool first)
{
  CStringList list;
  list = GetContext ();
  list.InsertLine (wxT("<") + Name + wxT(">"), 0);
  if (first)
    list.SaveToFile (filename);
  else
    list.AppendToFile (filename);

  for (int i = 0; i <= ChildCount; i++)
    {
      Child[i]->WriteXMLContext (filename, false);
      /*    
         list=Child[i]->GetContext();
         list.InsertLine("<"+Child[i]->GetName()+">",0);
         list.AddLine("<\\"+Child[i]->GetName()+">");
         list.AppendToFile(filename);    
       */
    };
  list.Clear ();
  list.AddLine (wxT("</") + Name + wxT(">"));
  list.AppendToFile (filename);
};

void
CControl::LoadXMLContext (String filename)
{
  wxTextFile fin;
  CStringList list;
  String line, name;

  fin.Open(filename);
  fin.GoToLine(0);
  
  //printf("<XML_%ls>\n",Name.c_str());
 
  if (fin.IsOpened())
    {
      list.Clear ();
      while (fgetline (fin, line))
	{
#ifdef _DEBUG_
#ifdef __UNICODE__
          printf("%ls == %ls ???\n",(const wchar_t*)line.c_str(),(const wchar_t*) (wxT("<") + Name + wxT(">")).c_str());
#else
          printf("%s == %s ???\n",(const char*)line.c_str(), (const char *)(wxT("<") + Name + wxT(">")).c_str());
#endif
#endif

	  if (line.compare (wxT("<") + Name + wxT(">")) == 0)
	    {
	      fgetline (fin, line);
	      do
		{
		  list.AddLine (line);
		  fgetline (fin, line);
		}
	      while (line[0] == ' ');
	      SetContext (list);

	      while (line.compare (wxT("</") + Name + wxT(">")) != 0)
		{
		  name = line.substr (1, line.size () - 2);
		  CControl *ch = GetChildByName (name);
		  if (ch != NULL)
		    ch->LoadXMLContext (filename);
		  else
		    printf ("Child Not Found! %s \n", (char *)name.char_str ());
		  do
		    {
		      fgetline (fin, line);
		    }
		  while ((line.compare (wxT("</") + name + wxT(">")) != 0));
		  fgetline (fin, line);
		};

	    };

	};

      fin.Close();
      //printf("<\\XML_%s>\n",Name.c_str());
    }
  else
    printf ("File not found!\n");


};

String
CControl::GetFontName (void)
{
  return FontName;
};
  

void 
CControl::SetFont (const String font)
{
  FontName=font;
};

void
CControl::SetFontSize (uint size)
{
  FontSize = size;
};

uint CControl::GetFontSize (void)
{
  return FontSize;
};

void
CControl::SetHint (String hint)
{
  Hint = hint;
/*
if ((Widget != NULL) && (Hint.size () > 0))
    Application.SetTips (this);
*/
};

String CControl::GetHint (void)
{
  return Hint;
};

void
CControl::SetX (int x)
{
  X = x;
  if ((Widget != NULL)&& (CanVisible == true))
       Widget->SetSize(X,Y,Width,Height,wxSIZE_USE_EXISTING);
       //Widget->SetSize(x,-1,-1,-1,wxSIZE_USE_EXISTING);

};

int
CControl::GetX (void)
{
  return X;
};

void
CControl::SetY (int y)
{
  Y = y;
  if ((Widget != NULL)&& (CanVisible == true))
       Widget->SetSize(X,Y,Width,Height,wxSIZE_USE_EXISTING);
       //Widget->SetSize(-1,y,-1,-1,wxSIZE_USE_EXISTING);
};

int
CControl::GetY (void)
{
  return Y;
};

void
CControl::SetWidth (uint w)
{
  Width = w;
  if ((Widget != NULL)&& (CanVisible == true))
       Widget->SetSize(X,Y,Width,Height,wxSIZE_USE_EXISTING);
       //Widget->SetSize(-1,-1,w,-1,wxSIZE_USE_EXISTING);
};

uint CControl::GetWidth (void)
{
  return Width;
};

void
CControl::SetHeight (uint h)
{
  Height = h;
  if ((Widget != NULL)&& (CanVisible == true))
       Widget->SetSize(X,Y,Width,Height,wxSIZE_USE_EXISTING);
       //Widget->SetSize(-1,-1,-1,h,wxSIZE_USE_EXISTING);
};

uint CControl::GetHeight (void)
{
  return Height;
};
  
  
void CControl::SetWid (int wid)
{
  Wid=wid;
};

long CControl::GetWid (void)
{
  return Wid;
};

void
CControl::SetBorder (uint b)
{
  Border = b;
};

uint CControl::GetBorder (void)
{
  return Border;
};

void
CControl::SetColorName (const String name)
{
  ColorName = name;
  
  wxColour color(name);
  if (Widget != NULL)
     Widget->SetOwnBackgroundColour(color);

};

void
CControl::SetColor (uint r, uint g, uint b)
{
  ColorRGB[0]=r;
  ColorRGB[1]=g;
  ColorRGB[2]=b;

  wxColour color(r,g,b);
  if (Widget != NULL)
     Widget->SetOwnBackgroundColour(color);
};

void
CControl::SetColor (wxColor color)
{ 
  ColorRGB[0]=color.Red ();
  ColorRGB[1]=color.Green ();
  ColorRGB[2]=color.Blue ();

  if (Widget != NULL)
     Widget->SetOwnBackgroundColour(color);

};


wxColor 
CControl::GetColor(void)
{
  return wxColor(ColorRGB[0],ColorRGB[1],ColorRGB[2]);
}


void
CControl::SetEnable (bool enable)
{
  Enable = enable;

  if ((Widget != NULL)&& (CanVisible == true))
    Widget->Enable(enable);

};

bool
CControl::GetEnable (void)
{
  return Enable;
};

CControl *
CControl::GetOwner (void)
{
  return Owner;
};

void
CControl::SetOwner (CControl * control)
{
  Owner = control;

};

void
CControl::SetVisible (bool visible, bool update)
{

//Widget->IsShown();

  if ((update)&&(Visible != visible))
  {
    if (visible)
      {
	Visible = visible;
	if ((Widget != NULL)&& (CanVisible == true))
	  Widget->Show();
	//Update ();
      }
    else
      {
	Erase ();
	Visible = visible;
      }
  }
  else
    Visible = visible;
  
};

bool CControl::GetVisible (void)
{
  return Visible;
};

bool CControl::GetCanVisible (void)
{
  return CanVisible;
};


void
CControl::SetPopupMenu (CPMenu * popupmenu)
{
  PopupMenu = popupmenu;

  if (Widget != NULL)
  {
    Widget->PopupMenu ((wxMenu*) (PopupMenu->GetWidget ()),PopupMenu->GetX() , PopupMenu->GetY());
  }
};

void
CControl::SetFocus (void)
{
  if ((CanFocus)&&(Widget != NULL))
    {
      Widget->SetFocus();
    };
};

bool CControl::GetFocus (void)
{
  if (Widget != NULL)
    return Widget->FindFocus();
  else
    return false;
};

void
CControl::SetCanFocus (bool canfocus)
{
  CanFocus = canfocus;
};

bool CControl::GetCanFocus (void)
{
  return CanFocus;
};

bool CControl::GetDynamic (void)
{
  return Dynamic;
};

int
CControl::GetChildCount (void)
{
  return ChildCount;
};


CControl *
CControl::GetChild (uint child)
{
  return Child[child];
};


CControl *
CControl::GetChildByWidget (wxWindow * widget)
{
  CControl *ch;

  for (int a = 0; a <= ChildCount; a++)
  {
    if(Child[a] != NULL)
    {
      if (Child[a]->GetWidget () == widget)
        return Child[a];
    
      if ((ch=Child[a]->GetChildByWidget(widget)))
        return ch;
    }
  }

  return NULL;

};

CControl *
CControl::GetChildByWid (long wid)
{
CControl *ch;

  for (int a = 0; a <= ChildCount; a++)
  {
    if (Child[a]->GetWid() == wid)
      return Child[a];
    
    if ((ch=Child[a]->GetChildByWid(wid)))
      return ch;
  }


  return NULL;

};




CControl *
CControl::GetChildByName (const String child)
{
CControl *ch;

 for (int a = 0; a <= ChildCount; a++)
  {
    if (Child[a]->GetName ().compare (child) == 0)
      return Child[a];
    if ((ch=Child[a]->GetChildByName(child)))
      return ch;
   }
  return NULL;
};


void
CControl::SetFOwner (CControl * control)
{
  FOwner = control;
};

CControl *
CControl::GetFOwner (void)
{
  return FOwner;
};

void
CControl::SetCanExecuteEvent (bool can)
{
  CanExecuteEvent = can;
};

bool
CControl::GetCanExecuteEvent (void)
{
  return CanExecuteEvent;
};

//operators

void *
CControl::operator
new (size_t sz)
{
/*The use of calloc instead malloc preserve Dynamic=false in controls owned */
  CControl *m = (CControl *) calloc (sz, 1);
  if (!m)
    puts ("out of memory");
  m->Dynamic = true;
  return (void *) m;
};

void 
CControl::operator
delete (void * p)
{
  CControl* pc = static_cast<CControl*>(p);
  free(pc);
};



//events

void
CControl::mouse_move (wxMouseEvent * event)
{
  if ((FOwner) && (EvMouseMove))
    (FOwner->*EvMouseMove) (this,event->GetButton(), (int) event->m_x, (int) event->m_y,(uint) event->ShiftDown());
};



void
CControl::button_press (wxMouseEvent * event)
{

//  printf("button_press %p %p\n",FOwner,EvMouseButtonPress);

  if ((FOwner) && (EvMouseButtonPress))
    (FOwner->*EvMouseButtonPress) (this,event->GetButton(), (int) event->m_x, (int) event->m_y,(uint) event->ShiftDown());

  BTimePress = event->GetTimestamp();


  if ((PopupMenu != NULL) && (event->GetButton() == 3))
    Widget->PopupMenu((wxMenu*)(PopupMenu->GetWidget()),event->m_x,event->m_y);
    
};



void
CControl::button_release (wxMouseEvent * event)
{
  BTimeRelease = event->GetTimestamp();

  if ((FOwner) && (EvMouseButtonRelease))
    (FOwner->*EvMouseButtonRelease) (this, event->GetButton(), (int) event->m_x, (int) event->m_y, event->ShiftDown());


  if ((BTimeRelease - BTimeClick) < DOUBLECLICKTIME)
    {
      if ((FOwner) && (EvMouseButtonDoubleClick))
	{
	  (FOwner->*EvMouseButtonDoubleClick) (this, event->GetButton(), (int) event->m_x, (int) event->m_y, event->ShiftDown());
	};
    }
  else
    {
      if ((FOwner) && (EvMouseButtonClick))
	{
	  (FOwner->*EvMouseButtonClick) (this, event->GetButton(), (int) event->m_x, (int) event->m_y, event->ShiftDown());
	}
      BTimeClick = BTimePress;
    };

};



void
CControl::key_press (wxKeyEvent * event)
{
  if ((FOwner) && (EvKeyboardPress))
    (FOwner->*EvKeyboardPress) (this, event->GetKeyCode(), event->GetRawKeyCode(), event->GetRawKeyFlags());
};



void
CControl::key_release (wxKeyEvent * event)
{
  if ((FOwner) && (EvKeyboardRelease))
    (FOwner->*EvKeyboardRelease) (this, event->GetKeyCode(),event->GetRawKeyCode(), event->GetRawKeyFlags());
};



void
CControl::focus_in (wxMouseEvent * event)
{
  if ((FOwner) && (EvOnFocusIn))
    (FOwner->*EvOnFocusIn) (this);
};



void
CControl::focus_out (wxMouseEvent * event)
{
  if ((FOwner) && (EvOnFocusOut))
    (FOwner->*EvOnFocusOut) (this);
};



void
CControl::on_draw (wxPaintEvent * event)
{
  if ((FOwner) && (EvOnDraw))
    (FOwner->*EvOnDraw) (this);
};


