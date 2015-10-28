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

#include"../include/cobject.h"

//CObject--------------------------------------------------------------

CObject::CObject (void)
{
  SetName (wxT("cobject"));
  SetClass (wxT("CObject"));
  Evcount = 0;
  Tag = 0;
  Aux = 0;	
  for (int a = 0; a < EVMAX; a++)
    Ev[a] = false;
};

CObject::~CObject (void)
{
};

void
CObject::SetName (const String name)
{
  Name = name;
};

String
CObject::GetName (void)
{
  return Name;
};

void
CObject::SetClass (const String classn)
{
  Class = classn;
};

String
CObject::GetClass (void)
{
  return Class;
};

void
CObject::SetTag (uint tag)
{
  Tag = tag;
};

uint
CObject::GetTag (void)
{
  return Tag;
};

void
CObject::SetAux (int aux)
{
  Aux = aux;
};

int
CObject::GetAux (void)
{
  return Aux;
};



CStringList
CObject::GetContext (void)
{
  Context.Clear ();
  Context.AddLine (xml_out (wxT("Class"), wxT("String"), GetClass ()));
  Context.AddLine (xml_out (wxT("Name"), wxT("String"), GetName ()));
  Context.AddLine (xml_out (wxT("Tag"), wxT("int"), itoa (GetTag ())));
  return Context;
};

void
CObject::SetContext (CStringList context)
{
  String name, type, value;
  Context.Clear ();
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      
      Context.AddLine (context.GetLine (i));
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("Name")) == 0)
	SetName (value);
      if (name.compare (wxT("Tag")) == 0)
	SetTag (atoi (value));
    };
};

bool
CObject::GetEv (bool reset)
{
  if (reset)
    Evcount = 0;
  else
    Evcount++;
  return Ev[Evcount];
};


void
CObject::SetEv (bool value, bool reset)
{
  if (reset)
    Evcount = 0;
  else
    Evcount++;
  Ev[Evcount] = value;
};


