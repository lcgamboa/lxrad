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
 * \file cedit.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CEDIT
#define CEDIT

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Edit Control.
 *
 * Generic Edit Control Class.
 */

class CEdit:public CControl
{
protected:
  uint MaxLenght;	///<Max Len
  String Text;		///<Text
  uint CursorPos;		
  bool ReadOnly;
  CAlign Align;		
public:
    CEdit (void);
   ~CEdit (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  //propiedades
  virtual void SetText (String t);
  virtual String GetText (void);
  void SetReadOnly (bool r);
  bool GetReadOnly (void);
  void SetMaxLenght (int l);
  int GetMaxLenght (void);
  void SetAlign (CAlign align);
  CAlign GetAlign (void);
};

#endif
