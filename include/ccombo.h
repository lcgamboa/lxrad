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
 * \file ccombo.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CCOMBO
#define CCOMBO

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Combo Control.
 *
 * Generic Combo Control Class.
 */

class CCombo:public CControl
{
protected:
  String Text;
  int Index;
  CStringList Items;
  bool ReadOnly;
  int CEvent (int event);
public:
    CCombo (void);
   ~CCombo (void);
  int Create (CControl * control);
  void SetItems (String litens);
  String GetItems (void);
  void AddItem (String text);
  void LoadItemsFromFile (String fname);
  void SaveItemsToFile (String fname);
  String GetItem (int item);
  void SetSelectedItem (String item);
  String GetSelectedItem (void);
  int GetSelectedItemIndex (void);
  int GetItemsCount (void);
  void DeleteItem (int item);
  void DeleteItems (bool clean =true);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void SetText (String text);
  String GetText (void);
  void Event (wxEvent & event);
  void SetReadOnly (bool r);
  bool GetReadOnly (void);
  //Events 
  void (CControl::*EvOnComboChange) (CControl * control);
};

#endif
