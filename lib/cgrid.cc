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

#include"../include/cgrid.h"
#include <wx/grid.h>



// CGrid___________________________________________________________

CGrid::CGrid (void)
{
  Rows=2;
  Cols=2;
  ARow=1;
  ACol=1;
  Rsize=25;
  Csize=60;
  RLsize=60;
  CLsize=25;
  Ronly=0;	
  DragRs=1;
  SetX (10);
  SetY (10);
  SetWidth (160);
  SetHeight (130);
  SetClass (wxT("CGrid"));
  EvOnGridCellLeftClick = NULL;
  EvOnGridCellRightClick = NULL;
  EvOnGridSelectCell = NULL;
};

CGrid::~CGrid (void)
{
};




int
CGrid::Create (CControl * control)
{
  Win = control->GetWin ();
  
    Widget = new wxGrid(control->GetWidget (),GetWid(),wxPoint(GetX(),GetY()),wxSize(GetWidth(),GetHeight()));
  
   ((wxGrid*)Widget)->CreateGrid(Rows,Cols);
   ((wxGrid*)Widget)->EnableEditing(!Ronly);
   ((wxGrid*)Widget)->SetDefaultRowSize(Rsize,true);
   ((wxGrid*)Widget)->SetDefaultColSize(Csize,true);
   ((wxGrid*)Widget)->SetRowLabelSize(RLsize);
   ((wxGrid*)Widget)->SetColLabelSize(CLsize);
   ((wxGrid*)Widget)->EnableDragGridSize(DragRs);  
    

    Widget->Bind(wxEVT_GRID_CELL_LEFT_CLICK,&CGrid::Event,this,GetWid()); 
    Widget->Bind(wxEVT_GRID_CELL_RIGHT_CLICK,&CGrid::Event,this,GetWid()); 
    Widget->Bind(wxEVT_GRID_SELECT_CELL,&CGrid::Event,this,GetWid()); 
    
  return CControl::Create (control);
};

int 
CGrid::CEvent (int event)
{
if(event == wxEVT_GRID_CELL_LEFT_CLICK)return lxEVT_GRID_CELL_LEFT_CLICK;
if(event == wxEVT_GRID_CELL_RIGHT_CLICK)return lxEVT_GRID_CELL_RIGHT_CLICK;
if(event == wxEVT_GRID_SELECT_CELL)return lxEVT_GRID_SELECT_CELL;

return CControl::CEvent(event);
}


//FIXME clean this code
void
CGrid::Event (wxEvent & event)
{
//activate event in control
      switch (CEvent(event.GetEventType()))
	{
	case lxEVT_GRID_CELL_LEFT_CLICK:
          ARow= ((wxGridEvent*)&event)->GetRow();
          ACol= ((wxGridEvent*)&event)->GetCol();
	  if ((FOwner) && (EvOnGridCellLeftClick))
	    (FOwner->*EvOnGridCellLeftClick) (this);
	 return;
	  break;
	case lxEVT_GRID_CELL_RIGHT_CLICK:
          ARow= ((wxGridEvent*)&event)->GetRow();
          ACol= ((wxGridEvent*)&event)->GetCol();
	  if ((FOwner) && (EvOnGridCellRightClick))
	    (FOwner->*EvOnGridCellRightClick) (this);
	 return;
	  break;
	case lxEVT_GRID_SELECT_CELL:
          ARow= ((wxGridEvent*)&event)->GetRow();
          ACol= ((wxGridEvent*)&event)->GetCol();
	  if ((FOwner) && (EvOnGridSelectCell))
	    (FOwner->*EvOnGridSelectCell) (this);
	 return;
	  break;
	default:
            //return CControl::Event (widget, event);
	  break;
	};

};




