/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2018  Luis Claudio Gamboa Lopes

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
 * \file cdirdialog.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CDIRDIALOG
#define CDIRDIALOG

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Dir Dialog Control.
 *
 * Generic Dir Dialog Control Class.
 */

class CDirDialog:public CControl
{
private:
  String DirName;
  long Type;
public:
  CDirDialog (void);
   ~CDirDialog (void);
  int Create (CControl * control);
  void Run (void);
  //propriedades
  String GetDirName (void);
  void SetDirName (String dirname);
  long GetType(void);
  void SetType(long type);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  //events
  void (CControl::*EvOnClose) (int retId);  
};

#endif
