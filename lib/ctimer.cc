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


#include"../include/capplication.h"
#include"../include/ctimer.h"


#ifndef __WXMSW__
#include<unistd.h>
#else
#define sleep(x) Sleep(x)
#include<winbase.h>
#endif

// CTimer___________________________________________________________

CTimer::CTimer (void)
{
  CanFocus = false;
  CanVisible = false;
  SetClass (wxT("CTimer"));
  Time = 1000;
  Run = false;
  SetVisible (false);
  EvOnTime = NULL;
};

CTimer::~CTimer (void)
{
};

int
CTimer::Create (CControl * control)
{
   Widget =(wxWindow*) new wxTimer;	

   ((wxTimer*)Widget)->SetOwner(GetWidget(),GetWid());
  
    Widget->Bind(wxEVT_TIMER,&CTimer::Event,this,GetWid()); 

      Win = control->GetWin ();
  
  if(Run)
  {
     SetRunState (false);
     SetRunState (true);
  };

  CanExecuteEvent=false;
  CControl::Create (control);
  CanExecuteEvent=true;

  return 0;
};

void
CTimer::Destroy (void)
{
  SetRunState (false);
  CControl::Destroy ();
};

int CTimer::CEvent (int event)
{
  if(event == wxEVT_TIMER)return lxEVT_TIMER;
  return CControl::CEvent(event);
}


  
void 
CTimer::Event (wxTimerEvent & te)
{
  te.Skip();
  if ((FOwner) && (EvOnTime)&&(Application->GetRun()))
     { 
     (FOwner->*EvOnTime) (this);
     }
};


CStringList
CTimer::GetContext (void)
{
//  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("Time"), wxT("int"), itoa (GetTime ())));
  Context.AddLine (xml_out (wxT("RunState"), wxT("int"), itoa (GetRunState ())));
  Context.AddLine (xml_out (wxT("EvOnTime"), wxT("Event"), btoa (GetEv (true))));
  return Context;
};

void
CTimer::SetContext (CStringList context)
{
  String name, type, value;

//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      
      if (name.compare (wxT("Time")) == 0)
	SetTime (atoi (value));
      if (name.compare (wxT("RunState")) == 0)
	SetRunState (atoi (value));
      if (name.compare (wxT("EvOnTime")) == 0)
	SetEv (atob (value),true);
    };
};

//propiedades

void
CTimer::SetTime (uint time)
{
  Time = time; 
};

uint CTimer::GetTime (void)
{
  return Time;
};

void
CTimer::SetRunState (bool run)
{
  if (Run != run)
    {
      if (Widget != NULL)
	{
	  if (run)
	    {
   	     ((wxTimer*)Widget)->Start(Time,false);
	    }
	  else
	    {
	      Run = false;
   	     ((wxTimer*)Widget)->Stop();
	     while(((wxTimer*)Widget)->IsRunning() == true);
	    };
	};
      Run = run;
    };
};

bool CTimer::GetRunState (void)
{
  return Run;
};

void
CTimer::SetName (const String name)
{
  Name = name;
};

