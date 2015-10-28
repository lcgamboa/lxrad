
#include"layout4.h"
#include"layout4_d.cc"

CPWindow4 Window4;

//Implementation

#include"layout2.h"
#include"layout6.h"

void
CPWindow4::checkboxclick (CControl * control)
{
  CStringList List;
  CCheckBox *cb;
  CControl *ctrl;

  for (int c = 0; c <= Window4.GetChildCount (); c++)
    {
      cb = (CCheckBox *) (Window4.GetChild (c));
      List.AddLine (xml_out (cb->GetText (), wxT("any"), btoa (cb->GetCheck ())));
    };
  
  ctrl= Window2.GetChildByName(Window6.combo1.GetText());

  //if (Window2.GetControlOnFocus () == NULL)
  if ((ctrl == NULL)||(ctrl == &Window2))
    dynamic_cast < CObject * >(&Window2)->SetContext (List);
  else
    dynamic_cast < CObject * >(ctrl)->SetContext (List);
};





