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

#include"../include/ccombo.h"
#include"../include/capplication.h"

// CCombo_____________________________________________________________

CCombo::CCombo (void)
{
  Text = wxT("");
  SetClass (wxT("CCombo"));
  SetX (10);
  SetY (10);
  SetHeight (26);
  SetWidth (80);
  Items.Clear ();
  Index=-1;
  ReadOnly=false;
  EvOnComboChange = NULL;
};

CCombo::~CCombo (void)
{
};


int
CCombo::Create (CControl * control)
{

   if(ReadOnly)	
     Widget = new wxComboBox(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,NULL,wxCB_READONLY,wxDefaultValidator,GetName());
   else
     Widget = new wxComboBox(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,NULL,0,wxDefaultValidator,GetName());
	

  for (uint i = 0; i < Items.GetLinesCount (); i++)
    {
	((wxComboBox*)Widget)->Append(Items.GetLine (i));
    };

    Win = control->GetWin ();

    Widget->Bind(wxEVT_COMBOBOX,&CCombo::Event,this,GetWid()); 

return CControl::Create (control);
};

int CCombo::CEvent (int event)
{
if(event == wxEVT_COMBOBOX)return lxEVT_COMBOBOX;

return CControl::CEvent(event);
}

//FIXME clean this code
void
CCombo::Event (wxEvent & event)
{
    event.Skip();  
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_COMBOBOX:
          if(Widget)
           // Text = ((wxComboBox*)Widget)->GetValue();
	  if ((FOwner) && (EvOnComboChange))
	    (FOwner->*EvOnComboChange) (this);
//            printf("Combo Change!!!\n");
	  return;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};
};


void
CCombo::AddItem (lxString text)
{
  Items.AddLine (text);

  if (Widget != NULL)
    {
   ((wxComboBox*)Widget)->Append(text);
    };
};

void
CCombo::LoadItemsFromFile (lxString fname)
{
  DeleteItems ();
  Items.LoadFromFile (fname);

  for (uint i = 0; i < Items.GetLinesCount (); i++)
    {
      ((wxListBox *)Widget)->Append(Items.GetLine (i));
    };

  Draw ();
};

void
CCombo::SaveItemsToFile (lxString fname)
{
  Items.SaveToFile (fname);
};

lxString CCombo::GetItem (int item)
{
  return Items.GetLine (item);
};

void
CCombo::SetSelectedItem (lxString item)
{
  if (Widget != NULL)
  {
       ((wxComboBox*)Widget)->SetValue(item);
  }
};

lxString CCombo::GetSelectedItem (void)
{
  if (Widget != NULL)
  {
    Text = ((wxComboBox*)Widget)->GetValue();
  }

  return Text;
};

int CCombo::GetSelectedItemIndex (void)
{
  if (Widget != NULL)
  {
    Index = ((wxComboBox*)Widget)->GetSelection();
  }

  return Index;
};


int
CCombo::GetItemsCount (void)
{
  return Items.GetLinesCount ();
};

void
CCombo::DeleteItem (int item)
{

  Items.DelLine (item);

  if (Widget != NULL)
    {
       ((wxComboBox*)Widget)->Delete(item);     
    };
 
};

void
CCombo::DeleteItems (bool clean)
{
  if(clean)
  {
  Items.Clear ();
  if (Widget != NULL)
  {
     ((wxComboBox*)Widget)->Clear();
     //((wxComboBox*)Widget)->SetValue(Text);
  };  
  };
};

lxStringList CCombo::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Items"), wxT("lxStringList"), GetItems ()));
  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"), GetText ()));
  Context.AddLine (xml_out (wxT("ReadOnly"), wxT("bool"), itoa(GetReadOnly ())));
  Context.AddLine (xml_out (wxT("EvOnComboChange"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CCombo::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("Items")) == 0)
	SetItems (value);
      if (name.compare (wxT("ReadOnly")) == 0)
	SetReadOnly (atoi(value));
      if (name.compare (wxT("EvOnComboChange")) == 0)
	SetEv (atob (value));
    };
};

void
CCombo::SetText (lxString text)
{
  Text = text;
  if (Widget != NULL)
   ((wxComboBox*)Widget)->SetValue(text);
};

lxString CCombo::GetText (void)
{
  if (Widget != NULL)
    Text =    ((wxComboBox*)Widget)->GetValue();

  return Text;
};

void
CCombo::SetItems (lxString litems)
{
  int f = 0;
  DeleteItems (1);
  while (litems.size () > 0)
    {
      f = litems.find (wxT(","));
      if(f < 0)break;
      AddItem (litems.substr (0, f));
      litems = litems.substr (f + 1, litems.size () - f - 1);
    };
  Draw ();
};

lxString CCombo::GetItems (void)
{
  lxString list = wxT("");
  for (uint c = 0; c < Items.GetLinesCount (); c++)
    {
      list += Items.GetLine (c) + wxT(",");
    };
  return list;
};


void
CCombo::SetReadOnly (bool r)
{
  ReadOnly = r;
  if (Widget != NULL)
      ((wxComboBox*)Widget)->SetEditable(!r);
};

bool
CCombo::GetReadOnly (void)
{
  return ReadOnly;
};
