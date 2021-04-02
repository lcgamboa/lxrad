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

/**
 * \file ccanvas.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CCANVAS
#define CCANVAS

#include"cobject.h"
#include"cwindow.h"


/** \brief Canvas Control.
 *
 * Generic Canvas Class.
 */
class CCanvas:public CObject 
{
private:
  uint LWidth;
  wxWindow *Drawable;
  wxBitmap *Bitmap;  
  wxColor FgColor, BgColor;
  wxClientDC* WDC;	 ///<Window Draw Context
  wxDC* DC;	         ///<Memory Draw Context
  wxBitmap * BitmapBuffer;
  wxPen  *Pen;		 ///<Pen
  wxBrush *Brush;	 ///<Brush
  wxFont Font;
  int Width;
  int Height;
  int DirectDraw;
  int orientation;
  void Rotate(float *x, float *y);
  double Scalex;
  double Scaley;
public:
    CCanvas (void);
   ~CCanvas (void);
  int Create (wxWindow * drawable,int directdraw);
  int Create (wxWindow *drawable, wxBitmap * bitmap);
  void Destroy(void);
  void Init(void);
  void Init(double sx, double sy, int angle=0);
  void ChangeScale(double sx,double sy);
  void End(void);
  wxDC* GetDC (void);
  wxClientDC* GetWDC (void);
  wxBitmap * GetBitmapBuffer(void);
  wxWindow * GetDrawable(void);
  void SetBitmap(wxBitmap * bitmap,double xs, double ys);
  void SetFunction (wxRasterOperationMode   function);
  void SetColor (wxColor color);
  void SetColor (lxString color);
  void SetColor (uint r, uint g, uint b);
  void SetFgColor (wxColor color);
  void SetFgColor (lxString color);
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
  void SetBgColor (lxString color);
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
  void Point (float x, float y);
  void Points (wxPoint * points, int npoints);
  void Line (float x1_, float y1_, float x2_, float y2_);
  void Lines (wxPoint * points, int npoints);
  void Spline (wxPoint * points, int npoints);
  //void Segments (wxSegment * segs, int nsegs);
  void Rectangle (bool filled, float x, float y, float width, float height);
  void Arc (bool filled, int x, int y, int x1, int y1, int x2, int y2);
  void Circle (bool filled, float x, float y, float radius);
  void Text (lxString str, float x, float y);
  void RotatedText (lxString str, float x, float y, float angle);
  void TextOnRect (lxString str, wxRect, unsigned int align );
  void Polygon (bool filled, wxPoint * points, int npoints);
  void Ellipse(bool filled,int x, int y, int width, int height);
  void EllipticArc(bool filled,int x, int y, int width, int height, double start, double end);
  void PutBitmap(wxBitmap * bitmap,float x, float y);
  
  void FloodFill(int x, int y,wxColor color, wxFloodFillStyle style);
//events  
};
#endif
