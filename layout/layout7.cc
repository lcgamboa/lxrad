
/* Menu Itens Edit Window*/

#include"layout7.h"
#include"layout7_d.cc"

CPWindow7 Window7;

//Implementation

#include"layout2.h"
#include"layout6.h"

void
CPWindow7::lxStringListMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state)
{

  Window7.cl = dynamic_cast < CList * >(Window2.GetChildByName(Window6.combo1.GetText()));
  Window7.cc = dynamic_cast < CCombo * >(Window2.GetChildByName(Window6.combo1.GetText()));
  Window7.cs = dynamic_cast < CStatusbar * >(Window2.GetChildByName(Window6.combo1.GetText()));

  if (Window7.cl != NULL)
    {
      Window7.list1.SetItems (Window7.cl->GetItems ());
      Window7.ShowExclusive ();
    };

  if (Window7.cc != NULL)
    {
      Window7.list1.SetItems (Window7.cc->GetItems ());
      Window7.ShowExclusive ();
    };
  
  if (Window7.cs != NULL)
    {
      Window7.list1.SetItems (Window7.cs->GetFields ());
      Window7.ShowExclusive ();
    };
};



void
CPWindow7::button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  lxString item;
  if (Input (wxT("Add lxString: "), item))
    {
      list1.AddItem (item);
    };
};

void
CPWindow7::button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  list1.DeleteItem (list1.GetSelectedItemN ());
};

void
CPWindow7::button3_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  list1.DeleteItems ();
};

void
CPWindow7::button4_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  HideExclusive ();
  if(cl)cl->SetItems(list1.GetItems());
  if(cc)cc->SetItems(list1.GetItems());
  if(cs)cs->SetFields(list1.GetItems());
};






