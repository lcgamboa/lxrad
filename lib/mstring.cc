/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2000  Luis Claudio Gamboa Lopes

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



//#include"../include/mstring.h"
#include"../include/clxrad.h"


String
xml_out (String name, String type, String value)
{
  return (wxT("  <") + name + wxT(" type=\"") + type + wxT("\">") + value + wxT("</") + name + wxT(">"));
};

void
xml_in (String data, String & name, String & type, String & value)
{
  int p0, p1, p2, p3;
  if(data != wxT(""))
  {

  p0 = data.find (wxT("<"));
  p1 = data.find (wxT("type="));
  p2 = data.find (wxT("\">"));
  p3 = data.find (wxT("</"));
  name = data.substr (p0 + 1, p1 - p0 - 2);
  type = data.substr (p1 + 6, p2 - p1 - 6);
  value = data.substr (p2 + 2, p3 - p2 - 2);
  }
  else
  {
  name=wxT("");
  type=wxT("");
  value=wxT("");
  }
};


String
LocaleToUtf8 (const String str)
{
/*
  char *temp;
  String ret;

  //temp = g_locale_to_utf8(str.c_str(),-1,NULL,NULL,&error);

  if (str.size () > 0)
    {
      //temp = g_convert (str.c_str (), -1, "UTF-8", "ISO-8859-1", NULL, NULL, NULL);
      ret = temp;
      //g_free (temp);
      printf("imcompleto! LocaleToUtf8\n");
    }
  else
    ret = "";

  return ret;
*/
return wxT("");
};

String
LocaleFromUtf8 (const String str)
{
/*
  //gchar *temp;
  String ret;

  //temp = g_locale_from_utf8(str.c_str(),-1,NULL,NULL,NULL);

  if (str.size () > 0)
    {
      //temp = g_convert (str.c_str (), -1, "ISO-8859-1", "UTF-8", NULL, NULL, NULL);

      //ret = temp;
      //g_free (temp);
      printf("imcompleto! LocaleFromUtf8\n");
    }
  else
    ret = "";

  return ret;
*/
return wxT("");
};


String
eqparse (String & str, String & arg)
{
  String temp = str;
  int pos1 = str.find (wxT("="));
  str = temp.substr (0, pos1);
  arg = temp.substr ((pos1 + 1), temp.size () - pos1 - 1);
  temp = arg;
  pos1 = temp.find (wxT(";"));
  arg = temp.substr (0, pos1);
  String stype = temp.substr ((pos1 + 1), temp.size () - pos1 - 1);
  return stype;
};


String
strndel (const String & str, uint n)
{
  String temp;
  temp = str;
  if ((n > 0) && (n <= str.size ()))
    temp.erase (n - 1, 1);
  return temp;
}

String
strnadd (const String & str, char c, uint n)
{
  String temp;
  temp = str.substr (0, n) + c + str.substr (n, str.size () - n);
  return temp;
};

int
atoi (const String & str)
{
#ifndef __UNICODE__
  return strtol (str.c_str (),NULL,0);
#else
  return wcstol (str.c_str (),NULL,0);
#endif
};

float
atof (const String & str)
{
#ifndef __UNICODE__
  return strtof(str.c_str (),NULL);
#else
  return wcstof(str.c_str (),NULL);
#endif
};

bool
atob (const String & str)
{
  bool b;
  if (str.compare (wxT("TRUE")) == 0)
    b = true;
  else
    b = false;
  return b;
};

String
itoa (int n, const String & format)
{
  return String::Format(format, n);
};

String
itoa (uint n, const String & format)
{
  return String::Format(format, n);
};

String
itoa (long n, const String & format)
{
  return String::Format(format, n);
};

String
ftoa (float f, const String & format)
{
  return String::Format(format.c_str (), f);
};

String
btoa (bool b)
{
  String str;
  if (b)
    str = wxT("TRUE");
  else
    str = wxT("FALSE");
  return str;
};

String
uppercase (const String & str)
{
  String ustr=str;
  return ustr.Upper();
}

String
lowercase (const String & str)
{
  String ustr=str;
  return ustr.Lower();
}

