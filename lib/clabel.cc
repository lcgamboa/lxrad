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

#include"../include/clabel.h"

// CLabel _________________________________________________________________

class wxClickText : public wxStaticText
{
public:
wxClickText(wxWindow *parent, wxWindowID id, const wxString &label,
const wxPoint &pos = wxDefaultPosition, const wxSize
&size = wxDefaultSize, int style = 0, const wxString& name =
"staticText");
virtual ~wxClickText();
void OnMouseEvent( wxMouseEvent& event );
DECLARE_EVENT_TABLE()

};

BEGIN_EVENT_TABLE( wxClickText, wxStaticText )
EVT_LEFT_DOWN(wxClickText::OnMouseEvent)
END_EVENT_TABLE()

wxClickText::wxClickText(wxWindow *parent, wxWindowID id, const
wxString &label, const wxPoint &pos , const wxSize &size , int style , const wxString& name): 
wxStaticText(parent, id, label, pos, size, style/*|wxPOPUP_WINDOW*/, name)
{}

wxClickText::~wxClickText(){}

void wxClickText::OnMouseEvent( wxMouseEvent& event )
{
  wxCommandEvent myevent(wxEVT_COMMAND_BUTTON_CLICKED, GetId());
  wxPostEvent(this, myevent);
}

//CLabel


CLabel::CLabel (void)
{
  CanFocus = false;
  CanExecuteEvent = false;
  X = 0;
  Y = 0;
  Width = 60;
  Height = 20;
  Text = wxT("Label");
  SetClass (wxT("CLabel"));
  SetAlign (CA_LEFT);
};


CLabel::~CLabel (void)
{
};

int
CLabel::Create (CControl * control)
{
unsigned int flags=0;

    switch(Align)
    {
      case CA_RIGHT:
        flags=wxST_NO_AUTORESIZE | wxALIGN_RIGHT;
        break;
      case CA_LEFT:
        flags=wxST_NO_AUTORESIZE | wxALIGN_LEFT;
        break;
      case CA_CENTER:
        flags=wxST_NO_AUTORESIZE | wxALIGN_CENTRE;
        break;
      case CA_FILL:
        flags=wxST_NO_AUTORESIZE | wxALIGN_CENTRE;
        break;
    } 

  Widget = new wxClickText(control->GetWidget (),GetWid(),Text,wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),flags,GetName());

  Widget->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &CControl::Event,this,GetWid()); 
  
  SetAlign (Align);
  return CControl::Create (control);
};



CStringList
CLabel::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("Text"), wxT("String"), GetText ()));
  Context.AddLine (xml_out (wxT("Align"), wxT("CAlign"), itoa (GetAlign ())));
  return Context;
};

void
CLabel::SetContext (CStringList context)
{
  String name, type, value;

  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Text")) == 0)
	SetText (value);
      if (name.compare (wxT("Align")) == 0)
	SetAlign (CAlign (atoi (value)));
    };
};

//propierties
void
CLabel::SetText (String text)
{
  Text = text;
  if (Widget != NULL)
   ((wxClickText*)Widget)->SetLabel(Text);
};

String
CLabel::GetText (void)
{
//  if (Widget != NULL)
//    Text = LocaleFromUtf8 (gtk_label_get_text (GTK_LABEL (Label)));
  return Text;
};

void
CLabel::SetAlign (CAlign align)
{
  Align = align;
  if (Widget != NULL)
  {
    switch(Align)
    {
      case CA_RIGHT:
        ((wxClickText*)Widget)->SetWindowStyle(wxST_NO_AUTORESIZE | wxALIGN_RIGHT);
        break;
      case CA_LEFT:
        ((wxClickText*)Widget)->SetWindowStyle(wxST_NO_AUTORESIZE | wxALIGN_LEFT);
        break;
      case CA_CENTER:
        ((wxClickText*)Widget)->SetWindowStyle(wxST_NO_AUTORESIZE | wxALIGN_CENTRE);
        break;
      case CA_FILL:
        ((wxClickText*)Widget)->SetWindowStyle(wxST_NO_AUTORESIZE | wxALIGN_CENTRE);
        break;
    } 
  }

};

CAlign CLabel::GetAlign (void)
{
//  if (Widget != NULL)
//    Align = (CAlign) gtk_label_get_justify (GTK_LABEL (Label));
  return Align;
};


void
CLabel::SetWidth (uint w)
{
  Width = w;
  if ((Widget != NULL)&& (CanVisible == true))
  {
       Widget->SetSize(X,Y,Width,Height,wxSIZE_USE_EXISTING);
       ((wxClickText*)Widget)->Wrap(Width);
  }
};


void
CLabel::SetColorName (const String name)
{
  ColorName = name;
  
  wxColour color(name);
  if (Widget != NULL)
  {
     ((wxClickText*)Widget)->SetForegroundColour(color);
     ((wxClickText*)Widget)->Refresh();
  }
};

void 
CLabel::SetColor (unsigned r, unsigned g, unsigned b)
{
  ColorRGB[0]=r;
  ColorRGB[1]=g;
  ColorRGB[2]=b;

  wxColour color(r,g,b);
  if (Widget != NULL)
  {
     ((wxClickText*)Widget)->SetForegroundColour(color);
     ((wxClickText*)Widget)->Refresh();
  }
};

void
CLabel::SetColor (wxColor color)
{ 
  ColorRGB[0]=color.Red ();
  ColorRGB[1]=color.Green ();
  ColorRGB[2]=color.Blue ();

  if (Widget != NULL)
  {
     ((wxClickText*)Widget)->SetForegroundColour(color);
     ((wxClickText*)Widget)->Refresh();
  }
};


