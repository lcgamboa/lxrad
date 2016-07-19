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


#include"../include/cfiledialog.h"


// CFileDialog__________________________________________________________


CFileDialog::CFileDialog (void)
{
//  CanFocus = false;
  CanVisible = false;
  FileName = wxT("untitled.txt");
  Dir = wxGetCwd();
  SetVisible (false);
  SetName (wxT("FileDialog"));
  SetClass (wxT("CFileDialog"));
  Type= wxFD_OPEN|wxFD_CHANGE_DIR;
  CanExecuteEvent=false;
  SetFilter(wxT("All Files (*.*)|*.*"));
};


CFileDialog::~CFileDialog (void)
{
};

int
CFileDialog::Create (CControl * control)
{
  //disabled because gtk bug

  //Widget =  new wxFileDialog(((CWindow *)control)->GetWWidget (), wxT("Choose a file"),Dir,wxT(""), Filter, Type);
  //SetFileName (FileName);
  //((wxFileDialog*)Widget)->SetDirectory(wxGetCwd());
  
  //return 0;
    
  Widget=NULL; 

  return CControl::Create (control);
};

String
CFileDialog::GetFileName (void)
{
  if (Widget != NULL)
     FileName=((wxFileDialog*)Widget)->GetPath();
//     FileName=((wxFileDialog*)Widget)->GetFilename();

  return FileName;
};

String
CFileDialog::GetDir (void)
{
  if (Widget != NULL)
     Dir=((wxFileDialog*)Widget)->GetDirectory();

  return Dir;
};


void
CFileDialog::SetFileName (String filename)
{
  FileName = filename;
  SetDir(dirname(filename));
  if (Widget != NULL)
      ((wxFileDialog*)Widget)->SetFilename(basename(filename));
};

void
CFileDialog::SetDir (String dir)
{
  Dir = dir;
  if(wxDirExists(dir))
    wxSetWorkingDirectory(dir);
  if (Widget != NULL)
      ((wxFileDialog*)Widget)->SetDirectory(dir);

};


bool
CFileDialog::Run (void)
{
  int run;

  Widget =  new wxFileDialog(((CWindow *)GetOwner())->GetWWidget (), wxT("Choose a file"),Dir,basename(FileName), Filter, Type);
  //SetFileName (FileName);
  //((wxFileDialog*)Widget)->SetDirectory(wxGetCwd());

  switch(((wxFileDialog*)Widget)->ShowModal())
    {
    case wxID_OK :
      run= 1;
      FileName=((wxFileDialog*)Widget)->GetPath();
      Dir=((wxFileDialog*)Widget)->GetDirectory();
      break;
    default:
      run= 0;
      break;
    };

  delete Widget;

  Widget=NULL; 

return run;
};


CStringList CFileDialog::GetContext (void)
{
//  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("FileName"), wxT("String"), GetFileName ()));
  Context.AddLine (xml_out (wxT("Filter"), wxT("String"), GetFilter ()));
  Context.AddLine (xml_out (wxT("Type"), wxT("int"), itoa(GetType ())));
  return Context;
};

void
CFileDialog::SetContext (CStringList context)
{
  String name, type, value;
//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Filter")) == 0)
	SetFilter (value);
      if (name.compare (wxT("Type")) == 0)
	SetType (atoi(value));
      if (name.compare (wxT("Filename")) == 0)
	SetFileName (value);
    };
};
  
  
long 
CFileDialog::GetType(void)
{
  return Type;
};


void 
CFileDialog::SetType(long type)
{
  Type =type;
  
  if(Widget)
    ((wxFileDialog*)Widget)->SetWindowStyle(Type);
//    ((wxFileDialog*)Widget)->SetStyle(Type);
};
  
  
String
CFileDialog::GetFilter(void)
{
  return Filter;
};


void 
CFileDialog::SetFilter(String filter)
{
  Filter= filter;
  
  if(Widget)
    ((wxFileDialog*)Widget)->SetWildcard(Filter);
};
