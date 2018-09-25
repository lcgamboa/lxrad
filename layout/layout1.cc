/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2010-2018 Luis Claudio Gamboa Lopes

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

#include"layout1.h"
#include"layout1_d.cc"

CPWindow1 Window1;

//Implementation

#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#include<unistd.h>
#include"controlsdef.h"

#include "wx/stdpaths.h"
#include<dirent.h>

int WN = 1;
String Version = wxT(_VERSION);
int PNW = 1;
String PName = wxT("untitled");
String PDir = wxT("~/");
String POptions = wxT("-Wall -O2");
String PLibs = wxT(" ");
String PIncludeFile = wxT(" ");
bool Save = false;
bool Move;
String operation = wxT("editar");
String Browser = wxT("firefox");
String Editor = wxT("xterm -e vim");
String Debuger = wxT("ddd");
String Home = wxT("");

#include"layout2.h"
#include"layout5.h"
#include"layout6.h"


void
CPWindow1::menu1_Windows_Windowx_EvMenuActive(CControl * control)
{
  CItemMenu *im;
  im = dynamic_cast < CItemMenu * >(control);
  if (Save)
    {
      Save = false;
      Window2.MakeOrUpdateFiles (true);
    };
  WN = im->GetTag ();
  //Window2.ListPropierties (&Window2);
  Window2.DestroyChilds ();
  Window2.Reset ();
  Window2.LoadProject (PDir, PName + wxT(".prj_lxrad"));
  Save = true;

};


void
CPWindow1::_EvOnCreate(CControl * control)
{
  wxTextFile fin, fout;
  DIR  *dp;
  
  getbuttons (this);

  wxStandardPathsBase& stdp = wxStandardPaths::Get();
  Home= stdp.GetUserDataDir();
  

   dp = opendir ((char *)Home.char_str());

   if(dp)
   {
     closedir(dp);
   }
   else
   {
     remove((char *)Home.char_str());
#ifndef __WXMSW__
     mkdir((char *)Home.char_str(), S_IWUSR| S_IRUSR | S_IXUSR | S_IRGRP | S_IROTH );
#else
     mkdir((char *)Home.char_str());
#endif
   }



  Home= stdp.GetUserDataDir()+wxT("/lxrad.ini");

  fin.Open (Home);
  
  if (fin.IsOpened())
    {
      fin.GoToLine(-1);
      fgetline(fin,Browser);
      fgetline(fin,Editor);
      fgetline(fin,Debuger);
      fin.Close();
    }
  else
    {
      
     if(fout.Create(Home) != true)
         fout.Open(Home);
      
     fout.Clear();
     
     fout.AddLine(Browser);
     fout.AddLine(Editor);
     fout.AddLine(Debuger);
     fout.Write(); 
     fout.Close();
    };
};


void
CPWindow1::MouseButtonClick (CControl * control, uint button, uint x, uint y, uint state)
{
  Window1.SetTitle (wxT("LXRAD Layout - ") + ((CButton *) control)->GetName ());
  operation = ((CButton *) control)->GetName ();
  Save = true;
};

void
CPWindow1::menu1_File_NewProject_EvMenuActive(CControl * control)
{
  if (Save)
    {
      Save = false;
      Window2.MakeOrUpdateFiles(true);
    };

  Window5.ShowExclusive ();
};

void
CPWindow1::menu1_File_NewWindow_EvMenuActive(CControl * control)
{
  if (Save)
    {
      Save = false;
      Window2.MakeOrUpdateFiles (true);
    };
  PNW++;
  WN = PNW;
  Window1.menu1_Windows.DestroyChilds ();
  for (int n = 1; n <= PNW; n++)
    {
      CItemMenu *im;
      im = new CItemMenu;
      im->SetText (wxT("Window") + itoa (n));
      im->SetName (String(wxT("pmenu4_"))+wxT("Window") + itoa (n));
      im->SetTag (n);
      im->SetFOwner (this);
      im->EvMenuActive = EVMENUACTIVE & CPWindow1::menu1_Windows_Windowx_EvMenuActive;
      Window1.menu1_Windows.CreateChild (im);
    };
  operation = wxT("editar");
  Window2.DestroyChilds ();
  Window2.Reset ();
  Window2.SetName (wxT("window")+itoa (WN));
  Window2.SetX (240);
  Window2.SetY (40);
  Window2.SetWidth (400);
  Window2.SetHeight (400);
  Window2.SetTitle (PName);
  Window2.ListPropierties (&Window2);
  Save = true;
};

void
CPWindow1::menu1_File_Save_EvMenuActive(CControl * control)
{
  Window2.MakeOrUpdateFiles (false);
  Save = false;
};

