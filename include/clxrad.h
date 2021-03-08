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


//Constants definitions

/**
 * \file clxrad.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef CLXRAD
#define CLXRAD


#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#ifndef _THREAD_SAFE
#define _THREAD_SAFE

#undef _MSTRING

#define lxString wxString


//c++ headers
using namespace std;
#include<iostream>
#include<fstream>
#include<string>
#include<list>
#endif

//c headers
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


// For compilers that support precompilation, includes "wx/wx.h".
#include "wx/wxprec.h"

#ifdef __BORLANDC__
    #pragma hdrstop
#endif

    // for all others, include the necessary headers (this file is usually all you
    // // need because it includes almost all "standard" wxWidgets headers)
#ifndef WX_PRECOMP
   #include "wx/wx.h"
   #include "wx/textfile.h"
   #include "wx/sound.h"
   #include "wx/filename.h"
#endif

#ifndef uint
#define uint unsigned int
#endif


#include"mstring.h"


#define Initialize IMPLEMENT_APP(CApplication);bool CApplication::OnInit(){Application=this;wxInitAllImageHandlers();Aargc=argc;Aargv=argv;OnInit_();return 1;};bool CApplication::OnInit_()

enum lxevent 
{
lxEVT_MOTION,
lxEVT_KEY_DOWN,
lxEVT_KEY_UP,
lxEVT_LEFT_DOWN,
lxEVT_LEFT_UP,
lxEVT_LEFT_DCLICK,
lxEVT_RIGHT_DOWN,
lxEVT_RIGHT_UP,
lxEVT_RIGHT_DCLICK,
lxEVT_ENTER_WINDOW,
lxEVT_LEAVE_WINDOW,
lxEVT_PAINT,
lxEVT_DESTROY,
lxEVT_MAXIMIZE,
lxEVT_SHOW,
lxEVT_SET_FOCUS,
lxEVT_KILL_FOCUS,
lxEVT_SIZE,
lxEVT_CLOSE_WINDOW,
lxEVT_COMMAND_CHECKBOX_CLICKED,
lxEVT_COMBOBOX,
lxEVT_COMMAND_LISTBOX_SELECTED,
lxEVT_COMMAND_LISTBOX_DOUBLECLICKED,
lxEVT_COMMAND_MENU_SELECTED,
lxEVT_TIMER,
lxEVT_COMMAND_TREE_ITEM_ACTIVATED,
lxEVT_SCROLL_CHANGED,
lxEVT_HTML_LINK_CLICKED,
lxEVT_GRID_SELECT_CELL,
lxEVT_GRID_CELL_LEFT_CLICK,
lxEVT_GRID_CELL_RIGHT_CLICK,
lxEVT_THREAD_END,
lxEVT_SPINCTRL,
lxEVT_SPINCTRLDOUBLE,
lxEVT_TOGGLEBUTTON,
lxEVT_SCROLL_THUMBTRACK,
lxEVT_MOUSEWHEEL
};

#define Parent 99999
#define EVMAX 50
#define SIGMAX 50
#define DOUBLECLICKTIME 400

#define EVMOUSEMOVE              (void(CControl::*)(CControl*,const uint,const uint,const uint,const uint))
#define EVMOUSEBUTTONPRESS       (void(CControl::*)(CControl*,const uint,const uint,const uint,const uint))
#define EVMOUSEBUTTONRELEASE     (void(CControl::*)(CControl*,const uint,const uint,const uint,const uint))
#define EVMOUSEBUTTONCLICK       (void(CControl::*)(CControl*,const uint,const uint,const uint,const uint))
#define EVMOUSEBUTTONDOUBLECLICK (void(CControl::*)(CControl*,const uint,const uint,const uint,const uint))
#define EVKEYBOARDPRESS          (void(CControl::*)(CControl*,const uint,const uint,const uint))
#define EVKEYBOARDRELEASE        (void(CControl::*)(CControl*,const uint,const uint,const uint))
#define EVPOINTERIN              (void(CControl::*)(CControl*))
#define EVPOINTEROUT             (void(CControl::*)(CControl*))
#define EVONDRAW                 (void(CControl::*)(CControl*))
#define EVONFOCUSIN              (void(CControl::*)(CControl*))
#define EVONFOCUSOUT             (void(CControl::*)(CControl*))
#define EVMOUSEWHEEL             (void(CControl::*)(CControl*,const int))

#define EVONCHECKBOX               (void(CControl::*)(CControl*))
#define EVONCOMBOCHANGE            (void(CControl::*)(CControl*))
#define EVLISTSELECT               (void(CControl::*)(CControl*))
#define EVLISTDOUBLECLICK          (void(CControl::*)(CControl*))
#define EVONTIME	           (void(CControl::*)(CControl*))
#define EVFILELISTSELECTFILE       (void(CControl::*)(CControl*))
#define EVFILELISTSELECTDIR        (void(CControl::*)(CControl*))
#define EVMENUACTIVE               (void(CControl::*)(CControl*))
#define EVONCHANGEPOSITION         (void(CControl::*)(CControl*))

#define EVONGRIDCELLLEFTCLICK      (void(CControl::*)(CControl*))

#define EVTHREADRUN	           (void(CControl::*)(CControl*))
#define EVTHREADEND	           (void(CControl::*)(CControl*))

#define EVONCHANGESPIN		   (void(CControl::*)(CControl*))
#define EVONCHANGESPINDOUBLE 	   (void(CControl::*)(CControl*))

#define EVONTOGGLEBUTTON	   (void(CControl::*)(CControl*))

#define EVONCLOSE        (void(CControl::*)(const int))

#define CA_LEFT   1
#define CA_RIGHT  2
#define CA_CENTER 3
#define CA_FILL   4
typedef int CAlign;

class CApplication;
extern CApplication *Application;

#endif
