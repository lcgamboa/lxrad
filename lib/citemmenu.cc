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


#include"../include/citemmenu.h"
#include"../include/cpmenu.h"
#include"../include/cmenu.h"
#include"../include/capplication.h"


//CItemMenu------------------------------------------------------

CItemMenu::CItemMenu (void)
{
  CanVisible = false;
  CanExecuteEvent = true;
  Text = wxT(" ");
  SetClass (wxT("CItemMenu"));
  SubMenu = NULL;
  EvMenuActive = NULL;
  doenable=1;
};

int
CItemMenu::Create (CControl * control)
{
   int ret;
   Owner=control;

   Win = control->GetWin ();

   Widget =(wxWindow*) new wxMenuItem((wxMenu*)control->GetWidget (),GetWid(),Text,wxEmptyString,wxITEM_NORMAL);
  
  ((wxMenu*) control->GetWidget())->Append ((wxMenuItem *) Widget);


   //Win->GetWWidget()->Connect(GetWid(),wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&CApplication::events_callback);

   Win->GetWWidget()->Bind(wxEVT_COMMAND_MENU_SELECTED,&CItemMenu::Event,this,GetWid()); 


  CanExecuteEvent = false;
  ret= CControl::Create (control);
  CanExecuteEvent = true;
  SetEnable(Enable);
  return ret;
};

int CItemMenu::CEvent (int event)
{
if(event == wxEVT_COMMAND_MENU_SELECTED)return lxEVT_COMMAND_MENU_SELECTED;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CItemMenu::Event (wxEvent & event)
{
  event.Skip();
/*
#ifdef __WXGTK__   
  if ((Owner->GetWidget() == (widget-1))&&(event->GetId() == GetWid()))
#else
  if (event->GetId() == GetWid())
#endif
*/
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_COMMAND_MENU_SELECTED:
	if ((FOwner) && (EvMenuActive))
	    (FOwner->*EvMenuActive) (this);
	  return ;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};


void
CItemMenu::SetSubMenu (CPMenu * submenu)
{
  SubMenu = submenu;
//  if ((SubMenu != NULL) && (Widget != NULL))
//    gtk_menu_item_set_submenu (GTK_MENU_ITEM (Widget), submenu->GetWidget ());
};

void
CItemMenu::SetName (const String name)
{
  Name = name;
};

CStringList CItemMenu::GetContext (void)
{
  CObject::GetContext ();

  Context.AddLine (xml_out (wxT("Text"), wxT("String"), GetText ()));
  Context.AddLine (xml_out (wxT("Enable"), wxT("bool"), itoa (GetEnable ())));

  if (SubMenu)
    Context.AddLine (xml_out (wxT("SubMenu"), wxT("SubMenu"), SubMenu->GetName ()));
  else
    Context.AddLine (xml_out (wxT("SubMenu"), wxT("SubMenu"), wxT("NULL")));

  Context.AddLine (xml_out (wxT("EvMenuActive"), wxT("Event"), btoa (GetEv (true))));
    
/*
  Context.AddLine (xml_out ("SigActivate", "Signal", btoa (GetEv (true))));
  Context.AddLine (xml_out ("SigActivateItem", "Signal", btoa (GetEv ())));
*/
  /*
     for (uint i = 0; i < Context.GetLinesCount(); i++)
     {
     if(Context.GetLine(i).find("PoupMenu") == 0)
     Context.DelLine(i);
     };
   */
  return Context;
};

void
CItemMenu::SetContext (CStringList context)
{
  String name, type, value;

  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("SubMenu")) == 0)
	if (value.compare (wxT("NULL")) != 0)
	  SetSubMenu (dynamic_cast < CPMenu * >(Win->GetChildByName (value)));
      
      if (name.compare (wxT("EvMenuActive")) == 0)
	SetEv (atob (value),true);
      
      if (name.compare (wxT("Enable")) == 0)
	SetEnable (atoi (value));
/*  
     if (name.compare ("SigActivate") == 0)
	SetSig (atob (value), true);
      if (name.compare ("SigActivateItem") == 0)
	SetSig (atob (value));
*/	
    };
};

void
CItemMenu::SetText (String t)
{
  Text = t;
//  if (Label != NULL)
//    gtk_label_set_text (GTK_LABEL (Label), LocaleToUtf8 (Text).c_str ());
};

String
CItemMenu::GetText (void)
{
//  if (Label != NULL)
//    Text = LocaleFromUtf8 (gtk_label_get_text (GTK_LABEL (Label)));


  return Text;
};

void CItemMenu::Destroy (void)
{
  if((((wxMenu*) Owner->GetWidget()) != NULL)&&(Widget!=NULL))
    ((wxMenu*) Owner->GetWidget())->Destroy ((wxMenuItem *) Widget);
  Widget=NULL; 
  CControl::Destroy();	
  return;
};

	
void
CItemMenu::SetEnable (bool enable)
{
  Enable = enable;

  if ((Widget != NULL)&& (doenable == true))
  {
    ((wxMenuItem *) Widget)->Enable(enable);
  }
};

void
CItemMenu::SetDoEnable (bool denable)
{
  doenable = denable;
};