void
CPWindow1::menu1_File_Preferences_EvMenuActive(CControl * control)
{
  String temp;
  wxTextFile fout;

  temp = Browser;
  if (Input (wxT("Browser:"), temp))
    Browser = temp;
  temp = Editor;
  if (Input (wxT("Editor:"), temp))
    Editor = temp;
  temp = Debuger;
  if (Input (wxT("Debuger:"), temp))
    Debuger = temp;

      
   fout.Open(Home);
  
   if (fout.IsOpened())
   {    
     fout.Clear();
     
     fout.AddLine(Browser);
     fout.AddLine(Editor);
     fout.AddLine(Debuger);
     fout.Write(); 
     fout.Close();
    }
  else
    {
      Message (wxT("Error on saving preferences!"));
    };
};

void
CPWindow1::menu1_File_Exit_EvMenuActive(CControl * control)
{
  if (Save)
    {
      Save = false;
      Window2.MakeOrUpdateFiles (true);
    };
  Window1.WDestroy ();
};

void
CPWindow1::menu1_Edit_Options_EvMenuActive(CControl * control)
{
  Input (wxT("Options:"), POptions);
  Save = true;
};

void
CPWindow1::menu1_Edit_Clear_EvMenuActive(CControl * control)
{
  if(Dialog(wxT("Do you wish clear all?")) == 1)
  {
   operation = wxT("editar");
   Window2.ListPropierties (&Window2);
   Window2.DestroyChilds ();
   Window2.Reset ();
   Save = true;
  }
};

void
CPWindow1::menu1_Edit_DeleteControl_EvMenuActive(CControl * control)
{
  //operation = wxT("editar");
  CControl * dcontrol=Window2.GetChildByName(Window6.combo1.GetText()); 
  
  Window2.ListPropierties (&Window2);
  Window2.DestroyChild (dcontrol);
  Window2.MakeOrUpdateFiles(false);
  WN = 1;
  Window2.SetAux(1);
  Window2.DestroyChilds ();
  Window2.Reset ();
  Window2.ReLoadProject ();
};

void
CPWindow1::menu1_Edit_IncludeFiles_EvMenuActive(CControl * control)
{
  Input (wxT("Files:"), PIncludeFile);
  Save = true;
};


void
CPWindow1::menu1_Edit_IncludeLibs_EvMenuActive(CControl * control)
{
  Input (wxT("Libs:"), PLibs);
  Save = true;
};


void
CPWindow1::menu1_Project_Run_EvMenuActive(CControl * control)
{
  wxSetWorkingDirectory(PDir);
  //Window2.MakeList(false);
  system ("make run");
};

void
CPWindow1::menu1_Project_Build_EvMenuActive(CControl * control)
{
  wxSetWorkingDirectory(PDir);
  Window2.MakeOrUpdateFiles (false);
  system ("make");
};

void
CPWindow1::menu1_Project_Clean_EvMenuActive(CControl * control)
{
  wxSetWorkingDirectory(PDir);
  //Window2.MakeList(false);
  system ("make clean");
};

void
CPWindow1::menu1_Project_EditSource_EvMenuActive(CControl * control)
{
  wxSetWorkingDirectory(PDir);
  Window2.MakeOrUpdateFiles (false);
  wxExecute(Editor + wxT(" ") + PName + itoa (WN) + wxT(".cc"), wxEXEC_SYNC, NULL);
};

void
CPWindow1::menu1_Project_Debug_EvMenuActive(CControl * control)
{
  String temp;
  wxSetWorkingDirectory(PDir);
  temp = POptions;
  POptions = wxT("-Wall -ggdb3");
  Window2.MakeOrUpdateFiles (false);
  system ("make");
  wxExecute(Debuger + wxT(" ") + PName, wxEXEC_SYNC, NULL);
  //system ("make clean");
  wxExecute(wxT("make clean"), wxEXEC_SYNC, NULL);
  POptions = temp;
  Window2.MakeOrUpdateFiles (false);
};

void
CPWindow1::menu1_Help_Contents_EvMenuActive(CControl * control)
{
  wxExecute(Browser + wxT(" ") + String (wxT(_SHARE)) + wxT("/docs/index.html"), wxEXEC_ASYNC, NULL);
};

void
CPWindow1::menu1_Help_Reference_EvMenuActive(CControl * control)
{
  wxExecute(Browser + wxT(" ") + String (wxT(_SHARE)) + wxT("/docs/doxygen/html/index.html"), wxEXEC_ASYNC, NULL);
};

void
CPWindow1::menu1_Help_About_EvMenuActive(CControl * control)
{
  Message (wxT("LXRAD-") + String(wxT(_VERSION)) + wxT(" Developed by LCGamboa <lcgamboa@yahoo.com>"));
};






