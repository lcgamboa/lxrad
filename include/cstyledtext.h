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
 * \file cstyledtext.h
 * \author Luis Claudio Gamboa Lopes
 * \date 12-30-2018
 */

#ifndef CSTYLEDTEXT
#define CSTYLEDTEXT

#include"ccontrol.h"

/** \brief Image Control.
 *
 * Generic Text Control Class.
 */

class CStyledText:public CControl
{
protected:
  CStringList Lines;
  bool ReadOnly;
public:
    CStyledText (void);
   ~CStyledText (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void Clear ();
  void AddLine (String line);
  void InsertLine (String line, int ln);
  void DelLine (int ln);
  void LoadFromFile (String fname);
  void SaveToFile (String fname);
  //propriedades
  void SetReadOnly(bool r);
  bool GetReadOnly(void);
  //void SetAlign(CAlign align);
  //CAlign GetAlign(void);
  uint GetCountLines (void);
};

#endif
