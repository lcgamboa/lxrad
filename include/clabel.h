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
 * \file clabel.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CLABEL
#define CLABEL

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Image Control.
 *
 * Generic Label Class.
 */


class CLabel:public CControl
{
protected:
//  GtkWidget* Label;
  lxString Text;
  CAlign Align;
public:
    CLabel (void);
   ~CLabel (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
//propierties  
  void SetWidth (uint w);
  void SetText (lxString text);
  lxString GetText (void);
  void SetAlign (CAlign align);
  CAlign GetAlign (void);
  void SetColorName (const lxString name);
  void SetColor (unsigned r, unsigned g, unsigned b);
  void SetColor (wxColor color);
};

#endif
