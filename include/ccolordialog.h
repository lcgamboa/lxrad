/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2016  Luis Claudio Gamboa Lopes

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
 * \file ccolordialog.h
 * \author Luis Claudio Gamboa Lopes
 * \date 07-17-2016
 */

#ifndef CCOLORDIALOG
#define CCOLORDIALOG

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Color Dialog Control.
 *
 * Generic Color Dialog Control Class.
 */

class CColorDialog:public CControl
{
private:
  wxColor Color;
public:
  CColorDialog (void);
   ~CColorDialog (void);
  int Create (CControl * control);
  void Run (void);
  //propriedades
  lxString GetColorName (void);
  void SetColorName (lxString cname);
  wxColor GetColor (void);
  void SetColor (wxColor c);
  void SetColor (uint r, uint g, uint b);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //events
  void (CControl::*EvOnClose) (int retId);  
};

#endif
