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

#include<stdio.h>

#include"../include/cpwindow.h"
#include"../include/cmenu.h"
#include"../include/capplication.h"


//CPWindow _______________________________________________________________

CPWindow::CPWindow (void)
{

//  CWindow::CWindow();
  SetClass (wxT("CPWindow"));
  Window_=NULL;
};

CPWindow::~CPWindow (void)
{
};


int
CPWindow::Create (CControl * control)
{
  
  Win=this;

  if(!OverrideRedirect)
  {
  Window_ = new wxFrame(NULL,GetWid(),Title,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxDEFAULT_FRAME_STYLE,GetName());
   }
   else
  {
  Window_ = new wxFrame(NULL,GetWid(),Title,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxNO_BORDER|wxSTAY_ON_TOP  | wxFRAME_SHAPED | wxFRAME_NO_TASKBAR ,GetName());

   }


    Window_->Bind(wxEVT_SIZE,&CWindow::Event,this,GetWid()); 
    Window_->Bind(wxEVT_MAXIMIZE,&CWindow::Event,this,GetWid()); 
    Window_->Bind(wxEVT_CLOSE_WINDOW,&CWindow::Event,this,GetWid()); 
    Window_->Bind(wxEVT_SHOW,&CWindow::Event,this,GetWid()); 

    
  Widget = new wxPanel(Window_,GetWid(),wxDefaultPosition,wxDefaultSize,wxTAB_TRAVERSAL|wxFULL_REPAINT_ON_RESIZE,GetName()+wxT("p_"));

  //Widget->SetOwnBackgroundColour(*wxRED);

  return CControl::Create (control);
  
};



void
CPWindow::Destroy (void)
{
//  Win = NULL;
//  WWindow = NULL;
  on_destroy ();
  //DestroyChilds();
  CControl::Destroy ();
   
   if(Widget) 
   {
     Widget->Close();
     Widget=NULL;
   };
   
   if (Window_)
   {
     Window_->Destroy();
     Window_=NULL;
   }
};




//propiedades
wxWindow *
CPWindow::GetWWidget (void)
{
  if (Window_ != NULL)
    return Window_;
  else
    return NULL;
};

void
CPWindow::SetWidth (uint width)
{
  Width = width;
  if (GetWWidget() != NULL)
  {
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);
    GetWidget()->SetSize(0,0,Width,Height,wxSIZE_AUTO);
  }
}
  

void
CPWindow::SetHeight (uint height)
{
  Height = height;
  if (GetWWidget() != NULL)
  {
    ((wxFrame*)GetWWidget())->SetSize(X,Y,Width,Height,wxSIZE_AUTO);
    GetWidget()->SetSize(0,0,Width,Height,wxSIZE_AUTO);
  }
}

//eventos


//operators

void *
CPWindow::operator
new (size_t sz)
{
  CPWindow *m = (CPWindow *) calloc (sz, 1);
  if (!m)
    puts ("out of memory");
  m->Dynamic = true;
  m->CanDestroy = true;
  return (void *) m;
};

void 
CPWindow::operator
delete (void * p)
{
  CPWindow* pc = static_cast<CPWindow*>(p);
  free(pc);
};
