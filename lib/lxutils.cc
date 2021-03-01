/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2018  Luis Claudio Gamboa Lopes

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


#include"../include/lxutils.h"
#include "wx/stdpaths.h"
#include "wx/filesys.h"
#include "wx/zipstrm.h"
#include "wx/fs_zip.h"
#include "wx/wfstream.h"
#include "wx/dir.h"
#include <memory>
#include<dirent.h>

#include"../../lunasvg/include/svgdocument.h"

using namespace lunasvg;

#if __cplusplus >= 201103L
#define xauto_ptr  std::unique_ptr
#else
#define xauto_ptr  std::auto_ptr
#endif

bool
lxUnzipDir(const lxString &in_filename, const lxString &out_dirname)
{
 bool ret = true;

 wxFileSystem::AddHandler (new wxZipFSHandler);
 wxFileSystem fs;

 xauto_ptr<wxZipEntry> entry (new wxZipEntry);
 do
  {
   wxFileInputStream in (in_filename);
   if (!in)
    {
     wxLogError (_T ("Can not open file '") + in_filename + _T ("'."));
     ret = false;
     break;
    }
   wxZipInputStream zip (in);

   //create dirs
   while (entry.reset (zip.GetNextEntry ()), entry.get () != NULL)
    {
     // access meta-data
     lxString name = entry->GetName ();

     if (dirname (name).Length () > 0)
      {
       lxCreateDir (out_dirname + dirname (name));
      }

     name = out_dirname + name;


     // read 'zip' to access the entry's data
     if (entry->IsDir ())
      {
       int perm = entry->GetMode ();
       wxFileName::Mkdir (name, perm, wxPATH_MKDIR_FULL);
      }
     else
      {
       zip.OpenEntry (*entry.get ());
       if (!zip.CanRead ())
        {
         wxLogError (_T ("Can not read zip entry '") + entry->GetName () + _T ("'."));
         ret = false;
         break;
        }
       wxFileOutputStream file (name);
       if (!file)
        {
         wxLogError (_T ("Can not create file '") + name + _T ("'."));
         ret = false;
         break;
        }
       zip.Read (file);
      }

    }
  }
 while (false);

 return ret;
}

bool
lxZipDir(const lxString &in_dirname, const lxString &out_filename)
{
 lxString sep (wxFileName::GetPathSeparator ());

 wxArrayString files;

 wxDir::GetAllFiles (in_dirname, &files); //the dir contented all the files need to compress.

 wxFFileOutputStream fileout (out_filename);

 wxZipOutputStream zipout (fileout);

 wxFFileInputStream *in = NULL;
 wxZipEntry *entry = NULL;
 wxFileName *zipname = NULL;

 for (size_t i = 0; i != files.GetCount (); ++i)
  {
   if (in != NULL)
    {
     delete in;
     in = NULL;
    }
   if (zipname != NULL)
    {
     delete zipname;
     zipname = NULL;
    }

   in = new wxFFileInputStream (files[i]);
   zipname = new wxFileName (files[i]);
   if (zipname->MakeRelativeTo (in_dirname))
    {
     entry = new wxZipEntry (wxT ("picsimlab_workspace/") + zipname->GetFullPath ());
     zipout.PutNextEntry (entry);
     zipout.Write (*(in));
    }
   else
    {
     return false;
    }
  }
 zipout.CloseEntry ();
 zipout.Close ();
 fileout.Close ();
 if (in != NULL)
  {
   delete in;
   in = NULL;
  }
 if (zipname != NULL)
  {
   delete zipname;
   zipname = NULL;
  }
 return true;
}

bool
lxRemoveFile(const char * fname)
{
 return remove (fname);
}

