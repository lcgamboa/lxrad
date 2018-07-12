/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2018  Luis Claudio Gamboa Lopes

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

#include"../include/cbutton.h"

// CButton___________________________________________________________

CButton::CButton (void)
{
  Text = wxT("Button");
  SetX (10);
  SetY (10);
  SetWidth (65);
  SetHeight (28);
  SetClass (wxT("CButton"));
};

CButton::~CButton (void)
{
};

int
CButton::Create (CControl * control)
{
  Win = control->GetWin ();
  

Widget = new wxButton(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,wxDefaultValidator,GetName());

  return CControl::Create (control);
};


CStringList
CButton::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("String"), GetText ()));

  return Context;
};

void
CButton::SetContext (CStringList context)
{
  String name, type, value;
  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
    };
};

//propiedades

void
CButton::SetText (String t)
{
  Text = t;
  if (Widget != NULL)
     Widget->SetLabel(t);
};

String
CButton::GetText (void)
{
  if (Widget != NULL)
    Text = Widget->GetLabel();
 
  return Text;
};

//events 

void
CButton::key_press (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
     button_press ((wxMouseEvent*)event);
  CControl::key_press(event);
};

void
CButton::key_release (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
     button_release ((wxMouseEvent*)event);
  CControl::key_release(event);
};
