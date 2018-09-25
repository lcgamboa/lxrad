
#include"layout3.h"
#include"layout3_d.cc"

CPWindow3 Window3;

//Implementation

#include"layout1.h"
#include"layout2.h"
#include"layout6.h"

void
CPWindow3::editfocusout (CControl * control)
{
  CStringList List;
  CEdit *ed;
  CLabel *st;
  CControl *ctrl;

  for (int c = 0; c <= Window3.GetChildCount (); c++)
    {
      st = dynamic_cast < CLabel * >(Window3.GetChildByName (wxT("clabel") + itoa (c + 1)));
      ed = dynamic_cast < CEdit * >(Window3.GetChildByName (wxT("cedit") + itoa (c + 1)));
      if ((st) && (ed) && (!ed->GetReadOnly ()))
	List.AddLine (xml_out (st->GetText (), wxT("any"), ed->GetText ()));
    };


  //if (Window2.GetControlOnFocus () == &Window2)
  ctrl= Window2.GetChildByName(Window6.combo1.GetText());
  if ((ctrl == NULL)||(ctrl == &Window2))
    {
      Window2.SetContext (List);
      Window2.SetAux(Window2.GetVisible()); 
    }
  else
    {
/*
#ifdef __UNICODE__
      printf("Set context %ls\n",ctrl->GetName().char_str());  
#else      
      printf("Set context %s\n",ctrl->GetName().char_str());  
#endif
*/
      ctrl->Erase ();
      ctrl->SetContext (List);


      ctrl->SetAux(ctrl->GetVisible()); 
      ctrl->Draw ();
      Window2._EvKeyboardPress(&Window2, 0, 0, 0, 0);
    };

};

void
CPWindow3::FileMouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{
  CToolButton *tb;
  ctrl=control;
  tb = dynamic_cast < CToolButton * >(control);
  if (tb)
    {
      filedialog1.Run ();
    }
}


void
CPWindow3::Filedialog1OnClose (int retId)
{
    CEdit *ed;
    CToolButton *tb;
  
    if (retId)
	{
          tb = dynamic_cast < CToolButton * >(ctrl);
	  ed = dynamic_cast < CEdit * >(GetChildByName (wxT("cedit") + itoa (tb->GetTag ())));
	  if (ed)
	    {
	      ed->SetText (filedialog1.GetFileName ());
	      editfocusout (ctrl);
	    }
	}
}

