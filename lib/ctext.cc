/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001 Luis Claudio Gamboa Lopes

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


#include"../include/ctext.h"

//CText----------------------------------------------------------------

CText::CText (void)
{
  X = 10;
  Y = 10;
  Width = 100;
  Height = 100;
  SetClass (wxT("CText"));
  SetReadOnly (false);
};

CText::~CText (void)
{
};

int
CText::Create (CControl * control)
{

   Widget = new wxTextCtrl(control->GetWidget (),GetWid(),Lines.GetBuffer(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxTE_MULTILINE,wxDefaultValidator,GetName());
  
  SetReadOnly (ReadOnly);

  return CControl::Create (control);
};

lxStringList
CText::GetContext (void)
{
  CControl::GetContext ();
//  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"), GetText ()));
  Context.AddLine (xml_out (wxT("ReadOnly"), wxT("int"), itoa(GetReadOnly ())));
  return Context;
};

void
CText::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
//      if (name.compare (wxT("Text")) == 0)
//	SetText (value);
      if (name.compare (wxT("ReadOnly")) == 0)
	SetReadOnly (atoi(value));
    };
};

void
CText::Clear (void)
{
  Lines.Clear ();


  if (Widget != NULL)
    {
      ((wxTextCtrl*)Widget)->Clear();
    };

};

void
CText::AddLine (lxString line)
{
  Lines.AddLine (line);
  if (Widget != NULL)
       ((wxTextCtrl*)Widget)->AppendText(line.c_str());
  
  Draw ();
};

void
CText::InsertLine (lxString line, int ln)
{
  Lines.InsertLine (line, ln);
  if (Widget != NULL)
  {
       ((wxTextCtrl*)Widget)->Clear();
       ((wxTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
  };
  Draw ();
};

void
CText::DelLine (int ln)
{
  Lines.DelLine (ln);
  if (Widget != NULL)
  {
       ((wxTextCtrl*)Widget)->Clear();
       ((wxTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
  }
  Draw ();
};

void
CText::LoadFromFile (lxString fname)
{
  if (Widget != NULL)
    {
      Clear ();
      Lines.LoadFromFile (fname);
       ((wxTextCtrl*)Widget)->Clear();
       ((wxTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
    }
  else
    {
      Lines.LoadFromFile (fname);
    };
};

void
CText::SaveToFile (lxString fname)
{
  if (Widget != NULL)
    {
      Lines.SetBuffer (((wxTextCtrl*)Widget)->GetValue().c_str() );
    };
  Lines.SaveToFile (fname);
};

//propiedades
uint
CText::GetCountLines (void)
{
  return Lines.GetLinesCount ();
};

void
CText::SetReadOnly (bool r)
{
  ReadOnly = r;
  if (Widget != NULL)
      ((wxTextCtrl*)Widget)->SetEditable(!r);
};

bool
CText::GetReadOnly (void)
{
  return ReadOnly;
};

