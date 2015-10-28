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


#include"../include/cdialog.h"
#include"../include/capplication.h"


// CDialog__________________________________________________________


CDialog::CDialog (void)
{
  Return = false;
  SetClass (wxT("CDialog"));
  SetX (320);
  SetY (240);
  SetWidth (285);
  SetHeight (135);
  SetName (wxT("Dialog"));
  //button1
  button1.SetText (wxT("OK"));
  button1.SetX (80);
  button1.SetY (75);
  button1.SetTag (1);
  button1.SetFOwner (this);
  button1.EvMouseButtonRelease = EVMOUSEBUTTONRELEASE  & CDialog::ButtonSigReleased;
  CreateChild (&button1);
  //button1
  button2.SetText (wxT("Cancel"));
  button2.SetX (150);
  button2.SetY (75);
  button2.SetTag (0);
  button2.SetFOwner (this);
  button2.EvMouseButtonRelease = EVMOUSEBUTTONRELEASE  & CDialog::ButtonSigReleased;
  CreateChild (&button2);
  //label1
  label1.SetText (wxT(""));
  label1.SetX (0);
  label1.SetY (20);
  label1.SetWidth (285);
  label1.SetHeight (55);
  label1.SetAlign (CA_CENTER);
  CreateChild (&label1);
};

void
CDialog::ButtonSigReleased (CControl * control)
{
  Return = control->GetTag ();
  HideExclusive ();
};

bool
Dialog (String label)
{
  bool ret;
  CDialog *winput;
  winput = new CDialog;
  winput->label1.SetText (label);
  Application->ACreateWindow (winput);
  winput->Return=0;
  winput->SetCanDestroy (false);
  winput->Draw ();
  winput->ShowExclusive ();
  while (winput->GetCanExitExclusive())
  {
    Application->ProcessEvents(winput->GetWWidget());
    wxMilliSleep(100);
  }
  winput->SetCanDestroy (true);
  ret = winput->Return;
  winput->WDestroy ();
  return ret;
};
