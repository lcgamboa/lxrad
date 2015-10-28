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
 * \file cscroll.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CSCROLL
#define CSCROLL

#include"ccontrol.h"
#include"cwindow.h"

#define st_horizontal  wxSB_HORIZONTAL 
#define st_vertical    wxSB_VERTICAL


/** \brief Scroll Control.
 *
 * Generic Scroll Control Class.
 */


class CScroll:public CControl
{
protected:
  int Position;
  int Range;
  int Type;
  int CEvent (int event);
public:
    CScroll (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void Event (wxEvent & event);
  //propiedades
  void SetPosition (int position);
  int GetPosition (void);
  void SetRange (int range);
  int GetRange (void);
  void SetType (int type);
  int GetType (void);
  //eventos
  void (CControl::*EvOnChangePosition) (CControl * control);
};

#endif
