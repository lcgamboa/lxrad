
#include"layout5.h"
#include"layout5_d.cc"

CPWindow5 Window5;

//Implementation

#include<errno.h>
#include<sys/stat.h>

#include"layout1.h"
#include"layout2.h"


void
CPWindow5::checkbox1_EvOnCheckBox(CControl * control)
{
  checkbox2.SetCheck (!checkbox1.GetCheck ());

  if (checkbox1.GetCheck ())
    {
      button1.SetEnable (true);
      button2.SetEnable (false);
      edit1.SetEnable (true);
      edit2.SetEnable (false);
      edit3.SetEnable (false);
    }
  else
    {
      button1.SetEnable (false);
      button2.SetEnable (true);
      edit1.SetEnable (false);
      edit2.SetEnable (true);
      edit3.SetEnable (true);
    }
};

void
CPWindow5::checkbox2_EvOnCheckBox(CControl * control)
{
  checkbox1.SetCheck (!checkbox2.GetCheck ());

  if (checkbox2.GetCheck ())
    {
      button1.SetEnable (false);
      button2.SetEnable (true);
      edit1.SetEnable (false);
      edit2.SetEnable (true);
      edit3.SetEnable (true);
    }
  else
    {
      button1.SetEnable (true);
      button2.SetEnable (false);
      edit1.SetEnable (true);
      edit2.SetEnable (false);
      edit3.SetEnable (false);
    }
};

void
CPWindow5::button1_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state)
{
  if (filedialog1.Run ())
    {
      edit1.SetText (filedialog1.GetFileName ());
    };
};

void
CPWindow5::button2_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state)
{
  if (dirdialog1.Run ())
    {
      edit2.SetText (dirdialog1.GetDirName ());
    };
};

void
CPWindow5::button3_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state)
{
  operation = wxT("editar");

  if (checkbox1.GetCheck ())
    {
      if (edit1.GetText ().size () > 0)
	{
	  WN = 1;
	  Window2.SetAux(1);
	  Window2.ListPropierties (&Window2);
	  Window2.DestroyChilds ();
	  Window2.Reset ();
	  PDir = dirname (filedialog1.GetFileName ());
	  if (!Window2.LoadProject (dirname (filedialog1.GetFileName ()), basename (filedialog1.GetFileName ())))
	    {
	      return;
	    };
	  Window1.menu1_Windows.DestroyChilds ();
	  for (int n = 1; n <= PNW; n++)
	    {
	      CItemMenu *im;
	      im = new CItemMenu;
	      im->SetText (wxT("Window") + itoa (n));
	      im->SetName (String(wxT("pmenu4_"))+wxT("Window") + itoa (n));
	      im->SetTag (n);
	      im->SetFOwner (this);
              im->EvMenuActive = EVMENUACTIVE & CPWindow1::menu1_Windows_Windowx_EvMenuActive;
	      Window1.menu1_Windows.CreateChild (im);
	    };
	  Save = false;
	}
      else
	{
	  Message (wxT("Choose one file!"));
	  return;
	};
    }
  else
    {
      if (edit3.GetText ().size () > 0)
	{
	  if (edit2.GetText ().size () > 0)
	    {
	      WN = 1;
	      PNW = 1;
	      PName = edit3.GetText ();
	      PDir = edit2.GetText () + wxT("/") + PName;
	      POptions = wxT("-Wall -O2");
	      Window1.menu1_Windows.DestroyChilds ();
	      Window2.ListPropierties (&Window2);
	      Window2.DestroyChilds ();
	      Window2.Reset ();
	      Window2.SetName (wxT("window1"));
	      Window2.SetX (340);
	      Window2.SetY (40);
	      Window2.SetWidth (400);
	      Window2.SetHeight (400);
	      Window2.SetTitle (PName);
	      Window2.SetAux(1);
	      if (wxMkdir (PDir) != true)
		{
		  Message (wxSysErrorMsg(wxSysErrorCode()));
		  return;
		};
	      Window2.MakeOrUpdateFiles (false);
	      Save = true;
	    }
	  else
	    {
	      Message (wxT("Write Project Name!"));
	      return;
	    };
	}
      else
	{
	  Message (wxT("Choose one dir!"));
	  return;
	};
    };
  HideExclusive ();
};

void
CPWindow5::button4_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state)
{
  HideExclusive ();
  Window1.WDestroy ();
};


void
CPWindow5::_EvOnCreate(CControl * control)
{
  edit1.SetText (dirname (filedialog1.GetFileName ()) + wxT("/untitled.prj_lxrad"));
  edit2.SetText (dirname (filedialog1.GetFileName ()));
  edit3.SetText (wxT("untitled"));
};



