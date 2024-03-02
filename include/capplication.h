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
 * \file capplication.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */


#ifndef CAPPLICATION
#define CAPPLICATION

#include"clxrad.h"
#include"cwindow.h"



class CWindow;

/** \brief Application class
 *
 * Application class
 */

class CApplication : public wxApp
{
private:
  CWindow ** AWindowList;
  int AWindowCount;
  int Tag;
  int Run;
  lxString Title;
   bool OnInit_();
public:
   virtual bool OnInit();
   virtual int OnExit();
   int Aargc;
   char **Aargv;
   wchar_t **Aargvw;
//    CApplication (void);
//   ~CApplication (void);
  void Start (void);
  void ACreateWindow (CWindow * AWindow, CWindow * window = NULL);
  bool ADestroyWindow (int w);
  bool ADestroyWindow (wxCloseEvent * event);
  int  Load (void);
  void ProcessEvents (wxWindow * window = NULL);
  //propiedades
  int GetAWindowCount (void);
  CWindow *GetAWindow (uint window);
  void SetTag (int x);
  int GetTag (void);
  int GetRun (void);
  void SetTitle (lxString title);
  lxString GetTitle ();
  void SetTips (CControl * control);

};

#endif
