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

#include"../include/cstatusbar.h"



// CStatusbar___________________________________________________________

CStatusbar::CStatusbar (void)
{
  CanVisible = 0;
  Fields.Clear ();
  Fields.AddLine (wxT(""));
  CanFocus = false;
  CanExecuteEvent = false;
  SetClass (wxT("CStatusbar"));
};

CStatusbar::~CStatusbar (void)
{
};


int
CStatusbar::Create (CControl * control)
{
  

  SetOwner (control);
  Win = control->GetWin ();

   Widget = new wxStatusBar(((wxFrame*)((CWindow* )control)->GetWWidget()),GetWid(),0,control->GetName ());

   CControl::Create (control);
  
   ((wxFrame*)((CWindow* )control)->GetWWidget())->SetStatusBar((wxStatusBar*)Widget);

//   ((wxStatusBar *)Widget)->SetStatusText(wxT("StatusBar test"), 0);
//SetFieldsCount(int number = 1, int* widths = NULL)
//GetStatusText(int i = 0)
//SetStatusText(const wxString& text, int i = 0)

  ((wxStatusBar *)Widget)->SetFieldsCount( Fields.GetLinesCount ());
  for (uint i = 0; i < Fields.GetLinesCount (); i++)
    {
      ((wxStatusBar *)Widget)->SetStatusText(Fields.GetLine (i),i);
    };

  return 0;
};


CStringList
CStatusbar::GetContext (void)
{
//  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("Fields"), wxT("StringList"), GetFields ()));

  return Context;
};

void
CStatusbar::SetContext (CStringList context)
{
  String name, type, value;
//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Fields")) == 0)
	SetFields (value);
    };
};

//propiedades
void
CStatusbar::SetFields (String litems)
{
  int f = 0;
  Fields.Clear ();
  while (litems.size () > 0)
    {
      f = litems.find (wxT(","));
      if(f < 0)break;
      AddField (litems.substr (0, f));
      litems = litems.substr (f + 1, litems.size () - f -1);
    };
//  Draw ();
};

String 
CStatusbar::GetFields (void)
{
  String list = wxT("");
  for (uint c = 0; c < Fields.GetLinesCount (); c++)
    {
      list += Fields.GetLine (c) + wxT(",");
    };
  return list;
};

String
CStatusbar::GetField (int item)
{
  if (item < (int) Fields.GetLinesCount ())
    return Fields.GetLine (item);
  else
    return wxT('\0');
};

void
CStatusbar::SetField (int item, String sitem)
{
  if (item < (int) Fields.GetLinesCount ())
  {
    Fields.SetLine (sitem, item);
    if (Widget != NULL)
      ((wxStatusBar *)Widget)->SetStatusText(sitem,item);
  }
};

void
CStatusbar::AddField (String text)
{
  Fields.AddLine (text);

  if (Widget != NULL)
    {
      ((wxStatusBar *)Widget)->SetFieldsCount(Fields.GetLinesCount ());
      ((wxStatusBar *)Widget)->SetStatusText(text,Fields.GetLinesCount ()-1);
    };

};

int
CStatusbar::GetFieldsCount (void)
{
  return Fields.GetLinesCount ();
};

