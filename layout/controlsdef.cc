/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2010 Luis Claudio Gamboa Lopes

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


#include"../include/lxrad.h"
#include"controlsdef.h"
#include"layout1.h"

uint tbuttonc = 1;
uint ttoolbuttonc = 1;
uint txpmbuttonc = 1;
uint teditc = 1;
uint tlabelc = 1;
uint tcheckboxc = 1;
uint tdrawc = 1;
uint timagec = 1;
uint tlistc = 1;
uint tfilelistc = 1;
uint tmenuc = 1;
uint tpmenuc = 1;
uint tscrollc = 1;
uint tcomboc = 1;
uint ttextc = 1;
uint tfiledialogc = 1;
uint tdirdialogc = 1;
uint titemmenuc = 1;
uint ttimerc = 1;
uint tpanelc = 1;
uint tgaugec = 1;
uint tgridc = 1;
uint thtmlc = 1;
uint tstatusbarc = 1;

void
resetcontrolscount (void)
{
  tbuttonc = 1;
  ttoolbuttonc = 1;
  txpmbuttonc = 1;
  teditc = 1;
  tlabelc = 1;
  tcheckboxc = 1;
  tdrawc = 1;
  timagec = 1;
  tlistc = 1;
  tfilelistc = 1;
  tmenuc = 1;
  tpmenuc = 1;
  tscrollc = 1;
  tcomboc = 1;
  ttextc = 1;
  tfiledialogc = 1;
  tdirdialogc = 1;
  titemmenuc = 1;
  ttimerc = 1;
  tpanelc = 1;
  tgaugec = 1;
  tgridc = 1;
  thtmlc = 1;
  tstatusbarc = 1;
};

