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

#include"../include/cedit.h"

// CEdit_____________________________________________________________

CEdit::CEdit (void)
{
  Text = wxT("");
  SetX (10);
  SetY (10);
  SetWidth (80);
  SetHeight (26);
  SetReadOnly (false);
  SetMaxLenght (255);
  SetClass (wxT("CEdit"));
};


CEdit::~CEdit (void)
{
};

int
CEdit::Create (CControl * control)
{

   Widget = new wxTextCtrl(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxTE_PROCESS_ENTER,wxDefaultValidator,GetName());

  SetReadOnly (ReadOnly);

return CControl::Create (control);
};


lxStringList
CEdit::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("lxString"), GetText ()));
  Context.AddLine (xml_out (wxT("ReadOnly"), wxT("int"), itoa(GetReadOnly ())));
  return Context;
};

void
CEdit::SetContext (lxStringList context)
{
  lxString name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("ReadOnly")) == 0)
	SetReadOnly (atoi(value));
    };
};


//propriedades

void
CEdit::SetText (lxString t)
{
  Text = t;
  if (Widget != NULL)
    ((wxTextCtrl*)Widget)->SetValue(Text);
};

lxString
CEdit::GetText (void)
{
  if (Widget != NULL)
    Text =  ((wxTextCtrl*)Widget)->GetValue();
  return Text;
};

void
CEdit::SetReadOnly (bool r)
{
  ReadOnly = r;
  if (Widget != NULL)
      ((wxTextCtrl*)Widget)->SetEditable(!r);
};

bool
CEdit::GetReadOnly (void)
{
  return ReadOnly;
};

void
CEdit::SetMaxLenght (int l)
{
  MaxLenght = l;
  if (Widget != NULL)
    ((wxTextCtrl*)Widget)->SetMaxLength(l);
};

int
CEdit::GetMaxLenght (void)
{
  return MaxLenght;
};


void
CEdit::SetAlign (CAlign align)
{
  Align = align;

#ifdef _DEBUG_
  printf("incomplete:CEdit::SetAlign\n");
#endif
//  if (Widget != NULL)
//      ((wxTextCtrl*)Widget)->SetDefaultStyle(wxTE_LEFT);
};

CAlign
CEdit::GetAlign (void)
{
  return Align;
};
