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


#include"../include/cgauge.h"


// CGauge___________________________________________________________

CGauge::CGauge (void)
{
  SetRange (10);
  SetValue (3);
  SetWidth (20);
  SetHeight (20);
  SetX (10);
  SetY (10);
  SetType (wxGA_HORIZONTAL);
  SetClass (wxT("CGauge"));
};

int
CGauge::Create (CControl * control)
{

        Widget = new wxGauge(control->GetWidget (),GetWid(),Range,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),Type,wxDefaultValidator,GetName());
    
       ((wxGauge*)Widget)->SetValue(Value);

        return CControl::Create (control);
};

CStringList CGauge::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Range"), wxT("Int"), itoa(GetRange ())));
  Context.AddLine (xml_out (wxT("Value"), wxT("Int"), itoa(GetValue ())));
  Context.AddLine (xml_out (wxT("Type"), wxT("Int"), itoa(GetType ())));
  return Context;
};

void
CGauge::SetContext (CStringList context)
{
  String name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Range")) == 0)
	SetRange (atoi (value));
      if (name.compare (wxT("Value")) == 0)
	SetValue (atoi (value));
      if (name.compare (wxT("Type")) == 0)
	SetType (atoi (value));
    };
};

//propiedades


void 
CGauge::SetValue(int value)
{
  if ((value >= 0) && (value <= Range))
    {
       Value = value;
    if(Widget)
       ((wxGauge*)Widget)->SetValue(Value);
    }
};


int
CGauge::GetValue (void)
{
  return Value;
};

void
CGauge::SetRange (int range)
{
  if (range <= 0)
    range = 1;

  Range = range;
  	
  if(Widget)
    ((wxGauge*)Widget)->SetRange(Range);
};

int
CGauge::GetRange (void)
{
  return Range;
};


void
CGauge::SetType (int type)
{
  if (Type != type)
    {
      Type = type;
       if(Widget)
         ((wxGauge*)Widget)->SetWindowStyle(Type);
    }
};


int 
CGauge::GetType(void)
{
  return Type;
}