String
basename (const String & str)
{
#ifndef __WXMSW__
  int pos = str.rfind (wxT("/"));
#else
  int pos = str.rfind (wxT("\\"));
  if(pos == -1) 
     pos = str.rfind (wxT("/"));
#endif
  return str.substr (pos + 1, str.size () - pos - 1);
};

String
dirname (const String & str)
{
#ifndef __WXMSW__
  int pos = str.rfind (wxT("/"));
#else
  int pos = str.rfind (wxT("/"));
  int pos2 = str.rfind (wxT("\\"));
  if(pos2 > pos) 
     pos = pos2;
#endif
  return str.substr (0, pos + 1);
};


bool
fgetline (wxTextFile & file, String & str)
{
  String line;

  if(file.Eof()) return false;

  if (file.IsOpened()==true)
    {
      line =file.GetNextLine();

      str = line;

      return (!file.Eof());
    }
  else
    {
#ifdef __UNICODE__
      printf ("fatal error in function fgetline! (%ls)\n",wxSysErrorMsg(wxSysErrorCode()));
#else
      printf ("fatal error in function fgetline! (%s)\n",(const char *)wxSysErrorMsg(wxSysErrorCode()));
#endif
      exit (-1);
    };
};



void
mprint (String str)
{
#ifdef __UNICODE__
  printf ("%ls",(const wchar_t*) str.c_str ());
#else
  printf ("%s",(const char*) str.c_str ());
#endif
};

void
eprint (String str)
{
#ifdef __UNICODE__
  fprintf (stderr, "%ls", (const wchar_t*) str.c_str ());
#else
  fprintf (stderr, "%s", (const char *)str.c_str ());
#endif
};

#ifdef _MSTRING
//String _____________________________________________________________


String::String (void)
{
  Str = '\0';
};

String::String (const String & str)
{
  if (str.Str != NULL)
    {
      Str = new char[strlen (str.Str) + 1];
      strcpy (Str, str.Str);
    }
  else
    Str = '\0';
};

String::String (const char &str)
{
  if (str != '\0')
    {
      Str = new char[2];
      Str[0] = str;
      Str[1] = '\0';
    }
  else
    Str = '\0';
};

String::String (const char *str)
{
  if (str != NULL)
    {
      Str = new char[strlen (str) + 1];
      strcpy (Str, str);
    }
  else
    Str = '\0';
};

String::String (const char *str, int size)
{
  if (str)
    {
      Str = new char[size + 1];
      strncpy (Str, str, size);
      Str[size] = '\0';
    }
  else
    Str = '\0';
};

String::~String (void)
{
  if (Str != NULL)
    {
      delete[]Str;
      Str = NULL;
    };
};

const char *
String::c_str (void) const
{
  if (Str)
    return Str;
  else
    return NULL;
};

int
String::compare (const char *str) const
{
  if ((Str) && (str))
    return strcmp (Str, str);
  else
    return -1;
};

int
String::compare (const String & str) const
{
  if ((Str) && (str.Str))
    return strcmp (Str, str.Str);
  else
    return -1;
};

uint String::size (void) const
{
  if (Str != NULL)
    return strlen (Str);
  else
    return 0;
};

uint String::length (void) const
{
  if (Str != NULL)
    return strlen (Str);
  else
    return 0;
};

int
String::erase (uint start, int num)
{
  if (start + num <= length ())
    {
      char *tmp;
      tmp = new char[length () - num + 1];
      strncpy (tmp, Str, start);
      tmp[start] = '\0';
      strcat (tmp, (Str + start + num));
      strcpy (Str, tmp);
      delete[]tmp;
      return 1;
    }
  else
    return 0;
};

String String::substr (uint start, uint length) const
{
  if ((start < size ()) && (length > 0) && (start >= 0))
    {
      String
	temp;
      char *
	tmp;

      if (start + length > size ())
	length = size () - start;

      tmp = new char[length + 1];
      strncpy (tmp, Str + start, length);
      tmp[length] = '\0';
      temp = tmp;
      delete[]tmp;
      return temp;
    }
  else
    return '\0';
};

