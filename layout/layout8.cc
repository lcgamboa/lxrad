
#include"layout8.h"
#include"layout8_d.cc"

CPWindow8 Window8;

//Implementation

#include"layout2.h"
#include"layout6.h"


void
CPWindow8::MenuItensMouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{

  Window8.menu = dynamic_cast < CMenu * >(Window2.GetChildByName(Window6.combo1.GetText()));
  Window8.pmenu = dynamic_cast < CPMenu * >(Window2.GetChildByName(Window6.combo1.GetText()));

      if((Window8.menu != NULL)||(Window8.pmenu != NULL))
      {
      int f;
      String litems;

      if (Window8.menu)
	litems = Window8.menu->GetMenuItems ();
      else	  
	litems = Window8.pmenu->GetMenuItems ();


      Window8.list1.DeleteItems ();

      f = litems.find (wxT(","));
      while (f > 0)
	{
	  Window8.list1.AddItem (litems.substr (0, f));
	  litems = litems.substr (f + 1, litems.size () - f - 1);
	  f = litems.find (wxT(","));
	};

      Window8.ShowExclusive ();
      }
};



void
CPWindow8::button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  String item;

  if (Input (wxT("Item Text"), item))
    {
      list1.AddItem (item);

      if(menu)
      {  
        CPMenu *im;
        im = new CPMenu;

        im->SetVisible (false);
	im->SetName (spacestrip (menu->GetName () + wxT("_") + item));
        im->SetText (item);


        Window2.CreateChild (im);
      }
      else
      { 
        CItemMenu *im;
        im = new CItemMenu;
        
        im->SetVisible (false);
	im->SetName (spacestrip (pmenu->GetName () + wxT("_") + item));
        im->SetText (item);

        Window2.CreateChild (im);
      }  

    };
};

void
CPWindow8::button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  if (menu)
    Window2.DestroyChild (Window2.GetChildByName (spacestrip (menu->GetName ()) + wxT("_") + list1.GetSelectedItem ()));
  else
    Window2.DestroyChild (Window2.GetChildByName (spacestrip (pmenu->GetName ()) + wxT("_") + list1.GetSelectedItem ()));
  list1.DeleteItem (list1.GetSelectedItemN ());
};

void
CPWindow8::button3_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  int ii;
  String item;

  ii = list1.GetSelectedItemN ();
  if (ii > 0)
    {
      item = list1.GetItem (ii - 1);
      list1.SetItem (ii - 1, list1.GetSelectedItem ());
      list1.SetItem (ii, item);
      list1.SetSelectedItemN (ii - 1);
      list1.Draw ();
    };
};

void
CPWindow8::button4_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  int ii;
  String item;
  ii = list1.GetSelectedItemN ();
  if (ii < (list1.GetItemsCount () - 1))
    {
      item = list1.GetItem (ii + 1);
      list1.SetItem (ii + 1, list1.GetSelectedItem ());
      list1.SetItem (ii, item);
      list1.SetSelectedItemN (ii + 1);
      list1.Draw ();
    };
};

void
CPWindow8::button5_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  String items = wxT("");
  for (int c = 0; c < list1.GetItemsCount (); c++)
    {
      items += list1.GetItem (c) + wxT(",");
    };

  if (menu)
    menu->SetMenuItems (items);
  else
    pmenu->SetMenuItems (items);
  HideExclusive ();

  Window2.ListPropierties (Window2.GetControlOnFocus ());
};

void
CPWindow8::button6_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  HideExclusive ();
};






