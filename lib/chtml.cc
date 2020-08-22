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

#include"../include/chtml.h"
#include <wx/htmllbox.h>



// CHtml___________________________________________________________

CHtml::CHtml (void)
{
  Url=wxT("");
  File=wxT("");
  Text=wxT("");
  SetX (10);
  SetY (10);
  SetWidth (160);
  SetHeight (130);
  SetClass (wxT("CHtml"));
  EvOnLinkClicked = NULL;
};

CHtml::~CHtml (void)
{
};


int
CHtml::Create (CControl * control)
{
  Win = control->GetWin ();
  

  Widget = new wxHtmlWindow(control->GetWidget (),GetWid(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()),wxHW_DEFAULT_STYLE,control->GetName ());
    
  Widget->Bind(wxEVT_COMMAND_HTML_LINK_CLICKED,&CHtml::Event,this,GetWid()); 

  if(Url.size() > 0)
  {
    SetLoadUrl(Url);
  }
  else if(File.size() > 0)
  {
    SetLoadFile(File);
  }
  else if(Text.size() > 0)
  {
    SetLoadText(Text);
  }
 
  int ret= CControl::Create (control);
    
  Widget->Unbind(wxEVT_PAINT,&CControl::Event,this,GetWid());

  return ret;
};


int CHtml::CEvent (int event)
{
if(event == wxEVT_COMMAND_HTML_LINK_CLICKED)return lxEVT_HTML_LINK_CLICKED;

return CControl::CEvent(event);
}

#ifdef __WXMSW__
#include"wx/msw/private.h"
#endif

//FIXME clean this code
void
CHtml::Event (wxEvent & event)
{
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_HTML_LINK_CLICKED:
	  if ((FOwner) && (EvOnLinkClicked))
	    (FOwner->*EvOnLinkClicked) (this);
	 if(((wxHtmlLinkEvent*) &event)->GetLinkInfo().GetHref().StartsWith(_T("http://"))||
	 ((wxHtmlLinkEvent*) &event)->GetLinkInfo().GetHref().StartsWith(_T("https://")))
         {
	    wxLaunchDefaultBrowser(((wxHtmlLinkEvent*)&event)->GetLinkInfo().GetHref());
            return; 
         }
         if(((wxHtmlLinkEvent*)&event)->GetLinkInfo().GetTarget() == wxT("_blank"))
         {
#ifdef __WXMSW__
  //FIXME testing on windows           
  wxlxString url(dirname(((wxHtmlWindow *)Widget)->GetOpenedPage())+(((wxHtmlLinkEvent*)&event)->GetLinkInfo().GetHref()));

     
   url.Replace("%3A",":");
   url.Replace("%3a",":");

  
   int val= url.find(wxT("../"));

   if(val > 0)
   {
     wxlxString url2,url3;
     int val2=url.rfind("/",val-2);

     url3=(((wxHtmlLinkEvent*)&event)->GetLinkInfo().GetHref());
     int val3=url3.rfind(wxT("../"));
   
     url2=url.substr(0,val2+1)+url3.substr(val3+3,url3.size());
     url=url2;
   }

//   printf("url=(%s)\n",(char *)url.char_str());

   WinStruct<SHELLEXECUTEINFO> sei;
    sei.lpFile = url.c_str();
    sei.lpVerb = _T("open");
    sei.nShow = SW_SHOWNORMAL;
//  sei.fMask = SEE_MASK_FLAG_NO_UI; // we give error message ourselves

    ::ShellExecuteEx(&sei);
#else     

    wxLaunchDefaultBrowser(dirname(((wxHtmlWindow *)Widget)->GetOpenedPage())+(((wxHtmlLinkEvent*)&event)->GetLinkInfo().GetHref()));
#endif
         return;
         }
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};

   event.Skip();
};


lxStringList
CHtml::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("LoadText"), wxT("lxString"), GetLoadText ()));
  Context.AddLine (xml_out (wxT("LoadUrl"), wxT("lxString"), GetLoadUrl ()));
  Context.AddLine (xml_out (wxT("LoadFile"), wxT("File"), GetLoadFile ()));
  Context.AddLine (xml_out (wxT("EvOnLinkClicked"), wxT("Event"), btoa (GetEv ())));

  return Context;
};

void
CHtml::SetContext (lxStringList context)
{
  lxString name, type, value;
  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("LoadText")) == 0)
	SetLoadText (value);
      if (name.compare (wxT("LoadUrl")) == 0)
	SetLoadUrl (value);
      if (name.compare (wxT("LoadFile")) == 0)
	SetLoadFile (value);
      if (name.compare (wxT("EvOnLinkClicked")) == 0)
	SetEv (atob (value));
    };
};

//propiedades
void
CHtml::SetLoadText (lxString t)
{
  if(t.size() > 0)
  {
  Url=wxT("");
  File=wxT("");
  Text=t;
  if (Widget != NULL)
     ((wxHtmlWindow *)Widget)-> SetPage(Text);
  }  
};

lxString
CHtml::GetLoadText (void)
{
  return Text;
};

void
CHtml::SetLoadUrl (lxString t)
{
  if(t.size() > 0)
  {
  Url=t;
  File=wxT("");
  Text=wxT("");
  if (Widget != NULL)
     ((wxHtmlWindow *)Widget)->LoadPage(Url);
  }
};

lxString
CHtml::GetLoadUrl (void)
{
  return Url;
};

void
CHtml::SetLoadFile (lxString t)
{
  if(t.size() > 0)
  {
  Url=wxT("");
  File=t;
  Text=wxT("");
  if (Widget != NULL)
     ((wxHtmlWindow *)Widget)->LoadFile(File);
  }
};

lxString
CHtml::GetLoadFile (void)
{
  return File;
};
  
void 
CHtml::HistoryBack(void)
{
  if (Widget != NULL)
    ((wxHtmlWindow*)Widget)->HistoryBack();
}

void 
CHtml::HistoryForward(void)
{
  if (Widget != NULL)
    ((wxHtmlWindow*)Widget)->HistoryForward();

}
