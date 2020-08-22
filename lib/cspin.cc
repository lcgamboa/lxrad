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

#include"../include/cspin.h"
#include <wx/spinctrl.h>

// CSpin_____________________________________________________________

CSpin::CSpin (void)
{
  SetX (10);
  SetY (10);
  SetWidth (80);
  SetHeight (26);
  SetMin(0);
  SetMax(100);
  SetValue(0);
  SetClass (wxT("CSpin"));
  EvOnChangeSpin= NULL;
};


CSpin::~CSpin (void)
{
};

int
CSpin::Create (CControl * control)
{

   Widget = new wxSpinCtrl (control->GetWidget (), GetWid(), wxEmptyString , wxPoint(GetX(),GetY()), wxSize(GetWidth(),GetHeight()), wxSP_ARROW_KEYS, Min, Max, Value, GetName());

   Widget->Bind(wxEVT_SPINCTRL,&CSpin::Event,this,GetWid()); 
   
   return CControl::Create (control);
};


lxStringList
CSpin::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Value"), wxT("int"), itoa(GetValue ())));
  Context.AddLine (xml_out (wxT("Min"), wxT("int"), itoa(GetMin ())));
  Context.AddLine (xml_out (wxT("Max"), wxT("int"), itoa(GetMax ())));
  Context.AddLine (xml_out (wxT("EvOnChangeSpin"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CSpin::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Value")) == 0)
	SetValue (atoi(value));
      if (name.compare (wxT("Min")) == 0)
	SetMin (atoi(value));
      if (name.compare (wxT("Max")) == 0)
	SetMax (atoi(value));
      if (name.compare (wxT("EvOnChangeSpin")) == 0)
	SetEv (atob (value));
    };
};

int CSpin::CEvent (int event)
{
if(event == wxEVT_SPINCTRL)return lxEVT_SPINCTRL;

return CControl::CEvent(event);
}

void
CSpin::Event (wxEvent & event)
{
   event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_SPINCTRL:
	  if ((FOwner) && (EvOnChangeSpin))
	    (FOwner->*EvOnChangeSpin) (this);
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};


//propriedades

void
CSpin::SetValue(int v)
{
  Value = v;
  if (Widget != NULL)
    ((wxSpinCtrl*)Widget)->SetValue(Value);
};

int
CSpin::GetValue (void)
{
  if (Widget != NULL)
    Value =  ((wxSpinCtrl*)Widget)->GetValue();
  return Value;
};


void
CSpin::SetMin(int v)
{
  Min = v;
  if (Widget != NULL)
    ((wxSpinCtrl*)Widget)->SetRange(Min,Max);
};

int
CSpin::GetMin (void)
{
  if (Widget != NULL)
    Min =  ((wxSpinCtrl*)Widget)->GetMin();
  return Min;
};

void
CSpin::SetMax(int v)
{
  Max = v;
  if (Widget != NULL)
    ((wxSpinCtrl*)Widget)->SetRange(Min,Max);
};

int
CSpin::GetMax (void)
{
  if (Widget != NULL)
    Max =  ((wxSpinCtrl*)Widget)->GetMax();
  return Max;
};

