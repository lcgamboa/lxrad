/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2015-2016  Luis Claudio Gamboa Lopes

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
#include"../include/cthread.h"


//Thread Stuff

class lxThread : public wxThread
{
    public:
        lxThread(wxEvtHandler* pParent, CThread * th);
	~lxThread();
    private:
        CThread * thread;
        void* Entry();
    protected:
        wxEvtHandler* m_pParent;
};

DEFINE_EVENT_TYPE(wxEVT_LXTHREAD_END)

lxThread::lxThread(wxEvtHandler* pParent, CThread * th) : wxThread(wxTHREAD_DETACHED), m_pParent(pParent)
{
  thread = th;
}

lxThread::~lxThread()
{
  thread = NULL;
}

void* lxThread::Entry()
{   
    ((thread->GetFOwner())->*thread->EvThreadRun) (thread); 

    
    wxCommandEvent evt(wxEVT_LXTHREAD_END, GetId());
    //evt.SetInt(r); 
    //evt.SetClientData(data); 
    wxPostEvent(m_pParent, evt);
    
    thread->SetRunState(0);
    return 0;
}


// CThread___________________________________________________________

CThread::CThread (void)
{
  Thread=NULL;	
  CanFocus = false;
  CanVisible = false;
  SetClass (wxT("CThread"));
  runstate = false;
  SetVisible (false);
  EvThreadRun = NULL;
  EvThreadEnd = NULL;
};

CThread::~CThread (void)
{
};

int
CThread::Create (CControl * control)
{
  control->GetWin()->GetWWidget()->Bind(wxEVT_LXTHREAD_END,(void (CThread::*)(wxEvent &)) &CThread::Event,this,wxID_ANY); 

  Win = control->GetWin ();

  CanExecuteEvent=false;
  CControl::Create (control);
  CanExecuteEvent=true;

  return 0;
};

void
CThread::Destroy (void)
{
  //if(Thread) Thread->Delete();
  tdestroy=1;
  while(runstate) 
  {
#ifndef __WXMSW__
      usleep(100);
#else
      Sleep(1);
#endif 
  }      
  CControl::Destroy ();
  Thread=NULL;
};

void
CThread::Kill (void)
{
  if(Thread) Thread->Kill();
};

bool
CThread::GetRunState (void)
{
  return runstate;
}

void
CThread::SetRunState (bool rs)
{
  runstate=rs;
}


bool
CThread::TestDestroy (void)
{
/*	
  if(Thread) 
    return Thread->TestDestroy();
  else
    return 1;	  
*/
  return tdestroy;	
};

int CThread::CEvent (int event)
{
  if(event == wxEVT_LXTHREAD_END)return lxEVT_THREAD_END;
  return CControl::CEvent(event);
}

int CThread::Run (void)
{
 
  if ((FOwner) && (EvThreadRun)&&(Application->GetRun()))
     { 
       if(!runstate)
       {
       //create the thread
         Thread = new lxThread(this->GetWin()->GetWWidget(), this);
         Thread->Create();
         Thread->Run();
         runstate=1;
	 tdestroy=0;
         return 0;  
       }
       else
        return 1;
    }

   return 1;
}

  
void 
CThread::Event (wxCommandEvent & te)
{
  te.Skip();
  if ((FOwner) && (EvThreadEnd)&&(Application->GetRun()))
     { 
       (FOwner->*EvThreadEnd) (this);
       Thread=NULL;
     }
};


CStringList
CThread::GetContext (void)
{
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("EvThreadRun"), wxT("Event"), btoa (GetEv (true))));
  Context.AddLine (xml_out (wxT("EvThreadEnd"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CThread::SetContext (CStringList context)
{
  String name, type, value;

//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("EvThreadRun")) == 0)
	SetEv (atob (value),true);
      if (name.compare (wxT("EvThreadEnd")) == 0)
	SetEv (atob (value),false);

    };
};

void
CThread::SetName (const String name)
{
  Name = name;
};



