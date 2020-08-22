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
 * \file cswindow.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CSWINDOW
#define CSWINDOW

#include"cwindow.h"
#include "wx/splash.h"

/** \brief Image Control.
 *
 * Generic Splash Window Control Class.
 */

class CSWindow:public CWindow
{
protected:
  lxString ImgFileName;
  unsigned int Timeout;
public:
    CSWindow (void);
   ~CSWindow (void);
  int Create (CControl * control);
  //propiedades
  void SetImgFileName(lxString fname);
  void SetTimeout(unsigned int tout);
  //operator
  void *operator    new (size_t sz);
  void operator delete (void *p);
  //eventos
};


#endif