int
String::copy (char *str, uint sz) const
{
  if (Str)
    {
      if (sz < size ())
	{
	  strncpy (str, Str, sz);
	  str[sz] = '\0';
	  return sz;
	}
      else
	{
	  strncpy (str, Str, size ());
	  str[size ()] = '\0';
	  return size ();
	}
    }
  return 0;
};

int
String::find (const String & str) const
{
  if ((Str != NULL) && (str.Str != NULL))
    {
      char *temp = strstr (Str, str.Str);
      if (temp)
	return strlen (Str) - strlen (temp);
      else
	return -1;		//strlen (Str) + 1;
    }
  else
    return 0;
};

char *
strrstr (const char *str1, const char *str2)
{
  char *temp = '\0';
  char *temp1 = '\0';
  char *temp2 = '\0';
  uint c = 0;


  if ((str1 != NULL) && (str2 != NULL))
    {
      while (strlen (str1) != c)
	{
	  temp1 = new char[strlen (str1) + 1 - c];
	  strncpy (temp1, str1, strlen (str1) - c);
	  temp1[strlen (str1) - c] = '\0';
	  temp = strrchr (temp1, str2[0]);
	  if (temp)
	    {
	      temp2 = new char[strlen (str2) + 1];
	      strncpy (temp2, temp, strlen (str2));
	      temp2[strlen (str2)] = '\0';
	      if (strcmp (temp2, str2) == 0)
		{
		  c = strlen (temp) - 1;
		  delete[]temp1;
		  delete[]temp2;
		  char *str = new char[strlen (str1) + 1 - c];
		  strncpy (str, str1, strlen (str1) - c);
		  str[strlen (str1) - c] = '\0';
		  return str;
		}
	      else
		{
		  c += strlen (temp);
		  delete[]temp1;
		  delete[]temp2;
		};
	    }
	  else
	    c = strlen (str1);
	};
    }
  if (temp1)
    delete[]temp1;
  if (temp2)
    delete[]temp2;
  return NULL;
};


int
String::rfind (const String & str) const
{
  if ((Str != NULL) && (str.Str != NULL))
    {
      char *temp = strrstr (Str, str.Str);
      if (temp)
	{
	  int c = strlen (temp) - 1;
	  delete[]temp;
	  return c;
	}
      else
	return -1;		//length () + 1;
    }
  else
    return -1;			//length () + 1;
};


String & String::operator = (const String & str)
{
  if (this != &str)
    {
      if (Str != NULL)
	delete[]Str;
      if (str.Str != NULL)
	{
	  Str = new char[strlen (str.Str) + 1];
	  strcpy (Str, str.Str);
	}
      else
	Str = '\0';
    };
  return *this;
};

String & String::operator = (const char *str)
{
  if (Str != NULL)
    delete[]Str;

  if (str != NULL)
    {
      Str = new char[strlen (str) + 1];
      strcpy (Str, str);
    }
  else
    Str = '\0';
  return *this;
};

String
String::operator + (const String & str)
{
  String temp;

  if (str.Str != NULL)
    {
      temp.Str = new char[size () + strlen (str.Str) + 1];
      if (Str)
	{
	  strcpy (temp.Str, Str);
	  strcat (temp.Str, str.Str);
	}
      else
	strcpy (temp.Str, str.Str);
    }
  else
    {
      if (Str)
	{
	  if (&str != this)
	    {
	      temp.Str = new char[size () + 1];
	      strcpy (temp.Str, Str);
	    }
	  else
	    {
	      temp.Str = new char[(2 * size ()) + 1];
	      strcpy (temp.Str, Str);
	      strcat (temp.Str, Str);
	    }
	}
      else
	temp.Str = "\0";
    };
  return temp;
};


String
String::operator + (const char *str)
{
  String temp;

  if (str != NULL)
    {
      temp.Str = new char[size () + strlen (str) + 1];
      if (Str)
	{
	  strcpy (temp.Str, Str);
	  strcat (temp.Str, str);
	}
      else
	strcpy (temp.Str, str);
    }
  else
    {
      if (Str)
	{
	  temp.Str = new char[size () + 1];
	  strcpy (temp.Str, Str);
	}
      else
	temp.Str = '\0';
    };
  return temp;
};

