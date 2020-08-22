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


#include"../include/cfilelist.h"
#include"../include/capplication.h"
#include<wx/generic/dirctrlg.h> 

// CFileList_____________________________________________________________

CFileList::CFileList (void)
{
  SetX (10);
  SetY (10);
  SetWidth (160);
  SetHeight (130);
  SetClass (wxT("CFileList"));
  EvFileListSelectDir = NULL;
  EvFileListSelectFile = NULL;
  DefaultDir = wxT(".");
};


int
CFileList::Create (CControl * control)
{
	Widget = new wxGenericDirCtrl(control->GetWidget (),GetWid(),DefaultDir,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,wxEmptyString,0,GetName());

        Win = control->GetWin ();

        //Widget->Connect(((wxGenericDirCtrl*)Widget)->GetTreeCtrl()->GetId(),wxEVT_COMMAND_TREE_ITEM_ACTIVATED,(wxObjectEventFunction)&CApplication::events_callback);
        Widget->Bind(wxEVT_COMMAND_TREE_ITEM_ACTIVATED,&CFileList::Event,this,((wxGenericDirCtrl*)Widget)->GetTreeCtrl()->GetId()); 

      return CControl::Create (control);
};

CControl *
CFileList::GetChildByWidget (wxWindow * widget)
{
  if(Widget)
  {
  if (((wxGenericDirCtrl*)Widget)->GetTreeCtrl() == widget)
      return this;
  }

  return CControl::GetChildByWidget (widget);

};

int CFileList::CEvent (int event)
{
if(event == wxEVT_COMMAND_TREE_ITEM_ACTIVATED)return lxEVT_COMMAND_TREE_ITEM_ACTIVATED;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CFileList::Event (wxEvent & event)
{
        event.Skip();

//  if ((Widget == widget)||(((wxGenericDirCtrl*)Widget)->GetTreeCtrl()->GetId() == event->GetId()))
//    {
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_COMMAND_TREE_ITEM_ACTIVATED:

        	if(GetSelectedDir() == GetSelectedFile())
		{
			if ((FOwner) && (EvFileListSelectFile))
	    			(FOwner->*EvFileListSelectFile) (this);
		}
		else
		{
			if ((FOwner) && (EvFileListSelectDir))
	    			(FOwner->*EvFileListSelectDir) (this);
	    	}
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};



void
CFileList::SetDir (lxString dir)
{
  DefaultDir = dir;
  if (Widget != NULL)
    {
       ((wxGenericDirCtrl*)Widget)->SetDefaultPath(DefaultDir); 
    };
};

lxString CFileList::GetSelectedDir (void)
{

  if(Widget)
    return ((wxGenericDirCtrl*)Widget)->GetFilePath(); 
 else
    return wxT("");
};

lxString CFileList::GetSelectedFile (void)
{
  
  if(Widget)
    return ((wxGenericDirCtrl*)Widget)->GetPath(); 
  else
    return wxT("");
};


lxStringList CFileList::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Dir"), wxT("lxStringList"), DefaultDir));
  Context.AddLine (xml_out (wxT("EvFileListSelectDir"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvFileListSelectFile"), wxT("Event"), btoa (GetEv ())));
  return Context;
};


void
CFileList::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);

      if (name.compare (wxT("Dir")) == 0)
	SetDir (value);
      if (name.compare (wxT("EvFileListSelectDir")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvFileListSelectFile")) == 0)
	SetEv (atob (value));
    };
};
