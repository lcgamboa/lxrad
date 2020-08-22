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

#include"../include/clist.h"
#include"../include/capplication.h"

// CList_____________________________________________________________

CList::CList (void)
{
  ItemsList.Clear ();
  SetX (10);
  SetY (10);
  SetWidth (160);
  SetHeight (130);
  SetClass (wxT("CList"));
  SelectedItem = 0;
  Sort = false;
  
  EvListSelect = NULL;
  EvListDoubleClick = NULL;

};


CList::~CList (void)
{
};

int
CList::Create (CControl * control)
{
	Widget = new wxListBox(control->GetWidget (),GetWid(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),0,0,0,wxDefaultValidator,GetName());


  for (uint i = 0; i < ItemsList.GetLinesCount (); i++)
    {
      ((wxListBox *)Widget)->Append((ItemsList.GetLine (i)));
    };

  SetSort (Sort);

  Win = control->GetWin ();
  

   Widget->Bind(wxEVT_COMMAND_LISTBOX_SELECTED,&CList::Event,this,GetWid()); 
   Widget->Bind(wxEVT_COMMAND_LISTBOX_DOUBLECLICKED,&CList::Event,this,GetWid()); 

  return CControl::Create (control);
};

int CList::CEvent (int event)
{
if(event == wxEVT_COMMAND_LISTBOX_SELECTED)return lxEVT_COMMAND_LISTBOX_SELECTED;
if(event == wxEVT_COMMAND_LISTBOX_DOUBLECLICKED)return lxEVT_COMMAND_LISTBOX_DOUBLECLICKED;

return CControl::CEvent(event);
}

//FIXME clean this code
void
CList::Event (wxEvent & event)
{
    event.Skip();
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_COMMAND_LISTBOX_SELECTED:
	  if ((FOwner) && (EvListSelect))
	    (FOwner->*EvListSelect) (this);
	  return;
	  break;
	case lxEVT_COMMAND_LISTBOX_DOUBLECLICKED:
	  if ((FOwner) && (EvListDoubleClick))
	    (FOwner->*EvListDoubleClick) (this);
	  return;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};

};


void
CList::SetSort (bool sort)
{
  Sort = sort;
  if (Widget != NULL)
    {
      if (sort);
	//gtk_tree_sortable_set_sort_column_id (GTK_TREE_SORTABLE (Store), 0, GTK_SORT_ASCENDING);
        
	//wxLB_SORT
     };
};

bool CList::GetSort (void)
{
  return Sort;
};

lxStringList CList::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Items"), wxT("lxStringList"), GetItems ()));
  Context.AddLine (xml_out (wxT("EvListSelect"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvListDoubleClick"), wxT("Event"), btoa (GetEv ())));
  return Context;
};

void
CList::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);

      if (name.compare (wxT("Items")) == 0)
	SetItems (value);
      if (name.compare (wxT("EvListSelect")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvListDoubleClick")) == 0)
	SetEv (atob (value));
    };
};


//propriedades

void
CList::SetItems (lxString litems)
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

lxString CList::GetItems (void)
{
  lxString list = wxT("");
  for (uint c = 0; c < ItemsList.GetLinesCount (); c++)
    {
      list += ItemsList.GetLine (c) + wxT(",");
    };
  return list;
};

void
CList::AddItem (lxString text)
{
  if (Widget != NULL)
    {
      ((wxListBox *)Widget)->Append(text);
    };

  ItemsList.AddLine (text);
};

lxString
CList::GetItem (int item)
{
  if (item < (int) ItemsList.GetLinesCount ())
    return ItemsList.GetLine (item);
  else
    return wxT('\0');
};

void
CList::SetItem (int item, lxString sitem)
{
  if (item < (int) ItemsList.GetLinesCount ())
    ItemsList.SetLine (sitem, item);
};

void
CList::SetSelectedItemN (int item)
{
  SelectedItem = item;
  if (ItemsList.GetLinesCount () != 0)
    {
      Draw ();
    };
  //change_item ();
};

void
CList::SetSelectedItem (lxString item)
{

  for (uint c = 0; c < ItemsList.GetLinesCount (); c++)
    {
      if (ItemsList.GetLine (c).compare (item) == 0)
	{
	  SelectedItem = c;
	  if (ItemsList.GetLinesCount () != 0)
	    {
	      Draw ();
	    };
	  //change_item ();

	  break;
	};
    };
};

int
CList::GetSelectedItemN (void)
{
  if (Widget != NULL)
    {
       return ((wxListBox *)Widget)->GetSelection();
    };

  return wxNOT_FOUND;
};

lxString
CList::GetSelectedItem (void)
{
int i ;

  if ((i=GetSelectedItemN())!= wxNOT_FOUND)
    {
	  return ((wxListBox *)Widget)->GetString(i);
    };

  return wxT("");
};

int
CList::GetItemsCount (void)
{
  return ItemsList.GetLinesCount ();
};

void
CList::DeleteItem (int item)
{
  if (item >= 0)
    {
      ItemsList.DelLine (item);

      if(Widget)
          ((wxListBox *)Widget)->Delete(item); 
    };
};

void
CList::DeleteItems (bool clean)
{
  if (clean)
    {
      ItemsList.Clear ();
      SelectedItem = -1;

      if(Widget)
          ((wxListBox *)Widget)->Clear(); 
    };
};

void
CList::LoadItemsFromFile (lxString fname)
{
  DeleteItems ();
  ItemsList.LoadFromFile (fname);

  for (uint i = 0; i < ItemsList.GetLinesCount (); i++)
    {
      ((wxListBox *)Widget)->Append(ItemsList.GetLine (i));
    };

  Draw ();
};

void
CList::SaveItemsToFile (lxString fname)
{
  ItemsList.SaveToFile (fname);
};

void
CList::SetShowSelection (bool show)
{
  ShowSelection = show;
  Draw ();
};

bool
CList::GetShowSelection (void)
{
  return ShowSelection;
};
