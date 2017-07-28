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
 * \file cwindow.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CWINDOW
#define CWINDOW

#include"ccontrol.h"

#define EVONCREATE        (void(CControl::*)(CWindow*))
#define EVONDESTROY       (void(CControl::*)(CWindow*))
#define EVONSHOW          (void(CControl::*)(CWindow*))
#define EVONHIDE          (void(CControl::*)(CWindow*))
#define EVONENTER         (void(CControl::*)(CWindow*))
#define EVONLEAVE         (void(CControl::*)(CWindow*))

/** \brief Image Control.
 *
 * Generic Window Control Class.
 */

class CWindow:public CControl
{
protected:
  String Title;
  unsigned long BorderColor;
  bool CanDestroy;
  CWindow *WParent;
  bool CanExitExclusive;
  bool OverrideRedirect;
  int WNumber;
  float VScale;
  float HScale;
  int CEvent (int event);
  wxWindowDisabler * modalmode;
public:
    CWindow (void);
   ~CWindow (void);
  void Draw (void);
  int Create (CControl * control);
  void Destroy (void);
  void DestroyChild (CControl * control);
  void DestroyChilds (void);
  virtual void WCreate (int WN, CWindow * window = NULL);
  virtual void WDestroy (void);
  void Show (void);
  void ShowExclusive (void);
  virtual void Hide (void);
  void HideExclusive (void);
  void Update (void);
  int GetWNumber (void);
  CStringList GetContext (void);
  void SetContext (CStringList context);
  int  LoadXMLContextAndCreateChilds (String filename, CControl * ctrl = NULL);
  void SetFocus (void);
  void SetControlOnFocus (CControl * control);
  CControl *GetControlOnFocus (void);
//propierty
  virtual wxWindow* GetWWidget (void);
  void SetCanDestroy (bool candestroy);
  bool GetCanDestroy (void);
  void SetOverrideRedirect (bool redirect);
  bool GetOverrideRedirect (void);
  bool GetCanExitExclusive(void);
  void SetSaveUnder (bool saveunder);
  void SetX (int x);
  int GetX (void);
  void SetY (int y);
  int GetY (void);
  void SetWidth (uint width);
  uint GetWidth (void);
  void SetHeight (uint height);
  uint GetHeight (void);
  void SetTitle (const String & title);
  String GetTitle (void);
  int GetHScale (int w);
  int GetVScale (int h);
  //operator
  void *operator    new (size_t sz);
  void operator delete (void *p);
  void Event (wxEvent & event);
  //events
  virtual void on_create (void);
  virtual void on_destroy (void);
  virtual void on_show (void);
  virtual void on_hide (void);
  virtual void on_enter (void);
  virtual void on_leave (void);

  void (CControl::*EvOnCreate) (CWindow * win);
  void (CControl::*EvOnDestroy) (CWindow * win);
  void (CControl::*EvOnShow) (CWindow * win);
  void (CControl::*EvOnHide) (CWindow * win);
  void (CControl::*EvOnEnter) (CWindow * win);
  void (CControl::*EvOnLeave) (CWindow * win);
};


#endif
