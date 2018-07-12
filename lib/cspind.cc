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

#include"../include/cspind.h"
#include <wx/spinctrl.h>

// CSpind_____________________________________________________________

CSpind::CSpind (void)
{
  SetX (10);
  SetY (10);
  SetWidth (80);
  SetHeight (26);
  SetMin(0.0);
  SetMax(100.0);
  SetInc(0.5);
  SetValue(0.0);
  SetDigits(1);
  EvOnChangeSpinDouble= NULL;
  SetClass (wxT("CSpind"));
};


CSpind::~CSpind (void)
{
};

int
CSpind::Create (CControl * control)
{

   Widget = new wxSpinCtrlDouble (control->GetWidget (), GetWid(), wxEmptyString , wxPoint(GetX(),GetY()), wxSize(GetWidth(),GetHeight()), wxSP_ARROW_KEYS, Min, Max, Value, Inc, GetName());

   SetDigits(Digits);
 
   Widget->Bind(wxEVT_SPINCTRLDOUBLE,&CSpind::Event,this,GetWid()); 

return CControl::Create (control);
};


CStringList
CSpind::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Value"), wxT("double"), ftoa(GetValue ())));
  Context.AddLine (xml_out (wxT("Min"), wxT("double"), ftoa(GetMin ())));
  Context.AddLine (xml_out (wxT("Max"), wxT("double"), ftoa(GetMax ())));
  Context.AddLine (xml_out (wxT("Inc"), wxT("double"), ftoa(GetInc ())));
  Context.AddLine (xml_out (wxT("Digits"), wxT("int"), itoa(GetDigits ())));
  Context.AddLine (xml_out (wxT("EvOnChangeSpinDouble"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CSpind::SetContext (CStringList context)
{
  String name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Value")) == 0)
	SetValue (atof(value));
      if (name.compare (wxT("Min")) == 0)
	SetMin (atof(value));
      if (name.compare (wxT("Max")) == 0)
	SetMax (atof(value));
      if (name.compare (wxT("Inc")) == 0)
	SetInc (atof(value));
      if (name.compare (wxT("Digits")) == 0)
	SetDigits (atoi(value));
      if (name.compare (wxT("EvOnChangeSpinDouble")) == 0)
	SetEv (atob (value));
    };
};


int CSpind::CEvent (int event)
{
if(event == wxEVT_SPINCTRLDOUBLE)return lxEVT_SPINCTRLDOUBLE;

return CControl::CEvent(event);
}

void
CSpind::Event (wxEvent & event)
{
   event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_SPINCTRLDOUBLE:
	  if ((FOwner) && (EvOnChangeSpinDouble))
	    (FOwner->*EvOnChangeSpinDouble) (this);
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};



//propriedades

void
CSpind::SetValue(double v)
{
  Value = v;
  if (Widget != NULL)
    ((wxSpinCtrlDouble*)Widget)->SetValue(Value);
};

double
CSpind::GetValue (void)
{
  if (Widget != NULL)
    Value =  ((wxSpinCtrlDouble*)Widget)->GetValue();
  return Value;
};


void
CSpind::SetMin(double v)
{
  Min = v;
  if (Widget != NULL)
    ((wxSpinCtrlDouble*)Widget)->SetRange(Min,Max);
};

double
CSpind::GetMin (void)
{
  if (Widget != NULL)
    Min =  ((wxSpinCtrlDouble*)Widget)->GetMin();
  return Min;
};

void
CSpind::SetMax(double v)
{
  Max = v;
  if (Widget != NULL)
    ((wxSpinCtrlDouble*)Widget)->SetRange(Min,Max);
};

double
CSpind::GetMax (void)
{
  if (Widget != NULL)
    Max =  ((wxSpinCtrlDouble*)Widget)->GetMax();
  return Max;
};

void
CSpind::SetInc(double v)
{
  Inc = v;
  if (Widget != NULL)
    ((wxSpinCtrlDouble*)Widget)->SetIncrement(Inc);
};

double
CSpind::GetInc (void)
{
  if (Widget != NULL)
    Inc =  ((wxSpinCtrlDouble*)Widget)->GetIncrement();
  return Inc;
};

void
CSpind::SetDigits(int v)
{
  Digits = v;
  if (Widget != NULL)
    ((wxSpinCtrlDouble*)Widget)->SetDigits(Digits);
};

int
CSpind::GetDigits (void)
{
  if (Widget != NULL)
    Digits =  ((wxSpinCtrlDouble*)Widget)->GetDigits();
  return Digits;
};
