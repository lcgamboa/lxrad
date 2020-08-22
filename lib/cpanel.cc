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


#include"../include/capplication.h"

#include"../include/cpanel.h"

// CPanel___________________________________________________________

CPanel::CPanel (void)
{
  Text = wxT("Panel");
  SetX (10);
  SetY (10);
  SetWidth (65);
  SetHeight (25);
  SetClass (wxT("CPanel"));
};

CPanel::~CPanel (void)
{
};

int
CPanel::Create (CControl * control)
{
  Win = control->GetWin ();

  Widget = new wxPanel(control->GetWidget (),GetWid(),wxDefaultPosition,wxDefaultSize,wxTAB_TRAVERSAL,GetName());

  return CControl::Create (control);
};


lxStringList
CPanel::GetContext (void)
{
  CControl::GetContext ();
  return Context;
};

void
CPanel::SetContext (lxStringList context)
{
  lxString name, type, value;
  CControl::SetContext (context);
/*
 for (uint i = 0; i < context.GetLinesCount (); i++)
    {
    };
*/    
};

//propiedades