String
String::operator + (const char &str)
{
  char str2[2];
  str2[0] = str;
  str2[1] = '\0';
  String temp;

  if (Str != NULL)
    {
      temp.Str = new char[size () + 2];
      strcpy (temp.Str, Str);
      strcat (temp.Str, str2);
    }
  else
    {
      temp.Str = new char[2];
      strcpy (temp.Str, str2);
    };

  return temp;
};

String & String::operator += (const String & str)
{
  String
    temp =
    Str;

  if (Str != NULL)
    {
      delete Str;
      Str = NULL;
    };

  if (str.Str != NULL)
    {
      Str = new char[temp.size () + strlen (str.Str) + 1];
      if (temp.Str)
	{
	  strcpy (Str, temp.Str);
	  strcat (Str, str.Str);
	}
      else
	strcpy (Str, str.Str);
    }
  else
    {
      if (temp.Str)
	{
	  if (&str != this)
	    {
	      Str = new char[temp.size () + 1];
	      strcpy (Str, temp.c_str ());
	    }
	  else
	    {
	      Str = new char[(2 * temp.size ()) + 1];
	      strcpy (Str, temp.c_str ());
	      strcat (Str, temp.c_str ());
	    }
	}
      else
	Str = "\0";
    };
  return *this;
};

String & String::operator += (const char *str)
{
  String temp = Str;
  if (Str != NULL)
    {
      delete Str;
    };

  if (str != NULL)
    {
      Str = new char[temp.size () + strlen (str) + 1];
      if (temp.Str)
	{
	  strcpy (Str, temp.c_str ());
	  strcat (Str, str);
	}
      else
	strcpy (Str, str);
    }
  else
    {
      if (temp.Str)
	{
	  Str = new char[temp.size () + 1];
	  strcpy (Str, temp.c_str ());
	}
      else
	Str = '\0';
    };
  return *this;
};

String & String::operator += (const char &str)
{
  char
    str2[2];
  str2[0] = str;
  str2[1] = '\0';
  String temp = Str;

  if (Str != NULL)
    {
      delete Str;
      Str = new char[temp.size () + 2];
      strcpy (Str, temp.c_str ());
      strcat (Str, str2);
    }
  else
    {
      Str = new char[2];
      strcpy (Str, str2);
    };
  return *this;
};

char &
String::operator[] (const uint & index)
{
//  if((Str)&&(index <= length()))
  return Str[index];
};

String
operator + (const char *str1, const String & str2)
{
  if (str1)
    {
      if (str2.Str)
	return String (str1) + str2;
      else
	return str1;
    }
  else
    {
      if (str2.Str)
	return str2;
    };
  return '\0';
};

String
operator + (const char &str1, const String & str2)
{
  char temp[2];
  temp[0] = str1;
  temp[1] = '\0';
  if (temp)
    {
      if (str2.Str)
	return String (temp) + str2;
      else
	return temp;
    }
  else
    {
      if (str2.Str)
	return str2;
    };
  return '\0';
};

/*
ostream & operator << (ostream & os, const String & str)
{
  os << str.Str;
  return os;
};
*/

#endif


//CStringList _____________________________________________________________

CStringList::CStringList (void)
{
  Lines = NULL;
  LinesCount = 0;
};

CStringList::CStringList (const CStringList & list)
{
  Lines = NULL;
  LinesCount = 0;
  for (uint c = 0; c < list.GetLinesCount (); c++)
    {
      AddLine (list.GetLine (c));
    };
};

CStringList::~CStringList (void)
{
  if (Lines)
    {
      delete[]Lines;
      Lines = NULL;
    };
  LinesCount = 0;
};

void
CStringList::Create ()
{
};

String CStringList::GetLine (uint linen) const
{
  if(linen < (unsigned int)LinesCount)
    return Lines[linen];
  else
    return wxT("");
};

