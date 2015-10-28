
#include"layout6.h"
#include"layout6_d.cc"

CPWindow6 Window6;

//Implementation

#include"layout2.h"

void
CPWindow6::combo1_EvOnComboChange(CControl * control)
{

  if (combo1.GetSelectedItem ().compare (Window2.GetName ()) == 0)
    {
      Window2.SetControlOnFocus (NULL);
      Window2.ListPropierties (&Window2);
    }
  else
    {
      CControl *ctrl = NULL;
      if (combo1.GetSelectedItem ().size () > 0)
	ctrl = Window2.GetChildByName (combo1.GetSelectedItem ());

      if (ctrl == NULL)
      {
	ctrl = &Window2;
      }
 
      if (ctrl != &Window2)
      { 
      	Window2.SetControlOnFocus (ctrl);
      }  
      
      //printf("ListPropierties (%ls)\n",ctrl->GetName().char_str()); 
      Window2.ListPropierties (ctrl);
    };

};









