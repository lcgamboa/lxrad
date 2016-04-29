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
 * \file ccontrol.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CCONTROL
#define CCONTROL

#include"cobject.h"

class CWindow;
class CPMenu;
class CMenu;

/** \brief Generic Control
 *
 * Generic Control class
 */

class CControl:public CObject
{
protected:
  CControl * FOwner;		///<function owner control
  CControl * ControlOnFocus;	///<Control On Focus
  wxWindow *Widget;		///<Object wxWidget
  long	Wid;			///<wx ID
  bool Dynamic;			///<Dynamic Object?
  bool CanFocus;		///<CanFocus ?
  bool CanExecuteEvent;		///<Can Execute Event ?
  bool CanVisible;		///<Can be Visible ?
  bool Enable;
  int X, Y;
  uint Width, Height;
  uint Border;
  long Color;
  long DisableColor;
  String ColorName;
  unsigned char ColorRGB[3];
  CControl **Child;
  int ChildCount;
  String FontName;
  uint FontSize;
  CControl *Owner;
  bool Visible;
  CPMenu *PopupMenu;
  CWindow *Win;
  String Hint;
  unsigned long int BTimePress;
  unsigned long int BTimeRelease;
  unsigned long int BTimeClick;
  virtual int CEvent (int event);
public:
    CControl (void);
   ~CControl (void);
  virtual void SetName (const String name);
  String GetName (void);
  CWindow *GetWin (void);
  void SetWin (CWindow * win);
  virtual wxWindow *GetWidget (void);
  virtual void Event (wxEvent & event);
  virtual int Create (CControl * control);
  virtual void Destroy (void);
  virtual void Erase (void);
  virtual void Draw (void);
  virtual void Update (void);
  CStringList GetContext (void);
  void SetContext (CStringList context);
//propiedades
  void SetFont (const String font);
  String GetFontName (void);
  void SetFontSize (uint size);
  uint GetFontSize (void);
  virtual void SetX (int x);
  virtual int GetX (void);
  virtual void SetY (int y);
  virtual int GetY (void);
  virtual void SetBorder (uint border);
  uint GetBorder (void);
  virtual void SetWidth (unsigned w);
  virtual uint GetWidth (void);
  virtual void SetHeight (unsigned h);
  virtual uint GetHeight (void);
  void SetWid (int wid);
  long GetWid (void);
  virtual void SetColor (const String name);
  virtual void SetColor (unsigned r, unsigned g, unsigned b);
  virtual void SetEnable (bool enable);
  virtual bool GetEnable (void);
  void SetOwner (CControl * control);
  CControl *GetOwner (void);
  void SetVisible (bool visible, bool update = true);
  bool GetVisible (void);
  bool GetCanVisible (void);
  void SetPopupMenu (CPMenu * popupmenu);
  void SetFocus (void);
  bool GetFocus (void);
  void SetCanFocus (bool canfocus);
  bool GetCanFocus (void);
  bool GetDynamic (void);
  int GetChildCount (void);
  void SetHint (String hint);
  String GetHint (void);
  CControl *GetChild (uint child);
  virtual CControl *GetChildByWidget (wxWindow * widget);
  CControl *GetChildByWid (long wid);
  CControl *GetChildByName (const String child);
  virtual void CreateChild (CControl * control, bool onlyput = false);
  virtual void DestroyChild (CControl * control);
  virtual void DestroyChilds (void);
  virtual void WriteXMLContext (String filename, bool first = true);
  virtual void LoadXMLContext (String filename);
  void SetCanExecuteEvent (bool can);
  bool GetCanExecuteEvent (void);
//operators
  void *operator    new (size_t sz);
  void operator delete (void *p);
  void SetFOwner (CControl * control);
  CControl *GetFOwner (void);

//events

  virtual void mouse_move (wxMouseEvent* event);
  virtual void button_press (wxMouseEvent* event);
  virtual void button_release (wxMouseEvent* event);
  virtual void key_press (wxKeyEvent* event);
  virtual void key_release (wxKeyEvent *event);
  virtual void focus_in (wxMouseEvent* event);
  virtual void focus_out (wxMouseEvent* event);
  virtual void on_draw (wxPaintEvent* event);

  void (CControl::*EvMouseMove) (CControl * control,const uint button,const uint x,const uint y,const uint mask);
  void (CControl::*EvMouseButtonPress) (CControl * control,const uint button,const uint x,const uint y,const uint mask);
  void (CControl::*EvMouseButtonRelease) (CControl * control,const uint button,const uint x,const uint y,const uint mask);
  void (CControl::*EvMouseButtonClick) (CControl * control,const uint button,const uint x,const uint y,const uint mask);
  void (CControl::*EvMouseButtonDoubleClick) (CControl * control,const uint button,const uint x,const uint y,const uint mask);
  void (CControl::*EvKeyboardPress) (CControl * control,const uint keyval,const uint hardware_keycode,const  uint state);
  void (CControl::*EvKeyboardRelease) (CControl * control,const uint keyval,const uint hardware_keycode,const uint state);
  void (CControl::*EvKeyboardKey) (CControl * control,const uint key,const uint x,const uint y,const uint mask);
  void (CControl::*EvOnDraw) (CControl * control);
  void (CControl::*EvOnFocusIn) (CControl * control);
  void (CControl::*EvOnFocusOut) (CControl * control);
};
#endif
