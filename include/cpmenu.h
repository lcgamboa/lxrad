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
 * \file cpmenu.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CPMENU
#define CPMENU

#include"ccontrol.h"
#include"cwindow.h"
#include"citemmenu.h"


/** \brief Image Control.
 *
 * Generic Popup Menu Control Class.
 */


class CPMenu:public CControl
{
private:
  String MenuItems;
  String Text;
  int CEvent (int event);
public:
  CPMenu (void);
  int Create (CControl * control);
  void SetMenuItems (String mitems);
  String GetMenuItems (void);
  CStringList GetContext (void);
  void SetName (const String name);
  void SetContext (CStringList context);
//  void PopUp (GdkEventButton * event);
  void SetText (String t);
  String GetText (void);
  void Destroy (void);
  
  bool Event (wxWindow * widget, wxEvent * event);
  //Events 
  void (CControl::*EvMenuActive) (CControl * control);
};

#endif
