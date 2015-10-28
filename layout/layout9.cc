
#include"layout9.h"
#include"layout9_d.cc"

CPWindow9 Window9;

//Implementation

#include"layout2.h"
#include"layout6.h"

void
CPWindow9::SubMenuMouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{
  CControl *ctrl;
  if (Window2.GetChildByName(Window6.combo1.GetText()) != NULL)
    {
      Window9.list1.DeleteItems ();
      Window9.list1.AddItem (wxT("NULL"));
      for (int c = 0; c <= Window2.GetChildCount (); c++)
	{
	  ctrl = Window2.GetChild (c);
	  if (ctrl->GetClass ().compare (wxT("CPMenu")) == 0)
	    Window9.list1.AddItem (ctrl->GetName ());
	};
      Window9.ShowExclusive ();
    };
};


void
CPWindow9::button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  CItemMenu *ctrl = dynamic_cast < CItemMenu * >(Window2.GetControlOnFocus ());
  if (ctrl)
    {
      ctrl->SetSubMenu (dynamic_cast < CPMenu * >(Window2.GetChildByName (Window9.list1.GetSelectedItem ())));
    }
  else
    {
      Window2.GetControlOnFocus ()->SetPopupMenu (dynamic_cast < CPMenu * >(Window2.GetChildByName (Window9.list1.GetSelectedItem ())));
    }

  Window9.HideExclusive ();

  Window2.ListPropierties (Window2.GetControlOnFocus ());
};

void
CPWindow9::button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  Window9.HideExclusive ();
};





