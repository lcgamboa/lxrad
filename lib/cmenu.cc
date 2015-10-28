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


#include"../include/cmenu.h"
#include"../include/capplication.h"

//CMenu-----------------------------------------------------------

CMenu::CMenu (void)
{
  CanVisible = 0;
  CanFocus = false;
  SetClass (wxT("CMenu"));
  MenuItems = wxT("");
  CanExecuteEvent = false;
};


int
CMenu::Create (CControl * control)
{
  Widget = new wxMenuBar(); 

  SetOwner (control);
  Win = control->GetWin ();

  if (!Enable)
    {
      Enable = true;
      SetEnable (false);
    };

  CControl::Create (control);

  ((wxFrame*)((CWindow* )control)->GetWWidget())->SetMenuBar((wxMenuBar*)Widget);

  
  return 0;
};

CStringList CMenu::GetContext (void)
{
  //CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("MenuItems"), wxT("MenuItems"), GetMenuItems ()));

  for (uint i = 0; i < Context.GetLinesCount (); i++)
    {
      if (Context.GetLine (i).find (wxT("PoupMenu")) == 0)
	Context.DelLine (i);
    };

  return Context;
};

void
CMenu::SetContext (CStringList context)
{
  String name, type, value;

//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);

      if (name.compare (wxT("MenuItems")) == 0)
	SetMenuItems (value);
    };
};

void
CMenu::SetMenuItems (String menuitems)
{
  MenuItems = menuitems;
};

String CMenu::GetMenuItems (void)
{
  return MenuItems;
};

void CMenu::Destroy (void)
{
  Widget=NULL; 
  CControl::Destroy();	
  return;
};
