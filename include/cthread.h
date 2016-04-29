/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2015-2016  Luis Claudio Gamboa Lopes

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


#ifndef CTHREAD
#define CTHREAD

#include"ccontrol.h"
#include"cwindow.h"


/** \brief Thread Control.
 *
 * Generic Thread Control Class.
 */

class CThread:public CControl
{
protected:
  int CEvent (int event);
public:
  bool runstate;
    CThread (void);
   ~CThread (void);
  int Create (CControl * control);
  void Destroy (void);
//propiedades
  CStringList GetContext (void);
  void SetContext (CStringList context);
  int  Run (void);
  bool GetRunState (void);
  void SetName (const String name);
  void Event (wxCommandEvent & te);
//Events
  void (CControl::*EvThreadRun) (CControl * control);
  void (CControl::*EvThreadEnd) (CControl * control);
};

#endif
