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

#include<unistd.h>

int ca;


CApplication *Application;




//FIXME rip this code out
/*
void
CApplication::events_callback (wxEvent& event)
{



// debug	
CControl* ctrl=NULL;
int cc;
  if(wxEVT_MOTION != event.GetEventType())
  {

   for(cc=0;cc <= Application->GetAWindowCount();cc++)
   {
   if(Application->GetAWindow(cc)->GetWid() == event.GetId())
   {
     ctrl=Application->GetAWindow(cc);
     break;
   }
   else
   {
       ctrl=Application->GetAWindow(cc)->GetChildByWid(event.GetId());
       if(ctrl != NULL)break;
   }
   
   };



  if(ctrl!=NULL)
#ifdef __UNICODE__
   printf(">>>%06i Obj=%p Id=%i  Type=%i Name=%ls\n",ca++,event.GetEventObject(),event.GetId(), event.GetEventType(),ctrl->GetName().c_str());
#else
   printf(">>>%06i Obj=%p Id=%i  Type=%i Name=%s\n",ca++,event.GetEventObject(),event.GetId(), event.GetEventType(),ctrl->GetName().c_str());
#endif 
  else
    printf(">>>%06i %p %i  %i\n",ca++,event.GetEventObject(),event.GetId(), event.GetEventType());
  }
 

  if(Application->AEvent ((wxWindow * )event.GetEventObject(), &event, -1))
  {
     event.Skip();
  }
  return;
};
*/


/*  //FIXME remove this
void
CApplication::wdelete_callback (wxCloseEvent& event)
{

       if(Application->ADestroyWindow (&event))
       {
         if (!event.CanVeto()) 
         { 
           event.Skip();
         }
         else
         {
           event.Veto(); 
         };
        }
    
};
*/


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

/*
void
eventloop (GdkEvent * event)
{
  if ((event->type == GDK_BUTTON_PRESS) || (event->type == GDK_BUTTON_RELEASE) || (event->type == GDK_KEY_PRESS) || 
      (event->type == GDK_KEY_RELEASE))
    { 
      if (Application.AEvent (gtk_get_event_widget (event), event, -1))
	{
	  gtk_main_do_event (event);
	}
    }
  else
    {
      gtk_main_do_event (event);
    };


//   if(event->type != GDK_EXPOSE)
//   {
//   if(Application.AEvent (gtk_get_event_widget(event), event, -1))
//     gtk_main_do_event(event);
//   }
//   else
//   {
//     gtk_main_do_event(event);
//     Application.AEvent (gtk_get_event_widget(event), event, -1);
//   };
 
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
//  g_thread_init (NULL);
//  gdk_threads_init ();

//  gtk_init (&argc, &argv);

//  gdk_event_handler_set ((GdkEventFunc) eventloop, NULL, NULL);

//  Tips = gtk_tooltips_new ();

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
	  //gtk_main_quit ();
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
  //gdk_threads_enter ();
  //gtk_main ();
  //gdk_threads_leave ();


  //gtk_object_destroy (GTK_OBJECT (Tips));
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


/*
bool CApplication::AEvent (wxWindow * widget,wxEvent * event, int w)
{
//FIXME rip this code out

  if ((w == -1)&&(AWindowList!= NULL))
    {
      for (int i = 0; i <= AWindowCount; i++)
	{
	  if ((AWindowList[i]->GetWWidget () == widget)
	     ||(AWindowList[i]->GetWidget () == widget))
	    {
	      w = i;
	      break;
	    }
	  else
	    {
	      if (AWindowList[i]->GetChildByWidget (widget) != NULL)
		{
		  w = i;
		  break;
		};
	    };
	};
    };

  if ((w >= 0) && (w <= AWindowCount))
  {
    //if(event->type == 4)	
    //printf("Window=%i   widget=%s  event=%i\n",w,gtk_widget_get_name(widget),event->type);	  
    return AWindowList[w]->WEvent (widget, event);
  };

  return true;
};
*/

/*
void
CApplication::ASignal (GtkWidget * widget, int signal, int w)
{
  if (w <= AWindowCount)
    AWindowList[w]->WSignal (widget, signal);
};
*/

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
CApplication::SetTitle (String title)
{
  Title = title;
};

String CApplication::GetTitle (void)
{
  return Title;
};

void
CApplication::SetTips (CControl * control)
{
  //gtk_tooltips_set_tip (Tips, control->GetWidget (), control->GetHint ().c_str (), "help");
};



