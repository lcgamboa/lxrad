
/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : Luis Claudio Gamboa Lopes

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
#include"window1.h"

CJanela1 Janela1;


//implemetation

#include"window1_d.cc"

#include"window2.h"

void
CJanela1::timer1OnTime (CControl * control)
{
  mprint (wxT("on timer (increment gauge1)\n"));
  gauge1.SetValue(gauge1.GetValue()+10);
  if(gauge1.GetValue() == gauge1.GetRange())gauge1.SetValue(0);
  
  
  printf("argc=%i argv[0]=%s\n",Application->argc,(char *)Application->argv[0].char_str());        
};


void
CJanela1::button1MouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{
  SetTitle (wxT("janela1"));
  if (Janela2.GetVisible ())
    Janela2.Hide ();
  else
    Janela2.Show ();

printf("CJanela1::button1MouseButtonRelease (Change window Title and show/hide window2)\n");

  CPWindow * wd1= new CPWindow;
 
 
  wd1->SetName("Janela1");//must be the same as in xml 
  Application->ACreateWindow (wd1);
  wd1->LoadXMLContextAndCreateChilds ("teste/window_1.lxrad");

};

void
CJanela1::button2MouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{

  Message (wxT("Isso e um teste"));

  if (Dialog (wxT("Load teste.png in window2 and draw1?")))
    {
      Janela2.draw1.SetImgFileName (wxT("teste.png"),0.5,0.5);
      draw1.SetImgFileName (wxT("teste.png"),0.5,0.5);
      mprint (wxT("Ok\n"));
    }
  else
    {
      mprint (wxT("Cancel\n"));
    };


  button6.Destroy ();

  printf("CJanela1::button2MouseButtonRelease (message, dialog and destroy button6)\n");
};

void
CJanela1::button3MouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{

  if (filedialog1.Run ())
    {
      Janela2.draw1.WriteImgToFile (filedialog1.GetFileName ());
      mprint (wxT("tudo=")+filedialog1.GetFileName ()+wxT("  d=\"") + dirname (filedialog1.GetFileName ()) + wxT("\"   f=\"") + basename (filedialog1.GetFileName ()) + wxT("\"\n"));
    }
  else
    mprint (wxT("Dialog canceled\n"));

  if (dirdialog1.Run ())
    mprint (wxT("Dir Dialog Ok\n"));
  else  
    mprint (wxT("Dir Dialog canceled\n"));


  button1.SetEnable (!button1.GetEnable ());
  button2.SetEnable (!button2.GetEnable ());
  toolbutton1.SetEnable (!toolbutton1.GetEnable ());

  printf("CJanela1::button3MouseButtonRelease (save window2 in png, dir dialog test, enable buttons)\n");
};


void
CJanela1::pmenuitem2_3MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{
  printf("CJanela1::pmenuitem2_3MouseButtonPress (Wdestroy)\n");
  WDestroy ();
  
};

void
CJanela1::pmenuitem1_3MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{
  CStringList List = button1.GetContext ();
  for (uint a = 0; a < List.GetLinesCount (); a++)
    mprint ((List.GetLine (a) + wxT("\n")).c_str ());
  mprint (wxT("--------------------------------------\n"));
  //List.SaveToFile ("xcontext.xml");
  List.LoadFromFile (wxT("xcontext.xml"));
  button1.SetContext (List);

  printf("CJanela1::pmenuitem1_3MouseButtonPress (print button1 context, set button1 context)\n ");
};

void
CJanela1::pmenuitem1_2MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{

  for (uint a = 1; a < 4; a++)
    {
      CButton *ct = dynamic_cast < CButton * >(GetChildByName (wxT("button") + itoa (a)));
      mprint ((ct->GetName () + wxT("\n")).c_str ());
      if (ct)
	ct->SetText (ct->GetName ());
    };

  printf("CJanela1::pmenuitem1_2MouseButtonPress (change buttons text)\n");
};


void
CJanela1::checkbox1_oncheckbox (CControl * control)
{
  String s;	
  checkbox2.SetCheck (checkbox1.GetCheck ());

  s=list1.GetItems();
  mprint(s+wxT("\n"));
  s=s+wxT("lixo,");
  list1.SetItems(s);	  
 
 
  pmenuitem1_1.GetText();
  pmenuitem1_2.GetText();
  pmenuitem1_3.GetText();
  pmenuitem2_1.GetText();
  pmenuitem2_2.GetText();
  pmenuitem2_3.GetText();

  printf ("check checkbox2, print list and add one line, pmenuitem get text????\n");
};


void
CJanela1::AjudaMouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{
  String texto = wxT("aqui");
  bool ret = Input (wxT("escreva :"), texto);
  mprint ((texto + wxT(" ") + itoa (ret) + wxT("\n")).c_str ());

  list1.SetSelectedItem (texto);
  combo1.SetSelectedItem (texto);

  Janela1.WriteXMLContext (wxT("janela1.xml"));
  Janela1.LoadXMLContext (wxT("janela1_.xml"));
  
  printf("CJanela1::AjudaMouseButtonPress (input dialog,selected item in list1 and combo, save janela1.xml context)\n");
};


void
CJanela1::ListClick (CList * list)
{
  mprint (list->GetSelectedItem () + wxT("\n"));
  statusbar1.SetField(0,list->GetSelectedItem ());
  printf("ListClick (print,statusbar)\n");
  thread1.Run();
};

void
CJanela1::FileListOnFileSelected (CControl * control)
{
  mprint (filelist1.GetSelectedFile () + wxT("\n"));
  text1.LoadFromFile (filelist1.GetSelectedFile ());

  printf("FileListOnFileSelected (Load file in text1)\n");
};



void
CJanela1::Combo1Change (CControl * control)
{
  mprint (combo1.GetSelectedItem () + wxT("\n"));
  
  CStringList List;
  List.AddLine(wxT("um"));
  List.AddLine(wxT("dois"));
  List.AddLine(wxT("tres"));

  mprint (wxT("--------------------------------------\n"));
  for (uint a = 0; a < List.GetLinesCount (); a++)
    mprint ((itoa(a)+List.GetLine (a) + wxT("\n")).c_str ());
  mprint (wxT("--------------------------------------\n"));

  printf("combo1Change (Print combo selected, add um dois tres in list , print list)\n");
};

void
CJanela1::Combo2Change (CControl * control)
{

  combo2.SetItems(wxT("um,dois,tres,"));
  combo2.SetText("um");
  printf("combo2Change (reload combo2 list)\n");
};



void
CJanela1::Edit1Focus (CControl * control)
{
  mprint (wxT("focus changed \" ")+ control->GetName () + wxT("\" \n"));
  
  printf("CJanela1::Edit1Focus (show control on focus)\n");
  
  printf("toggle check=%i\n",togglebutton1.GetCheck ());
  if(togglebutton1.GetCheck ())
    {
#ifndef __WXX11__ 	    
      if(colordialog1.Run())
        {
           togglebutton1.SetColor (colordialog1.GetColor());
           label1.SetColor (colordialog1.GetColor());
        }
#endif      
    }
    
 };


void
CJanela1::Thread1Run (CControl * control)
{
  int i,j;
  double b=1;

  printf("Thread1 Run\n");
  for(j=0;j<10;j++)
  {
  for(i=0;i<80000000;i++)
  {
    b=b*1.244+b*log(b);
    if(thread1.TestDestroy())return;
  }
  //if(thread1.TestDestroy())return;
  }
}

void
CJanela1::Thread1End (CControl * control)
{
  printf("Thread1 End\n");
}


