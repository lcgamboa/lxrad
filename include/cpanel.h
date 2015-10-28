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
 * \file cpanel.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CPANEL
#define CPANEL

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Image Control.
 *
 * Generic PAnel Control Class.
 */


class CPanel:public CControl
{
protected:
  String Text;
public:
  CPanel (void);
   ~CPanel (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  //propiedades
  void SetText (String t);
  String GetText (void);

//  bool Signal (GtkWidget * widget, int signal);

/*
  //Signals 
  void (CControl::*SigActivate) (CControl * control);
  void (CControl::*SigClicked) (CControl * control);
  void (CControl::*SigEnter) (CControl * control);
  void (CControl::*SigLeave) (CControl * control);
  void (CControl::*SigPressed) (CControl * control);
  void (CControl::*SigReleased) (CControl * control);
*/
};

#endif
