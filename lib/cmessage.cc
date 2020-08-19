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


#include"../include/cmessage.h"
#include"../include/capplication.h"


// CMessage__________________________________________________________


CMessage::CMessage (void)
{
  SetClass (wxT("CMessage"));
  SetX (320);
  SetY (240);
  SetWidth (285);
  SetHeight (135);
  SetName (wxT("Message"));
  //button1
  button1.SetText (wxT("OK"));
  button1.SetX (110);
  button1.SetY (70);
  button1.SetFOwner (this);
  button1.EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CMessage::ButtonRelease1;
  CreateChild (&button1);
  //label1
  label1.SetText (wxT("OK"));
  label1.SetX (0);
  label1.SetY (20);
  label1.SetWidth (285);
  label1.SetHeight (55);
  label1.SetAlign (CA_CENTER);
  CreateChild (&label1);
};

void
CMessage::ButtonRelease1 (CControl * control, uint button, uint x, uint y, uint state)
{
  HideExclusive ();
};

//extern int wdelete_callback (GtkWidget * widget, GdkEvent * event, gpointer data);

void
Message (String str)
{
  CMessage *wmessage = new CMessage;
  int width, height;  

  wxDisplaySize (&width,&height);  
  
  wmessage->SetX ((width  - wmessage->GetWidth  ())/2);
  wmessage->SetY ((height - wmessage->GetHeight ())/2);

  wmessage->label1.SetText (str);
  Application->ACreateWindow (wmessage);
  wmessage->SetCanDestroy (false);
  wmessage->Draw ();
  wmessage->ShowExclusive ();
  while (wmessage->GetCanExitExclusive())
  {
    Application->ProcessEvents(wmessage->GetWWidget());
    wxMilliSleep(100);
  }
  wmessage->SetCanDestroy (true);
  wmessage->WDestroy ();
}

void
Message_sz (String str, int Width, int Height)
{
  CMessage *wmessage = new CMessage;
  int width, height;  
  
  wmessage->SetWidth (Width);
  wmessage->SetHeight (Height);
  wmessage->button1.SetX ((Width- wmessage->button1.GetWidth())/2);
  wmessage->button1.SetY (Height-65);
  wmessage->label1.SetWidth (Width-5);
  wmessage->label1.SetHeight (Height-80);

  wxDisplaySize (&width,&height);  
  
  wmessage->SetX ((width  - wmessage->GetWidth  ())/2);
  wmessage->SetY ((height - wmessage->GetHeight ())/2);

  wmessage->label1.SetText (str);
  Application->ACreateWindow (wmessage);
  wmessage->SetCanDestroy (false);
  wmessage->Draw ();
  wmessage->ShowExclusive ();
  while (wmessage->GetCanExitExclusive())
  {
    Application->ProcessEvents(wmessage->GetWWidget());
    wxMilliSleep(100);
  }
  wmessage->SetCanDestroy (true);
  wmessage->WDestroy ();
}
