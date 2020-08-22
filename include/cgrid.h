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
 * \file cgrid.h
 * \author Luis Claudio Gamboa Lopes
 * \date 06-25-2010
 */

#ifndef CGRID
#define CGRID

#include"ccontrol.h"
#include"cwindow.h"

/** \brief Grid Control.
 *
 * Generic Grid Control Class.
 */

class CGrid:public CControl
{
protected:
  int Rows;
  int Cols;   
  int ARow;   /**< Active Row */ 
  int ACol;   /**< Active Column */
  int Rsize;  /**< Defaukt row size */
  int Csize;  /**< Default col size */
  int RLsize; /**< Default Label row size */
  int CLsize; /**< Default LAbel col size*/
  int Ronly;  /**< Grid ReadOnly Flag */
  int DragRs; /**< Drag Resize Flag */	
  int CEvent (int event);
public:
  CGrid (void);
   ~CGrid (void);
  int Create (CControl * control);
  lxStringList GetContext (void);
  void SetContext (lxStringList context);
  void Event (wxEvent & event);
  //propiedades
  void SetRowsCount (int rows);
  int GetRowsCount (void);
  void SetColsCount (int cols);
  int GetColsCount (void);
  void SetReadOnly (int ronly);
  int GetReadOnly (void);
  void SetDefaultRowSize(int height);
  int GetDefaultRowSize (void);
  void SetDefaultColSize(int width);
  int GetDefaultColSize (void);
  void SetRowLabelSize(int height);
  int GetRowLabelSize (void);
  void SetColLabelSize(int width);
  int GetColLabelSize (void);
  void SetEnableDragGridSize(int enable);
  int GetEnableDragGridSize(void);
  //runtime 
  void SetCell (int row, int col, lxString val);
  lxString GetCell (int row, int col);
  void SetCellBgColor(int row, int col, const wxColour& color);
  void SetRowSize(int row, int height);
  void SetColSize(int col, int height);
  int GetActiveCol (void);
  int GetActiveRow (void);
  //events
  void (CControl::*EvOnGridCellLeftClick) (CControl * control);
  void (CControl::*EvOnGridCellRightClick) (CControl * control);
  void (CControl::*EvOnGridSelectCell) (CControl * control);
};

#endif
