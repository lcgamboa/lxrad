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
 * \file clist.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CLIST
#define CLIST

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Image Control.
 *
 * Generic List Control Class.
 */


class CList:public CControl
{
protected:
  lxStringList ItemsList;
  int SelectedItem;
  bool ShowSelection;
  bool Sort;

  int CEvent (int event);
public:
    CList (void);
   ~CList (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //propiedades
  void SetItems (lxString litens);
  lxString GetItems (void);
  void AddItem (lxString text);
  void LoadItemsFromFile (lxString fname);
  void SaveItemsToFile (lxString fname);
  lxString GetItem (int item);
  void SetItem (int item, lxString sitem);
  void SetSelectedItemN (int item);
  void SetSelectedItem (lxString item);
  int GetSelectedItemN (void);
  lxString GetSelectedItem (void);
  int GetItemsCount (void);
  void DeleteItem (int item);
  void DeleteItems (bool clean = true);
  void SetShowSelection (bool show);
  bool GetShowSelection (void);
  void SetSort (bool sort);
  bool GetSort (void);
  void Event (wxEvent & event);
  //Events
  void (CControl::*EvListSelect) (CControl * control);
  void (CControl::*EvListDoubleClick) (CControl * control);
};

#endif
