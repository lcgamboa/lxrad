/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2016  Luis Claudio Gamboa Lopes

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


#include"../include/ccolordialog.h"
#include <wx/colordlg.h>

// CColorDialog__________________________________________________________


CColorDialog::CColorDialog (void)
{
//  CanFocus = false;
  CanVisible = false;
  Color.SetRGB (0);
  SetVisible (false);
  SetName (wxT("ColorDialog"));
  SetClass (wxT("CColorDialog"));
  CanExecuteEvent=false;
};


CColorDialog::~CColorDialog (void)
{
};

int
CColorDialog::Create (CControl * control)
{
    
  Widget=NULL; 

  return CControl::Create (control);
};

String
CColorDialog::GetColorName (void)
{
   wxColourDatabase CB;
   return CB.FindName (Color);
};


void
CColorDialog::SetColorName (String cname)
{
  wxColourDatabase CB;
  
  Color=CB.Find(cname.c_str ());
};



bool
CColorDialog::Run (void)
{
  int run;
  
   wxColourData cdata;
   
   cdata.SetColour (Color);

  Widget =  new wxColourDialog(((CWindow *)GetOwner())->GetWWidget (), &cdata);


  switch(((wxColourDialog*)Widget)->ShowModal())
    {
    case wxID_OK :
      run= 1;
      Color=((wxColourDialog*)Widget)->GetColourData().GetColour ();	
      break;
    default:
      run= 0;
      break;
    };
    
  delete Widget;

  Widget=NULL; 

return run;
};


CStringList CColorDialog::GetContext (void)
{
//  CControl::GetContext ();
  CObject::GetContext ();
  Context.AddLine (xml_out (wxT("ColorName"), wxT("String"), GetColorName()));
  return Context;
};

void
CColorDialog::SetContext (CStringList context)
{
  String name, type, value;
//  CControl::SetContext (context);
  CObject::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("ColorName")) == 0)
      	SetColorName(value);
    };
};
  
  
wxColor 
CColorDialog::GetColor(void)
{
  return Color;
};


void 
CColorDialog::SetColor(wxColor c)
{
  Color=c;
};
  

void
CColorDialog::SetColor (uint r, uint g, uint b)
{
 Color.Set(r,g,b);

}




