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
 * \file cspin.h
 * \author Luis Claudio Gamboa Lopes
 * \date 07-10-2016
 */

#ifndef CSPIN
#define CSPIN

#include"ccontrol.h"
#include"cwindow.h"

/** \brief SPIN Control.
 *
 * Generic Spin Control Class.
 */

class CSpin:public CControl
{
protected:
  int Value;		///<Text		
  int Min;
  int Max;
  int CEvent (int event);
public:
    CSpin (void);
   ~CSpin (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void Event (wxEvent & event);
  //propiedades
  void SetValue(int v);
  int GetValue (void);
  void SetMin(int v);
  int GetMin (void);
  void SetMax(int v);
  int GetMax (void);
  //eventos
  void (CControl::*EvOnChangeSpin) (CControl * control);
};

#endif