CControl *
newcontrol (String controltype, CControl * owner)
{
  CControl *ncontrol;
  if (controltype.compare (wxT("CButton")) == 0)
    {
      ncontrol = new CButton;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("button") + itoa (tbuttonc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CToolButton")) == 0)
    {
      ncontrol = new CToolButton;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("toolbutton") + itoa (ttoolbuttonc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CXpmButton")) == 0)
    {
      ncontrol = new CXpmButton;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("xpmbutton") + itoa (txpmbuttonc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CEdit")) == 0)
    {
      ncontrol = new CEdit;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("edit") + itoa (teditc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CLabel")) == 0)
    {
      ncontrol = new CLabel;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("label") + itoa (tlabelc++));
      ncontrol->SetCanExecuteEvent (true);
      return ncontrol;
    };
  if (controltype.compare (wxT("CCheckBox")) == 0)
    {
      ncontrol = new CCheckBox;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("checkbox") + itoa (tcheckboxc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CDraw")) == 0)
    {
      ncontrol = new CDraw;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("draw") + itoa (tdrawc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CImage")) == 0)
    {
      ncontrol = new CImage;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("image") + itoa (timagec++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CList")) == 0)
    {
      ncontrol = new CList;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("list") + itoa (tlistc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CFileList")) == 0)
    {
      ncontrol = new CFileList;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("filelist") + itoa (tfilelistc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CMenu")) == 0)
    {
      ncontrol = new CMenu;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("menu") + itoa (tmenuc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CPMenu")) == 0)
    {
      ncontrol = new CPMenu;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("pmenu") + itoa (tpmenuc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CScroll")) == 0)
    {
      ncontrol = new CScroll;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("scroll") + itoa (tscrollc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CCombo")) == 0)
    {
      ncontrol = new CCombo;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("combo") + itoa (tcomboc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CText")) == 0)
    {
      ncontrol = new CText;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("text") + itoa (ttextc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CFileDialog")) == 0)
    {
      ncontrol = new CFileDialog;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("filedialog") + itoa (tfiledialogc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CDirDialog")) == 0)
    {
      ncontrol = new CDirDialog;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("dirdialog") + itoa (tdirdialogc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CItemMenu")) == 0)
    {
      ncontrol = new CItemMenu;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("itemmenu") + itoa (titemmenuc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CTimer")) == 0)
    {
      ncontrol = new CTimer;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("timer") + itoa (ttimerc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CPanel")) == 0)
    {
      ncontrol = new CPanel;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("panel") + itoa (tpanelc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CGauge")) == 0)
    {
      ncontrol = new CGauge;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("gauge") + itoa (tgaugec++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CGrid")) == 0)
    {
      ncontrol = new CGrid;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("grid") + itoa (tgridc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CHtml")) == 0)
    {
      ncontrol = new CHtml;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("html") + itoa (thtmlc++));
      return ncontrol;
    };
  if (controltype.compare (wxT("CStatusbar")) == 0)
    {
      ncontrol = new CStatusbar;
//      ncontrol->Create (owner);
      ncontrol->SetName (wxT("statusbar") + itoa (tstatusbarc++));
      return ncontrol;
    };


  eprint (wxT("Unknown Controltype \"") + controltype + wxT("\"!\n"));
  exit (-1);
  return NULL;
};

void
getbuttons (CControl * owner)
{
  CToolButton *button;
//button1  
  button = new CToolButton;
  button->SetName (wxT("CButton"));
  button->SetHint (wxT("CButton"));
  button->SetX (0);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/button.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button2  
  button = new CToolButton;
  button->SetName (wxT("CLabel"));
  button->SetHint (wxT("CLabel"));
  button->SetX (26);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/label.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button3 
  button = new CToolButton;
  button->SetName (wxT("CEdit"));
  button->SetHint (wxT("CEdit"));
  button->SetX (52);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/edit.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button4 
  button = new CToolButton;
  button->SetName (wxT("CCheckBox"));
  button->SetHint (wxT("CCheckBox"));
  button->SetX (78);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/checkbox.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button5 
  button = new CToolButton;
  button->SetName (wxT("CDraw"));
  button->SetHint (wxT("CDraw"));
  button->SetX (104);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/draw.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button6 
  button = new CToolButton;
  button->SetName (wxT("CToolButton"));
  button->SetHint (wxT("CToolButton"));
  button->SetX (130);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/toolbutton.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button7 
  button = new CToolButton;
  button->SetName (wxT("CXpmButton"));
  button->SetHint (wxT("CXpmButton"));
  button->SetX (156);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/xpmbutton.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button8 
  button = new CToolButton;
  button->SetName (wxT("CList"));
  button->SetHint (wxT("CList"));
  button->SetX (182);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/list.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button9 
  button = new CToolButton;
  button->SetName (wxT("CFileList"));
  button->SetHint (wxT("CFileList"));
  button->SetX (208);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/filelist.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button10 
  button = new CToolButton;
  button->SetName (wxT("CMenu"));
  button->SetHint (wxT("CMenu"));
  button->SetX (234);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/menu.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button11 
  button = new CToolButton;
  button->SetName (wxT("CPMenu"));
  button->SetHint (wxT("CPMenu"));
  button->SetX (260);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/pmenu.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button12 
  button = new CToolButton;
  button->SetName (wxT("CScroll"));
  button->SetHint (wxT("CScroll"));
  button->SetX (286);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/scroll.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button13 
  button = new CToolButton;
  button->SetName (wxT("CCombo"));
  button->SetHint (wxT("CCombo"));
  button->SetX (312);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/combo.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button14 
  button = new CToolButton;
  button->SetName (wxT("CFileDialog"));
  button->SetHint (wxT("CFileDialog"));
  button->SetX (338);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/filedialog.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button15 
  button = new CToolButton;
  button->SetName (wxT("CTimer"));
  button->SetHint (wxT("CTimer"));
  button->SetX (364);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/timer.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button16 
  button = new CToolButton;
  button->SetName (wxT("CImage"));
  button->SetHint (wxT("CImage"));
  button->SetX (390);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/image.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button17 
  button = new CToolButton;
  button->SetName (wxT("CText"));
  button->SetHint (wxT("CText"));
  button->SetX (416);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/text.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button18 
  button = new CToolButton;
  button->SetName (wxT("CPanel"));
  button->SetHint (wxT("CPanel"));
  button->SetX (442);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/panel.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button14 
  button = new CToolButton;
  button->SetName (wxT("CDirDialog"));
  button->SetHint (wxT("CDirDialog"));
  button->SetX (468);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/dirdialog.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button15
  button = new CToolButton;
  button->SetName (wxT("CGauge"));
  button->SetHint (wxT("CGauge"));
  button->SetX (494);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/gauge.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button16
  button = new CToolButton;
  button->SetName (wxT("CGrid"));
  button->SetHint (wxT("CGrid"));
  button->SetX (520);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/grid.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button17
  button = new CToolButton;
  button->SetName (wxT("CHtml"));
  button->SetHint (wxT("CHtml"));
  button->SetX (546);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/html.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
//button18
  button = new CToolButton;
  button->SetName (wxT("CStatusbar"));
  button->SetHint (wxT("CStatusbar"));
  button->SetX (572);
  button->SetY (0);
  button->SetHint (button->GetName ());
  button->SetImgFileName (String (wxT(_SHARE)) + wxT("/icons/statusbar.png"));
  button->SetFOwner (&Window1);
  button->EvMouseButtonPress = EVMOUSEBUTTONCLICK & CPWindow1::MouseButtonClick;
  owner->CreateChild (button);
};


void 
drawcontrol(wxMemoryDC* NDC,CControl *ctrl)
{
    wxRect ret;
    wxColor FgColor;
    wxColor BgColor;
    wxPen Pen;
    wxBrush Brush;
 
    ret.x=5;
    ret.y=5;
    ret.width=ctrl->GetWidth()-10;
    ret.height=ctrl->GetHeight()-10;
  
     NDC->SetFont(wxFont(10, wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));

    if (ctrl->GetClass().compare (wxT("CButton")) == 0)
    {
      BgColor.Set(150,150,150);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);
/*
      FgColor.Set(0,100,0);
      Pen = wxPen(NDC->GetPen());
      NDC->SetTextForeground( FgColor);
      Pen.SetColour(FgColor);
      NDC->SetPen(Pen);
*/
      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      NDC->DrawLabel(((CButton*)ctrl)->GetText(),ret,wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL);
      return;   
    }

    if (ctrl->GetClass().compare (wxT("CEdit")) == 0)
    {
      BgColor.Set(255,255,255);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      NDC->DrawLabel(((CEdit*)ctrl)->GetText(),ret,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
      return;   
    }
    
    if (ctrl->GetClass().compare (wxT("CLabel")) == 0)
    {
      BgColor.Set(170,170,170);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      NDC->DrawLabel(((CLabel*)ctrl)->GetText(),ret,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
      return;   
    }
      
    if (ctrl->GetClass().compare (wxT("CCombo")) == 0)
    {
      BgColor.Set(255,255,255);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);
    
      ret.width=ctrl->GetWidth()-20;
      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      
      BgColor.Set(150,150,150);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(ctrl->GetWidth()-20,0,20,ctrl->GetHeight());
      NDC->DrawLabel(((CCombo*)ctrl)->GetText(),ret,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
      return;   
    }
    
    if (ctrl->GetClass().compare (wxT("CGauge")) == 0)
    {
      BgColor.Set(170,170,170);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);
    
      ret.width=ctrl->GetWidth()-20;
      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      
      BgColor.Set(0,0,150);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(0,0,ctrl->GetWidth()-30,ctrl->GetHeight());
      return;   
    }
    
    if (ctrl->GetClass().compare (wxT("CScroll")) == 0)
    {
      BgColor.Set(170,170,170);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);
    
      ret.width=ctrl->GetWidth()-20;
      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      
      BgColor.Set(150,150,150);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(0,0,20,ctrl->GetHeight());
      NDC->DrawRectangle(40,0,20,ctrl->GetHeight());
      NDC->DrawRectangle(ctrl->GetWidth()-20,0,20,ctrl->GetHeight());
      return;   
    }
    
    if (ctrl->GetClass().compare (wxT("CCheckBox")) == 0)
    {
      BgColor.Set(170,170,170);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);
    
      ret.x=20;
      ret.width=ctrl->GetWidth()-20;
      NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
      
      BgColor.Set(255,255,255);
      Brush= wxBrush(NDC->GetBrush());
      NDC->SetTextBackground( BgColor);
      Brush.SetColour(BgColor);
      NDC->SetBrush(Brush);

      NDC->DrawRectangle(5,5,10,10);
      NDC->DrawLabel(((CCheckBox*)ctrl)->GetText(),ret,wxALIGN_LEFT | wxALIGN_CENTER_VERTICAL);
      return;   
    }
     
    //generic control 
    //BgColor.Set(100,100,100);
    BgColor.Set(255,255,255); 
    Brush= wxBrush(NDC->GetBrush());
    NDC->SetTextBackground( BgColor);
    Brush.SetColour(BgColor);
    NDC->SetBrush(Brush);

    NDC->DrawRectangle(0,0,ctrl->GetWidth(),ctrl->GetHeight());
    //NDC->SetFont(wxFont(6, wxFONTFAMILY_DEFAULT,wxFONTSTYLE_NORMAL, wxFONTWEIGHT_NORMAL));
    NDC->DrawLabel(ctrl->GetName(),ret,wxALIGN_CENTER | wxALIGN_CENTER_VERTICAL);



}