bool
lxRemoveDir(const char* dirname)
{
 DIR *dp;
 struct dirent *dent;
 struct stat sb;
 char fname[1024];

 dp = opendir (dirname);

 if (dp)
  {
   while ((dent = readdir (dp)) != NULL)
    {
     snprintf (fname, 1024, "%s/%s", dirname, dent->d_name);
     stat (fname, &sb);

     if (S_ISREG (sb.st_mode))
      {
       lxRemoveFile (fname);
      }
     else if (S_ISDIR (sb.st_mode))
      {
       if (!(!strcmp (dent->d_name, ".") || !strcmp (dent->d_name, "..")))
        {
         lxRemoveDir (fname);
        }
      }
    }
   closedir (dp);
   return rmdir (dirname);
  }
 return 0;
}

bool
lxCreateDir(const char * dirname)
{
 DIR *dp;
 dp = opendir (dirname);

 if (dp)
  {
   return closedir (dp);
  }
 else
  {
#ifndef __WXMSW__
   return mkdir (dirname, S_IWUSR | S_IRUSR | S_IXUSR | S_IRGRP | S_IROTH);
#else     
   return mkdir (dirname);
#endif
  }
 return 0;
}

lxString
lxGetUserDataDir(lxString appname)
{
 wxTheApp->SetAppName (appname);
 wxStandardPathsBase& stdp = wxStandardPaths::Get ();
 return stdp.GetUserDataDir ();
}

lxString
lxGetTempDir(lxString appname)
{
 wxTheApp->SetAppName (appname);
 wxStandardPathsBase& stdp = wxStandardPaths::Get ();
 return stdp.GetTempDir ();
}

lxString
lxGetExecutablePath(lxString appname)
{
 wxTheApp->SetAppName (appname);
 wxStandardPathsBase& stdp = wxStandardPaths::Get ();
 return stdp.GetExecutablePath ();
}

lxBitmap *
lxGetBitmapRotated(lxImage *image, CWindow * win, int orientation)
{
 lxImage im(win);

 switch (orientation)
  {
  case 1:
   im = image->Rotate90 (1);
   break;
  case 2:
   im = image->Rotate180 ();
   break;
  case 3:
   im = image->Rotate90 (0);
   break;
  default:
   im = *image;
   break;
  }

 lxBitmap * Bitmap = new xBitmap (im, win);
 im.Destroy ();
 return Bitmap;
}

bool
xImage::LoadFile(const lxString fname, int orientation, float scalex, float scaley)
{

 if (fname.Contains (".svg"))
  {
   int width;
   int height;

   SVGDocument document;
   if (document.loadFromFile ((const char *)fname.c_str ()))
    {
     width = document.documentWidth (96.0) * scalex;
     height = document.documentHeight (96.0) * scaley;

     Bitmap bitmap = document.renderToBitmap (width, height, 96.0, 0);

     const unsigned char * bmp = bitmap.data ();
     int size = bitmap.width () * bitmap.height ();
     unsigned char * data = (unsigned char *) malloc (size * 3);
     unsigned char * alpha = (unsigned char *) malloc (size);

     for (int i = 0; i < size; i++)
      {
       data[(3 * i)] = bmp[(4 * i)];
       data[(3 * i) + 1] = bmp[(4 * i) + 1];
       data[(3 * i) + 2] = bmp[(4 * i) + 2];
       alpha[i] = bmp[(4 * i) + 3];
      }

     lxImage image(NULL);
     image.Create (bitmap.width (), bitmap.height (), data, alpha);

     lxImage * im =this;
     switch (orientation)
      {
      case 1:
       *im = image.Rotate90 (1);
       break;
      case 2:
       *im = image.Rotate180 ();
       break;
      case 3:
       *im = image.Rotate90 (0);
       break;
      default:
       *im = image;
       break;
      }

     image.Destroy ();
     
     return 1;
    }

  }
 else //png
  {
   lxImage image(NULL);

   if (image.wxImage::LoadFile (fname))
    {

     lxImage * im =this;

     image.Rescale (image.GetWidth () * scalex, image.GetHeight () * scaley);

     switch (orientation)
      {
      case 1:
       *im = image.Rotate90 (1);
       break;
      case 2:
       *im = image.Rotate180 ();
       break;
      case 3:
       *im = image.Rotate90 (0);
       break;
      default:
       *im = image;
       break;
      }

     image.Destroy ();

     return 1;
    }
  }

 return 0;

}

