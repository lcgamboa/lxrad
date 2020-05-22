
#include"../include/lxrad.h"

CControl *
newcontrolbycname (String controltype)
{
  CControl *ncontrol = NULL;

  if (controltype.compare (wxT("CButton")) == 0)
    {
      ncontrol = new CButton;
    }
  if (controltype.compare (wxT("CToolButton")) == 0)
    {
      ncontrol = new CToolButton;
    }
  if (controltype.compare (wxT("CXpmButton")) == 0)
    {
      ncontrol = new CXpmButton;
    }
  if (controltype.compare (wxT("CEdit")) == 0)
    {
      ncontrol = new CEdit;
    }
  if (controltype.compare (wxT("CLabel")) == 0)
    {
      ncontrol = new CLabel;
    }
  if (controltype.compare (wxT("CCheckBox")) == 0)
    {
      ncontrol = new CCheckBox;
    }
  if (controltype.compare (wxT("CDraw")) == 0)
    {
      ncontrol = new CDraw;
    }
  if (controltype.compare (wxT("CImage")) == 0)
    {
      ncontrol = new CImage;
    }
  if (controltype.compare (wxT("CList")) == 0)
    {
      ncontrol = new CList;
    }
  if (controltype.compare (wxT("CFileList")) == 0)
    {
      ncontrol = new CFileList;
    }
  if (controltype.compare (wxT("CMenu")) == 0)
    {
      ncontrol = new CMenu;
    }
  if (controltype.compare (wxT("CPMenu")) == 0)
    {
      ncontrol = new CPMenu;
    }
  if (controltype.compare (wxT("CScroll")) == 0)
    {
      ncontrol = new CScroll;
    }
  if (controltype.compare (wxT("CCombo")) == 0)
    {
      ncontrol = new CCombo;
    }
  if (controltype.compare (wxT("CText")) == 0)
    {
      ncontrol = new CText;
    }
  if (controltype.compare (wxT("CFileDialog")) == 0)
    {
      ncontrol = new CFileDialog;
    }
  if (controltype.compare (wxT("CDirDialog")) == 0)
    {
      ncontrol = new CDirDialog;
    }
  if (controltype.compare (wxT("CItemMenu")) == 0)
    {
      ncontrol = new CItemMenu;
    }
  if (controltype.compare (wxT("CTimer")) == 0)
    {
      ncontrol = new CTimer;
    }
  if (controltype.compare (wxT("CPanel")) == 0)
    {
      ncontrol = new CPanel;
    }
  if (controltype.compare (wxT("CGauge")) == 0)
    {
      ncontrol = new CGauge;
    };
#ifndef _NO_ADVANCED
  if (controltype.compare (wxT("CSyledText")) == 0)
    {
      ncontrol = new CStyledText;
    }
  if (controltype.compare (wxT("CGrid")) == 0)
    {
      ncontrol = new CGrid;
    }
  if (controltype.compare (wxT("CHtml")) == 0)
    {
      ncontrol = new CHtml;
    }
#endif  
  if (controltype.compare (wxT("CStatusbar")) == 0)
    {
      ncontrol = new CStatusbar;
    }
  if (controltype.compare (wxT("CSpin")) == 0)
    {
      ncontrol = new CSpin;
    }
  if (controltype.compare (wxT("CSpind")) == 0)
    {
      ncontrol = new CSpind;
    }
  if (controltype.compare (wxT("CToggleButton")) == 0)
    {
      ncontrol = new CToggleButton;
    }
#ifndef __WXX11__ 	    
  if (controltype.compare (wxT("CColorDialog")) == 0)
    {
      ncontrol = new CColorDialog;
    }
#endif
  if (controltype.compare (wxT("CThread")) == 0)
    {
      ncontrol = new CThread;
    }

  if(ncontrol == NULL)
  {  
    eprint (wxT("Unknown Controltype \"") + controltype + wxT("\"!\n"));
    exit (-1);
  }

  return ncontrol;
};
