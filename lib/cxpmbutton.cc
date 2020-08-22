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
#include"../include/cxpmbutton.h"


// CXpmButton___________________________________________________________

CXpmButton::CXpmButton (void)
{
  SetX (10);
  SetY (10);
  SetWidth (65);
  SetHeight (25);
  SetClass (wxT("CXpmButton"));
  ImgFileName = wxT("");
};

CXpmButton::~CXpmButton (void)
{
};

int
CXpmButton::Create (CControl * control)
{
  Win = control->GetWin ();


  Widget = new wxButton(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,wxDefaultValidator,GetName());


  return CControl::Create (control);
};


lxStringList
CXpmButton::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"), GetText ()));
  Context.AddLine (xml_out (wxT("ImgFileName"), wxT("File"), GetImgFileName ()));
  return Context;
};

void
CXpmButton::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("ImgFileName")) == 0)
	{
	  if (value.size () > 0)
	    SetImgFileName (value);
	  else
	    SetImgFileName (wxT(""));
	};
	};
};

//propriedades

void
CXpmButton::SetImgData (const char **data)
{
  if (Widget != NULL)
    {
/*FIX*/
//      GdkPixbuf *buf = gdk_pixbuf_new_from_xpm_data (data);
//      gtk_image_set_from_pixbuf (GTK_IMAGE (Img), buf);
    };
};

void
CXpmButton::SetImgFileName (lxString imgfilename)
{
  ImgFileName = imgfilename;
/*FIX*/
//  if (Widget != NULL)
//    gtk_image_set_from_file (GTK_IMAGE (Img), ImgFileName.c_str ());
};

lxString CXpmButton::GetImgFileName (void)
{
  return ImgFileName;
};

void
CXpmButton::SetText (lxString t)
{
  Text = t;
//  if (Widget != NULL)
//    gtk_label_set_text (GTK_LABEL (Label), LocaleToUtf8 (Text).c_str ());
};

lxString
CXpmButton::GetText (void)
{
//  if (Widget != NULL)
//    Text = LocaleFromUtf8 (gtk_label_get_text (GTK_LABEL (Label)));
  return Text;
};

//events 

void
CXpmButton::key_press (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
    button_press ((wxMouseEvent*)event);
  CControl::key_press(event);
};

void
CXpmButton::key_release (wxKeyEvent * event)
{
  if((event->GetKeyCode() == WXK_RETURN)||(event->GetKeyCode() == WXK_SPACE))
    button_release ((wxMouseEvent*)event);
  CControl::key_release(event);
};
