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

#include"../include/cimage.h"
#include"../include/cmessage.h"



// CImage_____________________________________________________________

CImage::CImage (void)
{
  CanFocus = false;
  CanExecuteEvent = false;
  FileName = wxT("");
  Data = NULL;
  SetX (10);
  SetY (10);
  SetWidth (100);
  SetHeight (100);
  SetClass (wxT("CImage"));
  SetTransparent (false);
  //Image=NULL;
};

CImage::~CImage (void)
{
};

int
CImage::Create (CControl * control)
{
	

  if (Data != NULL)
  {
      Widget = new wxStaticBitmap(control->GetWidget (),GetWid(),wxBitmap(wxImage(Data).Rescale(wxSize(GetWidth(),GetHeight()).GetWidth(),wxSize(GetWidth(),GetHeight()).GetHeight())),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,GetName());
  }
  else if (GetImgFileName().size() > 0)
  {
      Widget = new wxStaticBitmap(control->GetWidget (),GetWid(),wxBitmap(wxImage(FileName).Rescale(wxSize(GetWidth(),GetHeight()).GetWidth(),wxSize(GetWidth(),GetHeight()).GetHeight())),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,GetName());
  }else
  {
      Widget = new wxStaticBitmap(control->GetWidget (),GetWid(),wxBitmap(wxImage(5,5,true).Rescale(wxSize(GetWidth(),GetHeight()).GetWidth(),wxSize(GetWidth(),GetHeight()).GetHeight())),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,GetName());
  }


  return CControl::Create (control);
};

bool CImage::GetTransparent (void)
{
  return Transparent;
};

void
CImage::SetTransparent (bool transparent)
{
  Transparent = transparent;
};

lxStringList
CImage::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Transparent"), wxT("bool"), itoa (GetTransparent ())));
  Context.AddLine (xml_out (wxT("ImgFileName"), wxT("File"), GetImgFileName ()));
  return Context;
};

void
CImage::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Transparent")) == 0)
	SetTransparent (atoi (value));
      if (name.compare (wxT("ImgFileName")) == 0)
	{
	  if (value.size () > 0)
	    SetImgFileName (value);
	  else
	    SetImgFileName (wxT(""));
	};
    };
};

lxString CImage::GetImgFileName (void)
{
  return FileName;
};


bool
CImage::SetImgFileName (lxString filename)
{
  FileName = filename;
  if ((Widget != NULL)&&(FileName.size() > 0))
    ((wxStaticBitmap*)Widget)->SetBitmap(wxBitmap(wxImage(FileName).Rescale(wxSize(GetWidth(),GetHeight()).GetWidth(),wxSize(GetWidth(),GetHeight()).GetHeight())));
  return false;
};


bool CImage::SetImgData (const char **data)
{
  Data = data;

   if ((Widget != NULL)&&(Data != NULL))
    ((wxStaticBitmap*)Widget)->SetBitmap(wxBitmap(wxImage(Data).Rescale(wxSize(GetWidth(),GetHeight()).GetWidth(),wxSize(GetWidth(),GetHeight()).GetHeight())));
 
 return false;
};

void
CImage::WriteImgToFile (lxString filename)
{
 /*FIX*/
 printf("CImage::WriteImgToFile  Not implemented yet!\n");
/*
  if (Widget != NULL)
    {
      gdk_pixbuf_save (gtk_image_get_pixbuf (GTK_IMAGE (Image)), filename.c_str (), "png", NULL, NULL);
    };
*/    
};
