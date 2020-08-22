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
 * \file cimage.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CIMAGE
#define CIMAGE

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Image Control.
 *
 * Generic Image Control Class.
 */


class CImage:public CControl
{
private:
  const char **Data;
  lxString FileName;
  bool Transparent;
//  GtkWidget *Image;
public:
    CImage (void);
   ~CImage (void);
  bool SetImgFileName (lxString filename);
  bool SetImgData (const char **data);
  lxString GetImgFileName (void);
  void WriteImgToFile (lxString filename);
  int Create (CControl * control);
  bool GetTransparent (void);
  void SetTransparent (bool);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
};

#endif
