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
 * \file chtml.h
 * \author Luis Claudio Gamboa Lopes
 * \date 06-25-2010
 */

#ifndef CHTML
#define CHTML

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Grid Control.
 *
 * Generic Grid Control Class.
 */

class CHtml:public CControl
{
protected:
  String Text;
  String Url;
  String File;
  int CEvent (int event);
public:
  CHtml (void);
   ~CHtml (void);
  int Create (CControl * control);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void Event (wxEvent & event);
  //propiedades
  void SetLoadText (String t);
  String GetLoadText (void);
  void SetLoadUrl (String url);
  String GetLoadUrl (void);
  void SetLoadFile (String url);
  String GetLoadFile (void);
  void HistoryBack(void);
  void HistoryForward(void);
  //events
  void (CControl::*EvOnLinkClicked) (CControl * control);
};

#endif
