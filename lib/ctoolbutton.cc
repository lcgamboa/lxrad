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
#include"../include/ctoolbutton.h"


// CToolButton___________________________________________________________

CToolButton::CToolButton (void)
{
  SetX (10);
  SetY (10);
  SetWidth (26);
  SetHeight (26);
  SetClass (wxT("CToolButton"));
  CanFocus = false;
  ImgFileName = wxT("");
  Data= NULL;
/*FIX*/
//  Img = NULL;
};

CToolButton::~CToolButton (void)
{
};

int
CToolButton::Create (CControl * control)
{
  Win = control->GetWin ();


  if (Data != NULL)
  {
	Widget = new wxBitmapButton(control->GetWidget (),GetWid(),wxBitmap(wxImage(Data)),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxBU_AUTODRAW,wxDefaultValidator,GetName());
  }
  else if (GetImgFileName().size() > 0)
  {
   
	Widget = new wxBitmapButton(control->GetWidget (),GetWid(),wxBitmap(wxImage(GetImgFileName())),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxBU_AUTODRAW,wxDefaultValidator,GetName());
  }
  else
  {
	Widget = new wxBitmapButton(control->GetWidget (),GetWid(),wxBitmap(wxImage(5,5,true)),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxBU_AUTODRAW,wxDefaultValidator,GetName());
  }


  ((wxBitmapButton*)Widget)->SetDefault();


  return CControl::Create (control);
};



CStringList
CToolButton::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("ImgFileName"), wxT("File"), GetImgFileName ()));
 return Context;
};

void
CToolButton::SetContext (CStringList context)
{
  String name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("ImgFileName")) == 0)
	{
	  if (value.size () > 0)
	    SetImgFileName (value);
	  else
	    SetImgFileName (wxT(""));
	}
  };
};

//propriedades

void
CToolButton::SetImgData (const char **data)
{
  Data = data;

  if ((Widget != NULL)&&(Data != NULL))
    {
       ((wxBitmapButton*)Widget)->SetBitmapLabel(wxBitmap(wxImage(Data)));
    };
};

void
CToolButton::SetImgFileName (String imgfilename)
{
  ImgFileName = imgfilename;
  if ((Widget != NULL) && (ImgFileName.size() > 0))
    {
       wxImage image;
       if(image.LoadFile(GetImgFileName()))
       ((wxBitmapButton*)Widget)->SetBitmapLabel(wxBitmap(image));
    };
};

String CToolButton::GetImgFileName (void)
{
  return ImgFileName;
};

//events 

void
CToolButton::key_press (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
     button_press ((wxMouseEvent*)event);
  CControl::key_press(event);
};

void
CToolButton::key_release (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
     button_release ((wxMouseEvent*)event);
  CControl::key_release(event);
};
