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


#include"../include/cpmenu.h"
#include"../include/capplication.h"

//CPMenu----------------------------------------------------------

CPMenu::CPMenu (void)
{
  CanFocus = false;
  SetBorder (0);
  SetX (1);
  SetY (1);
  SetHeight (10);
  SetWidth (10);
  SetClass (wxT("CPMenu"));
  SetVisible (false);
  CanExecuteEvent = false;
  MenuItems = wxT("");
  Text=wxT("");	
  CanVisible= false;
}

int
CPMenu::Create (CControl * control)
{
  Widget =(wxWindow*) new wxMenu(); 
  SetOwner (control);
  Win = control->GetWin ();


  if (!Enable)
    {
      Enable = true;
      SetEnable (false);
    };

  CControl::Create(control);

  if(control->GetClass() == wxT("CMenu")) 
    ((wxMenuBar*) control->GetWidget())->Append ((wxMenu *) Widget,Text);
  
  return 0;
};

int CPMenu::CEvent (int event)
{
if(event == wxEVT_COMMAND_MENU_SELECTED)return lxEVT_COMMAND_MENU_SELECTED;

return CControl::CEvent(event);
}

bool
CPMenu::Event (wxWindow * widget, wxEvent * event)
{

  if ((Widget == widget)&&(event->GetId() == GetWid()))
    {
//activate event in control
      switch (CEvent(event->GetEventType()))
	{
	case lxEVT_COMMAND_MENU_SELECTED:
	if ((FOwner) && (EvMenuActive))
	    (FOwner->*EvMenuActive) (this);
	  return 1;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
      return true;
    }
  else
    {
#ifdef __WXGTK__
      widget=widget+1;//hack for gtk menuitem
#endif      
      //return CControl::Event (widget, event);
    };

  return true;
};


void
CPMenu::SetName (const lxString name)
{
  Name = name;
};


void
CPMenu::SetMenuItems (lxString menuitems)
{
  MenuItems = menuitems;
};

lxString CPMenu::GetMenuItems (void)
{
  return MenuItems;
};


lxStringList CPMenu::GetContext (void)
{
  //CControl::GetContext ();
  CObject::GetContext ();

  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"),GetText() ));
  Context.AddLine (xml_out (wxT("MenuItems"), wxT("MenuItems"), GetMenuItems ()));

  for (uint i = 0; i < Context.GetLinesCount (); i++)
    {
      if (Context.GetLine (i).find (wxT("PoupMenu")) == 0)
	Context.DelLine (i);
    };

  return Context;
};

void
CPMenu::SetContext (lxStringList context)
{
  lxString name, type, value;

//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);

      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("MenuItems")) == 0)
	SetMenuItems (value);
    };
};

/*
void
CPMenu::PopUp (GdkEventButton * event)
{
  if (Widget != NULL)
    gtk_menu_popup (GTK_MENU (Widget), NULL, NULL, NULL, NULL, event->button, event->time);
};
*/

void
CPMenu::SetText (lxString t)
{
  Text = t;
//  if (Label != NULL)
//    gtk_label_set_text (GTK_LABEL (Label), LocaleToUtf8 (Text).c_str ());
};

lxString
CPMenu::GetText (void)
{
//  if (Label != NULL)
//    Text = LocaleFromUtf8 (gtk_label_get_text (GTK_LABEL (Label)));
  return Text;
};

void CPMenu::Destroy (void)
{
  Widget=NULL; 
  CControl::Destroy();	
  return;
};
