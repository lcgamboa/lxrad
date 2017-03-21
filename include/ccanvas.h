/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2017  Luis Claudio Gamboa Lopes

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

/**
 * \file ccanvas.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CCANVAS
#define CCANVAS

#include"cobject.h"
#include"cwindow.h"

//#define wxRasterOperationMode int 
//#define wxFloodFillStyle int


/** \brief Canvas Control.
 *
 * Generic Canvas Class.
 */
class CCanvas:public CObject 
{
private:
  uint LWidth;
  CControl *DControl;
  wxWindow *Drawable;
  wxColor FgColor, BgColor;
  wxClientDC* WDC;	///<Window Draw Context
  wxMemoryDC* DC;	///<Memory Draw Context
  wxBitmap * Bitmap;
  wxPen  *Pen;		///<Pen
  wxBrush *Brush;	///<Brush
  wxFont Font;
  int Width;
  int Height;
  int DirectDraw;
public:
    CCanvas (void);
   ~CCanvas (void);
  int Create (CControl * dcontrol,int directdraw);
  void Init(void);
  void Init(double sx,double sy);
  void End(void);
  wxClientDC* GetDC (void);
  wxClientDC* GetWDC (void);
  wxBitmap * GetBitmap(void);
  wxWindow * GetDrawable(void);
  void SetBitmap(wxBitmap * bitmap,double xs, double ys);
  void SetFunction (wxRasterOperationMode   function);
  void SetColor (wxColor color);
  void SetColor (String color);
  void SetColor (uint r, uint g, uint b);
  void SetFgColor (wxColor color);
  void SetFgColor (String color);
  void SetFgColor (uint r, uint g, uint b);
  void SetFont (wxFont font);
  wxColor GetFgColor (void);
 /**
  * Set Background Color by wxColor.
  *
  * \param color.
  * \return void.
  */
  void SetBgColor (wxColor color);
 /**
  * Set Background Color by name.
  *
  * \param  color name.
  * \return void.
  */
  void SetBgColor (String color);
 /**
  * Set Background Color by rgb.
  *
  * \param r Red color.
  * \param g Green color.
  * \param b Blue color.
  * \return void.
  */
  void SetBgColor (uint r, uint g, uint b);
 /**
  * Get Background Color.
  *
  * \return wxColor.
  */
  wxColor GetBgColor (void);
  void SetLineWidth (uint lwidth);
  uint GetLineWidth (void);
  void Point (int x, int y);
  void Points (wxPoint * points, int npoints);
  void Line (int x1_, int y1_, int x2_, int y2_);
  void Lines (wxPoint * points, int npoints);
  void Spline (wxPoint * points, int npoints);
  //void Segments (wxSegment * segs, int nsegs);
  void Rectangle (bool filled, int x, int y, int width, int height);
  void Arc (bool filled, int x, int y, int x1, int y1, int x2, int y2);
  void Circle (bool filled, int x, int y, int radius);
  void Text (String str, int x, int y);
  void RotatedText (String str, int x, int y, int angle);
  void Polygon (bool filled, wxPoint * points, int npoints);
  void Ellipse(bool filled,int x, int y, int width, int height);
  void EllipticArc(bool filled,int x, int y, int width, int height, double start, double end);
  void PutBitmap(wxBitmap * bitmap,int x, int y);
  
  void FloodFill(int x, int y,wxColor color, wxFloodFillStyle style);
//events  
};
#endif
