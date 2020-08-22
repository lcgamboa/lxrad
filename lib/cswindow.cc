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

#include<stdio.h>

#include"../include/cswindow.h"
#include"../include/cmenu.h"
#include"../include/capplication.h"


//CSWindow _______________________________________________________________

CSWindow::CSWindow (void)
{

//  CWindow::CWindow();
  SetClass (wxT("CSWindow"));
  ImgFileName=wxT("");
  Timeout=6000;

/*
  Win = NULL;
  SetX (0);
  SetY (0);
  SetWidth (300);
  SetHeight (200);
  SetBorder (1);
  Visible = 1;
  Title = wxT("LXRAD Window");
  WParent = false;
  OverrideRedirect = false;
//scale  
  SetPWidth (1024);
  SetPHeight (768);
//events
  EvOnCreate = NULL;
  EvOnDestroy = NULL;
  EvOnShow = NULL;
  EvOnHide = NULL;
  EvOnEnter = NULL;
  EvOnLeave = NULL;
*/
};

CSWindow::~CSWindow (void)
{
};


int
CSWindow::Create (CControl * control)
{
  
  Win=this;

   wxBitmap bitmap;
   if (bitmap.LoadFile(ImgFileName, wxBITMAP_TYPE_PNG))
   {
     Widget = new wxSplashScreen(bitmap, wxSPLASH_CENTRE_ON_SCREEN|wxSPLASH_TIMEOUT,Timeout, NULL, -1, wxDefaultPosition, wxDefaultSize, wxSIMPLE_BORDER|wxSTAY_ON_TOP);
   }
   else
   {
#ifdef __UNICODE__   
    printf("Splash ImgFileName Invalid! (\"%ls\") \n",(const wchar_t *)ImgFileName.c_str());
#else
    printf("Splash ImgFileName Invalid! (\"%s\") \n",(const char *)ImgFileName.c_str());
#endif
  }
   
   wxYield();


  return 1;
  
};



//propiedades


void 
CSWindow::SetImgFileName(lxString fname)
{
  ImgFileName=fname;
};

void 
CSWindow::SetTimeout(unsigned int tout)
{
  Timeout=tout;
};


//eventos


//operators

void *
CSWindow::operator
new (size_t sz)
{
  CSWindow *m = (CSWindow *) calloc (sz, 1);
  if (!m)
    puts ("out of memory");
  m->Dynamic = true;
  m->CanDestroy = true;
  return (void *) m;
};

void 
CSWindow::operator
delete (void * p)
{
  CSWindow* pc = static_cast<CSWindow*>(p);
  free(pc);
};
