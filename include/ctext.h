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
 * \file ctext.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CTEXT
#define CTEXT

#include"ccontrol.h"

/** \brief Image Control.
 *
 * Generic Text Control Class.
 */

class CText:public CControl
{
protected:
  lxStringList Lines;
  bool ReadOnly;
  int cursor_pos;
public:
    CText (void);
   ~CText (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  void Clear ();
  void Append (lxString line);
  void AddLine (lxString line);
  void InsertLine (lxString line, int ln);
  void DelLine (int ln);
  void LoadFromFile (lxString fname);
  void SaveToFile (lxString fname);
  void SetCursorPos (int cpos);
  void DelLine (void);
  //propiedades
  void SetReadOnly(bool r);
  bool GetReadOnly(void);
  //void SetAlign(CAlign align);
  //CAlign GetAlign(void);
  uint GetCountLines (void);
  lxString GetLine (uint linen);
};

#endif
