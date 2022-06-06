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
#include"../include/ccheckbox.h"

// CCheckBox___________________________________________________________

CCheckBox::CCheckBox (void)
{
  Text = wxT("checkbox");
  SetX (10);
  SetY (10);
  SetWidth (95);
  SetHeight (25);
  SetCheck (false);
  SetClass (wxT("CCheckBox"));

  EvOnCheckBox= NULL;
};

CCheckBox::~CCheckBox (void)
{
};

int
CCheckBox::Create (CControl * control)
{

   Widget = new wxCheckBox(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,wxDefaultValidator,GetName());

   Widget->Bind(wxEVT_COMMAND_CHECKBOX_CLICKED,&CCheckBox::Event,this,GetWid()); 
  
  SetCheck (Check);

  return CControl::Create (control);
};


int CCheckBox::CEvent (int event)
{
if(event == wxEVT_COMMAND_CHECKBOX_CLICKED)return lxEVT_COMMAND_CHECKBOX_CLICKED;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CCheckBox::Event (wxEvent &  event)
{
   event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_COMMAND_CHECKBOX_CLICKED:
	  if ((FOwner) && (EvOnCheckBox))
	    (FOwner->*EvOnCheckBox) (this);
	  return ;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};


//   CControl::Event(event);
};



lxStringList
CCheckBox::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"), GetText ()));
  Context.AddLine (xml_out (wxT("Check"), wxT("Int"), itoa(GetCheck ())));

  Context.AddLine (xml_out (wxT("EvOnCheckBox"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CCheckBox::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("Check")) == 0)
	SetCheck (atoi(value));

      if (name.compare (wxT("EvOnCheckBox")) == 0)
	SetEv (atob (value));
    };
};

//propiedades

void
CCheckBox::SetCheck (bool check)
{
  Check = check;
  if (Widget != NULL)
	((wxCheckBox *)Widget)->SetValue(check);
};

bool CCheckBox::GetCheck (void)
{
  if (Widget != NULL)
    Check = ((wxCheckBox *)Widget)->GetValue();
  return Check;
};

void
CCheckBox::SetText (lxString t)
{
  Text = t;
  if (Widget != NULL)
    ((wxCheckBox*)Widget)->SetLabel(Text.c_str ());
}

lxString
CCheckBox::GetText (void)
{
  if (Widget != NULL)
    Text =  ((wxCheckBox*)Widget)->GetLabel();
  return Text;
}