#ifdef __UNICODE__
const wchar_t *
#else
const char *
#endif
CStringList::GetLineStr (uint linen) const
{
  if(linen < (unsigned int)LinesCount)
    return Lines[linen].c_str ();
  else
    return NULL;
};

void
CStringList::SetLine (String line, uint linen)
{
  if(linen < (unsigned int)LinesCount)
    Lines[linen] = line;
};


void
CStringList::Clear (void)
{
  if (Lines)
    {
      delete[]Lines;
    };
  Lines = NULL;
  LinesCount = 0;
};

void
CStringList::AddLine (const String line)
{
  if (((const char*)line.c_str ()) != NULL)
    {
      LinesCount++;
      String *ALines = new String[LinesCount];
      for (int c = 0; c < LinesCount-1; c++)
	ALines[c] = Lines[c];
      ALines[LinesCount-1] = line;
      if (Lines)
	delete[]Lines;
      Lines = ALines;
    }
};

void
CStringList::InsertLine (String line, uint linen)
{
  if(linen >= (unsigned int)LinesCount)linen=LinesCount-1;

  LinesCount++;
  String *ALines = new String[LinesCount];
  for (uint c = 0; c < linen; c++)
    ALines[c] = Lines[c];
  ALines[linen] = line;
  for (int c = linen + 1; c < LinesCount; c++)
    ALines[c] = Lines[c - 1];
  if (Lines)
    delete[]Lines;
  Lines = ALines;
};


uint CStringList::GetLinesCount (void) const
{
  return LinesCount;
};

void
CStringList::DelLine (uint linen)
{
  if(linen < (unsigned int)LinesCount)
  {
  LinesCount--;
  String *ALines = new String[LinesCount];
  for (uint c = 0; c < linen; c++)
    ALines[c] = Lines[c];
  for (int c = linen; c < LinesCount; c++)
    ALines[c] = Lines[c + 1];
  if (Lines)
    delete[]Lines;
  Lines = ALines;
  }
};

bool
CStringList::LoadFromFile (String fname)
{
  wxTextFile file;
  
  
  file.Open (fname);
  file.GoToLine(-1);
  if (file.IsOpened() == true)
    {
      String line;
      while (fgetline (file, line))
	AddLine (line);

      file.Close();
      return true; 
    }
  else
#ifdef __UNICODE__
    printf ("File not found!(%ls)\n",wxSysErrorMsg(wxSysErrorCode()));
#else
    printf ("File not found!(%s)\n",(const char*)wxSysErrorMsg(wxSysErrorCode()));
#endif
  return false;
};


bool
CStringList::SaveToFile (String fname)
{

  wxTextFile file;
  
  if (file.Create (fname) == true)
    {
      for (int c = 0; c < LinesCount; c++)
        file.AddLine( GetLine (c));
	
      file.Write();
      file.Close();
      return true;
    }
  else if (file.Open(fname) == true)
    {
      file.Clear();
      for (int c = 0; c < LinesCount; c++)
 	file.AddLine( GetLine (c));
      file.Write();
      file.Close();
      return true;
    }
  else
#ifdef __UNICODE__
    printf ("File not create!(%ls)\n",wxSysErrorMsg(wxSysErrorCode()));
#else
    printf ("File not create!(%s)\n",(const char*)wxSysErrorMsg(wxSysErrorCode()));
#endif
  return false;

};

bool
CStringList::AppendToFile (String fname)
{
  wxTextFile file;


  file.Open (fname);
  
  if (file.IsOpened())
    {
      for (int c = 0; c < LinesCount; c++)
	file.AddLine( GetLine (c));
      file.Write();
      file.Close();
      return true;
    }
  else
#ifdef __UNICODE__
    printf ("File not create!(%ls)\n",wxSysErrorMsg(wxSysErrorCode()));
#else
    printf ("File not create!(%s)\n",(const char*)wxSysErrorMsg(wxSysErrorCode()));
#endif
  return false;

};


