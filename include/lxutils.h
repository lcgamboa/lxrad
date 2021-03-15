/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001-2019  Luis Claudio Gamboa Lopes

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


#ifndef LXUTILS_H
#define	LXUTILS_H

#include"clxrad.h"

#include<wx/bitmap.h>
#include"cwindow.h"

class xBitmap:public wxBitmap
{
   public:	
    xBitmap(wxImage * img, CWindow * win):wxBitmap(*img){};
    xBitmap(unsigned int x, unsigned int y):wxBitmap(x,y){};
};

class xImage:public wxImage
{
  public:
   xImage(CWindow * win):wxImage(){};   
   bool LoadFile(const lxString fname, int orientation = 0, float scalex = 1.0,  float scaley = 1.0, int usealpha = 1);
   using wxImage::operator=;
};


#define lxT wxT
#define lxImage xImage
#define lxBitmap xBitmap
#define lxFont wxFont
#define lxSound wxSound
#define lxColor wxColor
#define lxPoint wxPoint
#define lxCursor wxCursor 
#define lxFileName wxFileName
#define lxTextFile wxTextFile

#define lxSetCursor wxSetCursor 
#define lxMilliSleep wxMilliSleep
#define lxFileExists wxFileExists
#define lxExecute wxExecute
#define lxGetCwd wxGetCwd 
#define lxLaunchDefaultBrowser wxLaunchDefaultBrowser
#define lxSetWorkingDirectory wxSetWorkingDirectory
#define lxRenameFile wxRenameFile
#define lxLaunchDefaultApplication wxLaunchDefaultApplication


#define lxSysErrorMsg wxSysErrorMsg
#define lxSysErrorCode wxSysErrorCode

#define lxMOUSE_BTN_LEFT wxMOUSE_BTN_LEFT

#define lxEXEC_SYNC wxEXEC_SYNC
#define lxEXEC_ASYNC wxEXEC_ASYNC

#define lxRED wxRED
#define lxBLUE wxBLUE

#define lxCURSOR_CROSS wxCURSOR_CROSS
#define lxCURSOR_ARROW wxCURSOR_ARROW
#define lxCURSOR_SIZENWSE wxCURSOR_SIZENWSE
#define lxCURSOR_SIZING wxCURSOR_SIZING
#define lxCURSOR_SIZEWE wxCURSOR_SIZEWE
#define lxCURSOR_SIZENS wxCURSOR_SIZENS

#define lxSize wxSize

#define lxFONTFAMILY_TELETYPE wxFONTFAMILY_TELETYPE
#define lxFONTSTYLE_NORMAL wxFONTSTYLE_NORMAL
#define lxFONTWEIGHT_BOLD wxFONTWEIGHT_BOLD 
#define lxFONTWEIGHT_NORMAL wxFONTWEIGHT_NORMAL 
#define lxFONTFAMILY_DEFAULT wxFONTFAMILY_DEFAULT


#define lxSOUND_ASYNC wxSOUND_ASYNC
#define lxSOUND_LOOP wxSOUND_LOOP

#define lxFD_OPEN wxFD_OPEN
#define lxFD_SAVE wxFD_SAVE
#define lxFD_CHANGE_DIR wxFD_CHANGE_DIR

#define lxC2S_HTML_SYNTAX wxC2S_HTML_SYNTAX

#define lxEXEC_MAKE_GROUP_LEADER wxEXEC_MAKE_GROUP_LEADER

#define lxConvUTF8 wxConvUTF8

#define lxRect wxRect
#define lxALIGN_LEFT wxALIGN_LEFT
#define lxALIGN_RIGHT wxALIGN_RIGHT
#define lxALIGN_CENTER_VERTICAL wxALIGN_CENTER_VERTICAL
#define lxALIGN_CENTER wxALIGN_CENTER

#define LXK_SHIFT WXK_SHIFT
#define LXK_CONTROL WXK_CONTROL
#define LXK_RIGHT WXK_RIGHT
#define LXK_LEFT WXK_LEFT
#define LXK_DOWN WXK_DOWN
#define LXK_UP WXK_UP

lxBitmap * lxGetBitmapRotated(lxImage *image, CWindow * win, int orientation); 

lxString lxGetUserDataDir(lxString appname="");
lxString lxGetTempDir(lxString appname="");
lxString lxGetExecutablePath(lxString appname="");

bool lxZipDir(const lxString &in_dirname, const lxString &out_filename);
bool lxUnzipDir(const lxString &in_filename, const lxString &out_dirname);

bool lxRemoveFile(const char* fname);
bool lxRemoveDir(const char* dirname);
bool lxCreateDir(const char * dirname);


#endif	/* LXUTILS_H */
