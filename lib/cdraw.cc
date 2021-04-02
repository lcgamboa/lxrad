/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2021  Luis Claudio Gamboa Lopes

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

#include"../include/cdraw.h"
#include"../include/cmessage.h"
#include"../include/lxutils.h"

// CDraw_____________________________________________________________

CDraw::CDraw(void)
{
 FileName = wxT ("");
 Data = NULL;
 LWidth = 0;
 SetX (10);
 SetY (10);
 SetWidth (100);
 SetHeight (100);
 SetClass (wxT ("CDraw"));
 SetTransparent (false);
 Sx = 1;
 Sy = 1;
}

CDraw::~CDraw(void) { }

int
CDraw::Create(CControl * control)
{

 Win = control->GetWin ();

 Widget = new wxPanel (control->GetWidget (), GetWid (), wxPoint (GetX (), GetY ()), wxSize (GetWidth (), GetHeight ()), wxTAB_TRAVERSAL, GetName ());

 Widget->SetBackgroundColour (wxSystemSettings::GetColour (wxSYS_COLOUR_WINDOW));

 Canvas.Create (Widget, 0);

 Canvas.Init ();
 Canvas.SetBgColor (255, 255, 255);
 Canvas.SetFgColor (0, 0, 0);
 Canvas.SetLineWidth (LWidth);
 Canvas.Rectangle (true, 0, 0, Width, Height);
 Canvas.End ();

 //Update ();
 if (Data != NULL)
  SetImgData (Data);

 if (FileName != wxT (""))
  SetImgFileName (FileName);


 return CControl::Create (control);
}

void
CDraw::Draw(void) {
 /*FIX*/
 // gdk_draw_pixmap(Widget->window,Widget->style->fg_gc[GTK_WIDGET_STATE (Widget)],Pixmap,0,0,0,0,Width,Height);
 /*
 GdkRectangle update_rect;

 update_rect.x = 0;
 update_rect.y = 0;
 update_rect.width = Width;
 update_rect.height = Height;
  */
 //gtk_widget_draw (Widget, &update_rect);

 }

bool
CDraw::GetTransparent(void)
{
 return Transparent;
}

void
CDraw::SetTransparent(bool transparent)
{
 Transparent = transparent;
}

lxStringList
CDraw::GetContext(void)
{
 CControl::GetContext ();
 Context.AddLine (xml_out (wxT ("Transparent"), wxT ("bool"), itoa (GetTransparent ())));
 Context.AddLine (xml_out (wxT ("ImgFileName"), wxT ("File"), GetImgFileName ()));
 return Context;
}

void
CDraw::SetContext(lxStringList context)
{
 lxString name, type, value;

 CControl::SetContext (context);
 for (uint i = 0; i < context.GetLinesCount (); i++)
  {
   xml_in (Context.GetLine (i), name, type, value);
   if (name.compare (wxT ("Transparent")) == 0)
    SetTransparent (atoi (value));
   if (name.compare (wxT ("ImgFileName")) == 0)
    {
     if (value.size () > 0)
      SetImgFileName (value);
     else
      SetImgFileName (wxT (""));
    }
  }
}

lxString
CDraw::GetImgFileName(void)
{
 return FileName;
}

bool
CDraw::SetImgFileName(lxString filename, double sx, double sy)
{
 FileName = filename;
 Sx = sx;
 Sy = sy;

 if ((Widget != NULL)&&(FileName != wxT ("")))
  {
   lxImage image(Win);
   if (image.LoadFile (FileName, 0, sx, sy))
    {
     wxBitmap bitmap (image);
     Canvas.SetBitmap (&bitmap, 1.0, 1.0);
     Update ();
    }
   return true;
  }
 else
  return false;
}

bool
CDraw::SetImgFileName(lxString filename)
{
 FileName = filename;
 Sx = 1;
 Sy = 1;

 if ((Widget != NULL)&&(FileName != wxT ("")))
  {
   wxImage image;
   if (image.LoadFile (FileName))
    {
     wxBitmap bitmap (image);
     Canvas.SetBitmap (&bitmap, 1, 1);
     Update ();
    }
   return true;
  }
 else
  return false;
}

bool
CDraw::SetImgData(const char **data)
{
 wxBitmap bitmap (data);

 Data = data;

 if (Widget != NULL)
  {
   Canvas.SetBitmap (&bitmap, Sx, Sy);
   Update ();
  }

 return false;
}

void
CDraw::WriteImgToFile(lxString filename)
{
 if (Widget != NULL)
  {
   Canvas.GetBitmapBuffer ()->SaveFile (filename, wxBITMAP_TYPE_PNG, NULL);
  }
}

//events  

void
CDraw::on_draw(wxPaintEvent * event)
{
 //  gdk_draw_drawable (Widget->window, Canvas.GetGC(), Pixmap, event->area.x, event->area.y, event->area.x, event->area.y, event->area.width, event->area.height);
 Canvas.Init ();
 Canvas.End ();
 CControl::on_draw (event);


}


