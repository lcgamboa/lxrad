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
 * \file cfilelist.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */


#ifndef CFILELIST
#define CFILELIST

#include"ccontrol.h"
#include"cwindow.h"

/** \brief File List Control.
 *
 * Generic File List Control Class.
 */


class CFileList:public CControl
{
protected:
  lxString DefaultDir;	
  int CEvent (int event);
public:
  CFileList (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  //propiedades
  void SetDir (lxString dir);
  lxString GetSelectedDir (void);
  lxString GetSelectedFile (void);
  CControl *GetChildByWidget (wxWindow * widget);
  void Event (wxEvent & event);
  //Events
  void (CControl::*EvFileListSelectDir) (CControl * control);
  void (CControl::*EvFileListSelectFile) (CControl * control);
};

#endif
