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
 * \file ctogglebutton.h
 * \author Luis Claudio Gamboa Lopes
 * \date 07-17-2016
 */

#ifndef CTOGGLEBUTTON
#define CTOGGLEBUTTON


#include"ccontrol.h"
#include"cwindow.h"

/** \brief Toggle Button Control
 *
 * Toggle Button Control class
 */

class CToggleButton:public CControl
{
private:
  lxString Text;
  bool Check;	///<Is Checked ?
  int CEvent (int event);
public:
    CToggleButton (void);
   ~CToggleButton (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //propiedades
  void SetCheck (bool check);
  bool GetCheck (void);
  void SetText (lxString t);
  lxString GetText (void);

  void Event (wxEvent & event);
  //Events
  void (CControl::*EvOnToggleButton) (CControl * control);
};

#endif
