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
 * \file cpwindow.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CPWINDOW
#define CPWINDOW

#include"cwindow.h"

/** \brief Image Control.
 *
 * Generic Panel Window Control Class.
 */

class CPWindow:public CWindow
{
protected:
  wxWindow *Window_;
public:
    CPWindow (void);
   ~CPWindow (void);
  int Create (CControl * control);
  void Destroy (void);
//propiedades
  wxWindow* GetWWidget (void);
  //operator
  void *operator    new (size_t sz);
  void operator delete (void *p);
  //eventos
};


#endif
