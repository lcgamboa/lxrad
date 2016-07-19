/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2016  Luis Claudio Gamboa Lopes

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


//#include"../include/capplication.h"
#include"../include/ctogglebutton.h"
#include <wx/tglbtn.h>

// CToggleButton___________________________________________________________

CToggleButton::CToggleButton (void)
{
  Text = wxT("tlgBtn");
  SetX (10);
  SetY (10);
  SetWidth (65);
  SetHeight (28);
  SetCheck (false);
  SetClass (wxT("CToggleButton"));

  EvOnToggleButton= NULL;
};

CToggleButton::~CToggleButton (void)
{
};

int
CToggleButton::Create (CControl * control)
{

   Widget = new wxToggleButton(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,wxDefaultValidator,GetName());

   Widget->Bind(wxEVT_TOGGLEBUTTON,&CToggleButton::Event,this,GetWid()); 
  
  SetCheck (Check);

  return CControl::Create (control);
};


int CToggleButton::CEvent (int event)
{
if(event == wxEVT_TOGGLEBUTTON)return lxEVT_TOGGLEBUTTON;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CToggleButton::Event (wxEvent &  event)
{
   event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_TOGGLEBUTTON:
	  if ((FOwner) && (EvOnToggleButton))
	    (FOwner->*EvOnToggleButton) (this);
	  return ;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};


//   CControl::Event(event);
};



CStringList
CToggleButton::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("String"), GetText ()));
  Context.AddLine (xml_out (wxT("Check"), wxT("Int"), itoa(GetCheck ())));

  Context.AddLine (xml_out (wxT("EvOnToggleButton"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CToggleButton::SetContext (CStringList context)
{
  String name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("Check")) == 0)
	SetCheck (atoi(value));

      if (name.compare (wxT("EvOnToggleButton")) == 0)
	SetEv (atob (value));
    };
};

//propiedades

void
CToggleButton::SetCheck (bool check)
{
  Check = check;
  if (Widget != NULL)
	((wxToggleButton *)Widget)->SetValue(check);
};

bool CToggleButton::GetCheck (void)
{
  if (Widget != NULL)
    Check = ((wxToggleButton *)Widget)->GetValue();
  return Check;
};

void
CToggleButton::SetText (String t)
{
  Text = t;
//  if (Label != NULL)
//    gtk_label_set_text (GTK_LABEL (Label), Text.c_str ());
};

String
CToggleButton::GetText (void)
{
//  if (Label != NULL)
//    Text = gtk_label_get_text (GTK_LABEL (Label));
  return Text;
};
