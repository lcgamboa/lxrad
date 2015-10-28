/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : Luis Claudio Gambôa Lopes

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

#include<unistd.h>

#include"window1.h"
#include"window2.h"
#include"window3.h"



//inclui janela
//Programa________________________________________________________________


Initialize
{

  Application->Start ();

  Janela3.WCreate(100);
 
  wxMilliSleep(500);
  
  Application->ACreateWindow (&Janela1);
  Application->ACreateWindow (&Janela2);
 

  Janela3.WDestroy();

  return Application->Load ();

};
