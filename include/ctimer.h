/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2016  Luis Claudio Gamboa Lopes

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


#ifndef CTIMER
#define CTIMER

#include"ccontrol.h"
#include"cwindow.h"


/** \brief Timer Control.
 *
 * Generic Timer Control Class.
 */

class CTimer:public CControl
{
protected:
  uint Time;
  bool Run;
  int CEvent (int event);
public:
    CTimer (void);
   ~CTimer (void);
  int Create (CControl * control);
  void Destroy (void);
//propiedades
  CStringList GetContext (void);
  void SetContext (CStringList context);
  void SetRunState (bool run);
  bool GetRunState ();
  void SetTime (uint time);
  uint GetTime (void);
  void SetName (const String name);
  void Event (wxTimerEvent & te);
//Events
  void (CControl::*EvOnTime) (CControl * control);
};

#endif
