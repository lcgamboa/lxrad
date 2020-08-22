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

/**
 * \file cxpmbutton.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CXPMBUTTON
#define CXPMBUTTON

#include"ccontrol.h"

/** \brief Image Control.
 *
 * Generic XpmButton Control Class.
 */

class CXpmButton:public CControl
{
private:
  lxString ImgFileName;
  lxString Text;
public:
    CXpmButton (void);
   ~CXpmButton (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //propiedades
  void SetImgData (const char **data);
  void SetImgFileName (lxString imgfilename);
  lxString GetImgFileName (void);
  void SetText (lxString t);
  lxString GetText (void);
  //events
  void key_press (wxKeyEvent* event);
  void key_release (wxKeyEvent* event);
};

#endif
