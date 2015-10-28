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
 * \file cdialog.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CDIALOG
#define CDIALOG

#include"cpwindow.h"
#include"clabel.h"
#include"cbutton.h"
#include"cedit.h"


/** \brief Dialog Control.
 *
 * Generic Dialog Control Class.
 */

class CDialog:public CPWindow
{
public:
  CButton button1, button2;
  CLabel label1;
  bool Return;
  void ButtonSigReleased (CControl * control);
    CDialog (void);
};

bool Dialog (String label);

#endif