CStringList & CStringList::operator = (const CStringList & list)
{
  if (this != &list)
    {
      if (Lines != NULL)
	delete[]Lines;

      if (list.Lines != NULL)
	{
	  Lines = NULL;
	  LinesCount = 0;
	  for (uint c = 0; c < list.GetLinesCount (); c++)
	    {
	      AddLine (list.GetLine (c));
	    }
	}
      else
	{
	  Lines = NULL;
	  LinesCount = 0;
	};
    };
  return *this;
};

String
CStringList::GetBuffer (void)
{
  String buff;

  for (int c = 0; c < LinesCount; c++)
    buff += Lines[c] + wxT("\n");

  return buff;
};

void
CStringList::SetBuffer (String buff)
{
  int endl;

  Clear ();

  endl = buff.find (wxT("\n"));

  while ((endl >= 0) && (buff.size () > 0))
    {
      if (endl > 0)
	AddLine (buff.substr (0, endl));
      else
	AddLine (wxT(""));

      buff = buff.substr (endl + 1, buff.size ());
      endl = buff.find (wxT("\n"));
    };
  if (buff.size () > 0)
    AddLine (buff);

};


/*
//CStringList _____________________________________________________________

CStringList::CStringList (void)
{
};

CStringList::CStringList (const CStringList & list)
{
  for (uint c = 0; c < list.GetLinesCount (); c++)
    {
      AddLine (list.GetLine (c));
    };
};

CStringList::~CStringList (void)
{
  List.erase (List.begin (), List.end ());
};

void
CStringList::Create ()
{
};

string CStringList::GetLine (uint linen) const
{
  list < string > List2 (List);
  list < string >::iterator itList2;
  itList2 = List2.begin ();
  for (uint a = 0; a < linen; a++)
    itList2++;
  return *itList2;
};

const char *
CStringList::GetLineStr (uint linen) const
{
  list < string > List2 (List);
  list < string >::iterator itList2;
  itList2 = List2.begin ();
  for (uint a = 0; a < linen; a++)
    itList2++;
  return itList2->c_str ();
};

void
CStringList::SetLine (string line, uint linen)
{
  itList = List.begin ();
  for (uint a = 0; a < linen; a++)
    itList++;
  *itList = line;
};


void
CStringList::Clear (void)
{
  List.erase (List.begin (), List.end ());
};

void
CStringList::AddLine (string line)
{
  List.push_back (line);
};

void
CStringList::InsertLine (string line, uint linen)
{
  itList = List.begin ();
  for (uint a = 0; a < linen; a++)
    itList++;
  List.insert (itList, line);
};


uint CStringList::GetLinesCount (void) const
{
  return List.size ();
};

void
CStringList::DelLine (uint linen)
{
  itList = List.begin ();
  for (uint a = 0; a < linen; a++)
    itList++;
  List.erase (itList);
};

bool
CStringList::LoadFromFile (string fname)
{
  ifstream file (fname.c_str ());
  if (file)
    {
      string line;
      while (getline (file, line))
	List.push_back (line);
    }
  else
    printf ("File not found!\n");
 
 return false;
};

bool
CStringList::SaveToFile (string fname)
{
  ofstream file (fname.c_str ());
  if (file)
    {
      for (itList = List.begin (); itList != List.end (); itList++)
	file << *itList << endl;
    }
  else
    printf ("File not create!\n");

 return false;
};

bool
CStringList::AppendToFile (string fname)
{
  ofstream file (fname.c_str (), ios::app);
  
  if (file)
    {
      for (itList = List.begin (); itList != List.end (); itList++)
	file << *itList << endl;
    }
  else
    printf ("File not create!\n");
  return false;
};

string CStringList::GetBuffer (void)
{
  string    buff = "";

  for (itList = List.begin (); itList != List.end (); itList++)
    buff += *itList +"\n";

  return buff;
};

void
CStringList::SetBuffer (string buff)
{
  int endl;

  Clear ();

  endl = buff.find ("\n");

  while ((endl >= 0) && (buff.size () > 0))
    {
      if (endl > 0)
	AddLine (buff.substr (0, endl));
      else
	AddLine ("");

      buff = buff.substr (endl + 1, buff.size ());
      endl = buff.find ("\n");
    };
  if (buff.size () > 0)
    AddLine (buff);

};
#endif
*/


