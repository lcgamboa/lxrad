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


#include"../include/cscroll.h"
#include"../include/capplication.h"


// CScroll___________________________________________________________

CScroll::CScroll (void)
{
  SetRange (10);
  SetPosition (3);
  SetWidth (130);
  SetHeight (15);
  SetX (10);
  SetY (10);
  SetType (st_horizontal);
  EvOnChangePosition = NULL;
  SetClass (wxT("CScroll"));
};

int
CScroll::Create (CControl * control)
{

        Widget = new wxScrollBar(control->GetWidget (),GetWid(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),Type,wxDefaultValidator,GetName());
	
	Widget->SetScrollbar(Position,1,Range,1);
    
    Win = control->GetWin ();

    Widget->Bind(wxEVT_SCROLL_CHANGED,&CScroll::Event,this,GetWid()); 

  return CControl::Create (control);
};

lxStringList CScroll::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Range"), wxT("Int"), itoa(GetRange ())));
  Context.AddLine (xml_out (wxT("Position"), wxT("Int"), itoa(GetPosition ())));
  Context.AddLine (xml_out (wxT("Type"), wxT("Int"), itoa(GetType ())));
  Context.AddLine (xml_out (wxT("EvOnChangePosition"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CScroll::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Range")) == 0)
	SetRange (atoi (value));
      if (name.compare (wxT("Position")) == 0)
	SetPosition (atoi (value));
      if (name.compare (wxT("Type")) == 0)
	SetType (atoi (value));
      if (name.compare (wxT("EvOnChangePosition")) == 0)
	SetEv (atob (value));
    };
};


int CScroll::CEvent (int event)
{
if(event == wxEVT_SCROLL_CHANGED)return lxEVT_SCROLL_CHANGED;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CScroll::Event (wxEvent & event)
{
   event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_SCROLL_CHANGED:
	  if ((FOwner) && (EvOnChangePosition))
	    (FOwner->*EvOnChangePosition) (this);
//            printf("Scrollbar Change!!!\n");
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};


//propiedades


void 
CScroll::SetPosition(int position)
{
  if ((position >= 0) && (position <= Range))
    {
      Position = position;
      if(Widget)
       ((wxScrollBar*)Widget)->SetScrollbar(Position,1,Range,1);
    };
};


int
CScroll::GetPosition (void)
{
      if(Widget)
       Position=((wxScrollBar*)Widget)->GetThumbPosition();
  return Position;
};

void
CScroll::SetRange (int range)
{
  if (range <= 0)
    range = 1;

  Range = range;
  	
  if(Widget)
    ((wxScrollBar*)Widget)->SetScrollbar(Position,1,Range,1);
};

int
CScroll::GetRange (void)
{
  return Range;
};


void
CScroll::SetType (int type)
{
  if (Type != type)
    {
      Type = type;
       if(Widget)
         ((wxScrollBar*)Widget)->SetWindowStyle(Type);
    }
};


int 
CScroll::GetType(void)
{
  return Type;
}




