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
 * \file cgauge.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2010
 */

#ifndef CGAUGE
#define CGAUGE

#include"ccontrol.h"
#include"cwindow.h"
/** \brief Gauge Control.
 *
 * Generic Gauge Control Class.
 */


class CGauge: public CControl
{
protected:
  int Value;
  int Range;
  int Type;
//  GtkObject *Adj;
public:
    CGauge (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  //propiedades
  void SetValue (int value);
  int GetValue (void);
  void SetRange (int range);
  int GetRange (void);
  void SetType (int type);
  int GetType (void);
  //eventos
};

#endif
