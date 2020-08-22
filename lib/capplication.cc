/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2016  Luis Claudio Gamboa Lopes

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

#include<unistd.h>

int ca;


CApplication *Application;



// CApplication__________________________________________________________

/*
CApplication::CApplication (void)
{

};
*/

/*
CApplication::~CApplication (void)
{
};
*/


void
CApplication::Start ()
{
  Title = wxT("Program");
  AWindowCount = -1;
  AWindowList = NULL;
  Tag = 0;

  Run=0;
#ifdef _DEBUG_
  mprint (wxT("Application init ...\n"));
#endif

};

void
CApplication::ACreateWindow (CWindow * AWindow, CWindow * window)
{

  if (AWindowCount == -1)
    {
      AWindow->SetVisible (true, false);
    };

  AWindowCount++;
  CWindow **WindowList;
  WindowList = new CWindow *[AWindowCount + 1];
  for (int c = 0; c < AWindowCount; c++)
    WindowList[c] = AWindowList[c];
  WindowList[AWindowCount] = AWindow;
  if (AWindowList)
    delete[]AWindowList;
  AWindowList = WindowList;

  AWindow->WCreate (AWindowCount, window);
  AWindow->Draw ();
  

};

bool CApplication::ADestroyWindow (wxCloseEvent * event)
{
  int w=-1;
  wxWindow* Widget=(wxWindow*)event->GetEventObject();

  if (AWindowList!= NULL)
    {
      for (int i = 0; i <= AWindowCount; i++)
	{
	  if (AWindowList[i]->GetWWidget () == Widget)
	    {
	      w = i;
	      break;
	    }
         }
     }

return CApplication::ADestroyWindow (w);
}


bool CApplication::ADestroyWindow (int w)
{
  if ((AWindowCount >= 0) && (w <= AWindowCount))
    {
      if (w == 0)
	{
	  AWindowList[0]->Destroy ();
	  if (AWindowList[0]->GetDynamic ())
	    delete  AWindowList[0];

	  for (int r = AWindowCount; r > 0; r--)
	    {
	      AWindowList[r]->Destroy ();
	    };
#ifdef _DEBUG_
	  mprint (wxT("...Application Finished\n"));
#endif
	  ExitMainLoop();	
	  return false;
	}
      else
	{
	  if (AWindowList[w]->GetCanDestroy ())
	    {
	      AWindowList[w]->Destroy ();
	      if (AWindowList[w]->GetDynamic ())
	        delete  AWindowList[w];
	      for (int c = w; c < AWindowCount; c++)
		AWindowList[c] = AWindowList[c + 1];
	      AWindowList[AWindowCount] = NULL;
	      AWindowCount--;
	    }
	  else
	    {
              if(AWindowList[w]->GetCanExitExclusive() == 0)
	        AWindowList[w]->Hide ();
              else
	        AWindowList[w]->HideExclusive();
	    };
	};
    };
  return true;
};



int
CApplication::Load (void)
{
  /* Enter the event loop */
#ifdef _DEBUG_
  printf("Application Run ...\n");
#endif
  Run=1;
  return 1;
};

int
CApplication::OnExit (void)
{
  delete[]AWindowList;
  AWindowList = NULL;

  return 0;
}



void
CApplication::ProcessEvents (wxWindow *window)
{
      if(IsMainLoopRunning()) 
      {
//    wxSafeYield(window,true);
      Yield(true);
      }
};


//propierties

int
CApplication::GetAWindowCount (void)
{
  return AWindowCount;
};

CWindow *
CApplication::GetAWindow (uint window)
{
  return AWindowList[window];
};

int
CApplication::GetTag ()
{
  return Tag;
};

void
CApplication::SetTag (int x)
{
  Tag = x;
};

int
CApplication::GetRun ()
{
  return Run;
};


void
CApplication::SetTitle (lxString title)
{
  Title = title;
};

lxString CApplication::GetTitle (void)
{
  return Title;
};

void
CApplication::SetTips (CControl * control)
{
};



