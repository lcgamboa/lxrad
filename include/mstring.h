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

/**
 * \file mstring.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef MSTRING
#define MSTRING

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>


#ifdef _MSTRING


class lxString
{
private:
  char *Str;
public:
    lxString (void);
    lxString (const lxString & str);
    lxString (const char &str);
    lxString (const char *str);
    lxString (const char *str, int size);
   ~lxString (void);
  const char *c_str (void) const;
  int compare (const char *str) const;
  int compare (const lxString & str) const;
  uint size (void) const;
  uint length (void) const;
  lxString substr (uint start, uint length) const;
  int find (const lxString & str) const;
  int rfind (const lxString & str) const;
  int erase (uint start, int num);
  int copy (char *str, uint sz) const;
    lxString & operator = (const lxString & str);
    lxString & operator = (const char *str);
  lxString operator + (const lxString & str);
  lxString operator + (const char *str);
  lxString operator + (const char &str);
    lxString & operator += (const lxString & str);
    lxString & operator += (const char *str);
    lxString & operator += (const char &str);
  char &operator[] (const uint & index);
  friend lxString operator + (const char *str1, const lxString & str2);
  friend lxString operator + (const char &str1, const lxString & str2);
//  friend ostream & operator << (ostream & os, const lxString & str);
};

#endif

class lxStringList
{
private:
  lxString * Lines;
  int LinesCount;
public:
    lxStringList (void);
    lxStringList (const lxStringList & list);
   ~lxStringList (void);
  void Create ();
  void Clear ();
  void AddLine (const lxString line);
  void InsertLine (lxString line, uint linen);
  void DelLine (uint linen);
  bool LoadFromFile (lxString fname);
  bool SaveToFile (lxString fname);
  bool AppendToFile (lxString fname);
    lxStringList & operator = (const lxStringList & list);
  //propiedades
  lxString GetLine (uint linen) const;
#ifdef __UNICODE__
  const wchar_t *GetLineStr (uint linen) const;
#else
  const char *GetLineStr (uint linen) const;
#endif
  void SetLine (lxString line, uint linen);
  uint GetLinesCount (void) const;
  lxString GetBuffer (void);
  void SetBuffer (lxString buff);
};

/*
#else

using namespace std;
#include<string>
#include<iostream>
#include<fstream>
#include<list>


class lxStringList
{
private:
  list < string > List;
  list < string >::iterator itList;
public:
    lxStringList (void);
    lxStringList (const lxStringList & list);
   ~lxStringList (void);
  void Create ();
  void Clear ();
  void AddLine (string line);
  void InsertLine (string line, uint linen);
  void DelLine (uint linen);
  bool LoadFromFile (string fname);
  bool SaveToFile (string fname);
  bool AppendToFile (string fname);
  //propiedades
  string GetLine (uint linen) const;
  const char *GetLineStr (uint linen) const;
  void SetLine (string line, uint linen);
  uint GetLinesCount (void) const;
  string GetBuffer (void);
  void SetBuffer (string buff);
};
#endif
*/


lxString xml_out (lxString name, lxString type, lxString value);
void xml_in (lxString data, lxString & name, lxString & type, lxString & value);

/*Deprecate*/
lxString eqparse (lxString & str, lxString & arg);

lxString LocaleToUtf8 (const lxString str);
lxString LocaleFromUtf8 (const lxString str);

lxString strndel (const lxString & str, uint n);
lxString strnadd (const lxString & str, char c, uint n);
int atoi (const lxString & str);
float atof (const lxString & str);
bool atob (const lxString & str);
lxString itoa (int n, const lxString & format = wxT("%i"));
lxString itoa (uint n, const lxString & format = wxT("%u"));
lxString itoa (long n, const lxString & format = wxT("%li"));
lxString ftoa (float f, const lxString & format = wxT("%f"));
lxString btoa (bool b);

 /**
  * Set uppercase string.
  *
  * \param str string.
  * \return uppercase string.
  */
lxString uppercase (const lxString & str);
 /**
  * Set lowercase string.
  *
  * \param str string.
  * \return lowercase string.
  */
lxString lowercase (const lxString & str);

lxString basename (const lxString & str);
lxString dirname (const lxString & str);

bool fgetline (wxTextFile &file, lxString & str);

void mprint (lxString str);

void eprint (lxString str);


#endif