lxStringList
CGrid::GetContext (void)
{
  CControl::GetContext ();
  Context.AddLine (xml_out (wxT("RowsCount"), wxT("Int"), itoa(GetRowsCount ())));
  Context.AddLine (xml_out (wxT("ColsCount"), wxT("Int"), itoa(GetColsCount ())));
  Context.AddLine (xml_out (wxT("ReadOnly"), wxT("Int"), itoa(GetReadOnly ())));
  Context.AddLine (xml_out (wxT("EnableDragGridSize"), wxT("Int"), itoa(GetEnableDragGridSize ())));
  Context.AddLine (xml_out (wxT("DefaultRowSize"), wxT("Int"), itoa(GetDefaultRowSize ())));
  Context.AddLine (xml_out (wxT("DefaultColSize"), wxT("Int"), itoa(GetDefaultColSize ())));
  Context.AddLine (xml_out (wxT("RowLabelSize"), wxT("Int"), itoa(GetRowLabelSize ())));
  Context.AddLine (xml_out (wxT("ColLabelSize"), wxT("Int"), itoa(GetColLabelSize ())));

  Context.AddLine (xml_out (wxT("EvOnGridCellLeftClick"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnGridCellRightClick"), wxT("Event"), btoa (GetEv ())));
  Context.AddLine (xml_out (wxT("EvOnGridSelectCell"), wxT("Event"), btoa (GetEv ())));

  return Context;
};

void
CGrid::SetContext (lxStringList context)
{
  lxString name, type, value;
  CControl::SetContext (context);
  for (uint i = 0; i < context.GetLinesCount (); i++)
    {
      xml_in (Context.GetLine (i), name, type, value);
      if (name.compare (wxT("RowsCount")) == 0)
	SetRowsCount (atoi(value));
      if (name.compare (wxT("ColsCount")) == 0)
	SetColsCount (atoi(value));
      if (name.compare (wxT("ReadOnly")) == 0)
	SetReadOnly (atoi(value));
      if (name.compare (wxT("EnableDragGridSize")) == 0)
	SetEnableDragGridSize (atoi(value));
      if (name.compare (wxT("DefaultRowSize")) == 0)
	SetDefaultRowSize (atoi(value));
      if (name.compare (wxT("DefaultColSize")) == 0)
	SetDefaultColSize (atoi(value));
      if (name.compare (wxT("RowLabelSize")) == 0)
	SetRowLabelSize (atoi(value));
      if (name.compare (wxT("ColLabelSize")) == 0)
	SetColLabelSize (atoi(value));

      if (name.compare (wxT("EvOnGridCellLeftClick")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnGridCellRightClick")) == 0)
	SetEv (atob (value));
      if (name.compare (wxT("EvOnGridSelectCell")) == 0)
	SetEv (atob (value));
    };
};

//propiedades
void 
CGrid::SetRowsCount (int rows)
{
  //Rows=rows;  
  if ((Widget != NULL)&&(Rows != rows))
  {
    if(rows > Rows)
    {
      ((wxGrid*)Widget)->AppendRows(rows-Rows);
    }
    else
    {
      ((wxGrid*)Widget)->DeleteRows(Rows,Rows-rows);
    }
    ((wxGrid*)Widget)->ForceRefresh();
  }
  Rows=rows;  
 
};

int 
CGrid::GetRowsCount (void)
{
  return Rows;
};

void 
CGrid::SetColsCount (int cols)
{
  //Cols=cols;  
    if ((Widget != NULL)&&(Cols != cols))
  {
    if(cols > Cols)
    {
      ((wxGrid*)Widget)->AppendCols(cols-Cols);
    }
    else
    {
      ((wxGrid*)Widget)->DeleteCols(Cols,Cols-cols);
    }
    ((wxGrid*)Widget)->ForceRefresh();
  }
  Cols=cols;  
  
};

int 
CGrid::GetColsCount (void)
{
  return Cols;
};

void 
CGrid::SetCell (int row, int col, lxString val)
{
  if (Widget != NULL)
   ((wxGrid*)Widget)->SetCellValue( row, col, val);
};

lxString 
CGrid::GetCell (int row, int col)
{
  if (Widget != NULL)
   return ((wxGrid*)Widget)->GetCellValue( row, col);

  return wxT("");
};
  
void 
CGrid::SetReadOnly (int ronly)
{
  Ronly=ronly;  
  if (Widget != NULL)
     ((wxGrid*)Widget)->EnableEditing(!Ronly);
};

int 
CGrid::GetReadOnly (void)
{
  return Ronly; 
};

void 
CGrid::SetDefaultRowSize(int height)
{
  Rsize=height;
  if (Widget != NULL)
    ((wxGrid*)Widget)->SetDefaultRowSize(Rsize,true);
}

int 
CGrid::GetDefaultRowSize (void)
{
  return Rsize;
};


void 
CGrid::SetDefaultColSize(int width)
{
  Csize=width;
  if (Widget != NULL)
   ((wxGrid*)Widget)->SetDefaultColSize(Csize,true);
}

int 
CGrid::GetDefaultColSize (void)
{
  return Csize;
};

void 
CGrid::SetRowLabelSize(int height)
{
  RLsize=height;
  if (Widget != NULL)
    ((wxGrid*)Widget)->SetRowLabelSize(RLsize);
}

int 
CGrid::GetRowLabelSize (void)
{
  return RLsize;
};

void 
CGrid::SetColLabelSize(int width)
{
  CLsize=width;
  if (Widget != NULL)
    ((wxGrid*)Widget)->SetColLabelSize(CLsize);
} 

int 
CGrid::GetColLabelSize (void)
{
  return CLsize;
};

void 
CGrid::SetEnableDragGridSize(int enable)
{
   DragRs=enable;
  if (Widget != NULL)
    ((wxGrid*)Widget)->EnableDragGridSize(DragRs);  
};

int 
CGrid::GetEnableDragGridSize(void)
{
  return DragRs; 
};

int
CGrid::GetActiveCol(void)
{
  return ACol;
}

int
CGrid::GetActiveRow(void)
{
  return ARow;
}


void 
CGrid::SetCellBgColor(int row, int col, const wxColour& color)
{
  if (Widget != NULL)
  {
    ((wxGrid*)Widget)->SetCellBackgroundColour(row,col,color);
    ((wxGrid*)Widget)->ForceRefresh();
  }

};

void 
CGrid::SetRowSize(int row, int height)
{
  if (Widget != NULL)
    ((wxGrid*)Widget)->SetRowSize(row,height);
};


void 
CGrid::SetColSize(int col, int height)
{
  if (Widget != NULL)
    ((wxGrid*)Widget)->SetColSize(col,height);
};




