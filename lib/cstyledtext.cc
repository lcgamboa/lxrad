/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2018 Luis Claudio Gamboa Lopes

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


#include"../include/cstyledtext.h"
#include <wx/stc/stc.h>

//CStyledText----------------------------------------------------------------

CStyledText::CStyledText (void)
{
  X = 10;
  Y = 10;
  Width = 100;
  Height = 100;
  SetClass (wxT("CStyledText"));
  SetReadOnly (false);
};

CStyledText::~CStyledText (void)
{
};

int
CStyledText::Create (CControl * control)
{

   Widget = new wxStyledTextCtrl(control->GetWidget (),GetWid(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxTE_MULTILINE,GetName());

  ((wxStyledTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
  SetReadOnly (ReadOnly);

  return CControl::Create (control);
};

CStringList
CStyledText::GetContext (void)
{
  CControl::GetContext ();
//  Context.AddLine (xml_out (wxT("Text"), wxT("String"), GetText ()));
  Context.AddLine (xml_out (wxT("ReadOnly"), wxT("int"), itoa(GetReadOnly ())));
  return Context;
};

void
CStyledText::SetContext (CStringList context)
{
  String name, type, value;

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
CStyledText::Clear (void)
{
  Lines.Clear ();


  if (Widget != NULL)
    {
      ((wxStyledTextCtrl*)Widget)->ClearAll();
    };

};

void
CStyledText::AddLine (String line)
{
  Lines.AddLine (line);
  if (Widget != NULL)
       ((wxStyledTextCtrl*)Widget)->AppendText(line.c_str());
  
  Draw ();
};

void
CStyledText::InsertLine (String line, int ln)
{
  Lines.InsertLine (line, ln);
  if (Widget != NULL)
  {
       ((wxStyledTextCtrl*)Widget)->ClearAll();
       ((wxStyledTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
  };
  Draw ();
};

void
CStyledText::DelLine (int ln)
{
  Lines.DelLine (ln);
  if (Widget != NULL)
  {
       ((wxStyledTextCtrl*)Widget)->ClearAll();
       ((wxStyledTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
  }
  Draw ();
};

void
CStyledText::LoadFromFile (String fname)
{
  if (Widget != NULL)
    {
      Clear ();
      Lines.LoadFromFile (fname);
       ((wxStyledTextCtrl*)Widget)->ClearAll();
       ((wxStyledTextCtrl*)Widget)->WriteText (Lines.GetBuffer ().c_str ());
    }
  else
    {
      Lines.LoadFromFile (fname);
    };
};

void
CStyledText::SaveToFile (String fname)
{
  if (Widget != NULL)
    {
      Lines.SetBuffer (((wxStyledTextCtrl*)Widget)->GetValue().c_str() );
    };
  Lines.SaveToFile (fname);
};

//propiedades
uint
CStyledText::GetCountLines (void)
{
  return Lines.GetLinesCount ();
};

void
CStyledText::SetReadOnly (bool r)
{
  ReadOnly = r;
  if (Widget != NULL)
      ((wxStyledTextCtrl*)Widget)->SetEditable(!r);
};

bool
CStyledText::GetReadOnly (void)
{
  return ReadOnly;
};

