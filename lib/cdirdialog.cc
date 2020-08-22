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


#include"../include/cdirdialog.h"


// CDirDialog__________________________________________________________

CDirDialog::CDirDialog (void)
{
  CanVisible = false;
  DirName = wxT ("");
  SetVisible (false);
  SetName (wxT ("DirDialog"));
  SetClass (wxT ("CDirDialog"));
  Type = wxFD_OPEN;
  CanExecuteEvent = false;
  EvOnClose = NULL;
};

CDirDialog::~CDirDialog (void) { };

int
CDirDialog::Create (CControl * control)
{
  Widget = NULL;

  //disabled because gtk bug
  /*
    Widget = new wxDirDialog(((CWindow *)control)->GetWWidget (),wxT("Choose a directory"),wxGetCwd(), wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, Name);
    if(DirName.length() > 0 )
      SetDirName (DirName);
   */
  return CControl::Create (control);
};

lxString
CDirDialog::GetDirName (void)
{
  if (Widget != NULL)
    DirName = ((wxDirDialog*) Widget)->GetPath ();

  return DirName;
}

void
CDirDialog::SetDirName (lxString dirname)
{
  DirName = dirname;
  if (Widget != NULL)
    ((wxDirDialog*) Widget)->SetPath (DirName);
}

void
CDirDialog::Run (void)
{
  int run;

  Widget = new wxDirDialog (((CWindow *) GetOwner ())->GetWWidget (), wxT ("Choose a directory"), wxGetCwd (), wxDD_DEFAULT_STYLE, wxDefaultPosition, wxDefaultSize, Name);
  if (DirName.length () > 0)
    SetDirName (DirName);

  switch (((wxFileDialog*) Widget)->ShowModal ())
    {
    case wxID_OK:
      run = 1;
      DirName = ((wxDirDialog*) Widget)->GetPath ();
      break;
    default:
      run = 0;
      break;
    }


  delete Widget;
  Widget = NULL;

  if ((FOwner) && (EvOnClose))
    (FOwner->*EvOnClose) (run);
}

lxStringList
CDirDialog::GetContext (void)
{
  //  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT ("EvOnClose"), wxT ("Event"), btoa (GetEv (true))));
  return Context;
};

void
CDirDialog::SetContext (lxStringList context)
{
  lxString name, type, value;  
  //  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT ("EvOnClose")) == 0)
        SetEv (atob (value), true);
    }
};

long
CDirDialog::GetType (void)
{
  return Type;
};

void
CDirDialog::SetType (long type)
{
  Type = type;

  if (Widget)
    ((wxDirDialog*) Widget)->SetWindowStyle (Type);
  //    ((wxDirDialog*)Widget)->SetStyle(Type);
};
