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
 * \file citemmenu.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CITEMMENU
#define CITEMMENU

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Item Menu Control.
 *
 * Generic Item Menu Control Class.
 */

class CPMenu;

class CItemMenu:public CControl
{
protected:
  CPMenu * SubMenu;
  lxString Text;
  int CEvent (int event);
  int doenable;
public:
    CItemMenu (void);
//propiedades;
  int Create (CControl * control);
  void SetName (const lxString name);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  void SetSubMenu (CPMenu * submenu);
  void SetText (lxString t);
  lxString GetText (void);
  void Destroy (void);
  void SetEnable (bool enable);
  void SetDoEnable (bool enable);
  
  void Event (wxEvent & event);
  //Events 
  void (CControl::*EvMenuActive) (CControl * control);
  
};

#endif
