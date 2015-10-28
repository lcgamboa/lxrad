

#include"../include/lxrad.h"
#include"window3.h"


CJanela3 Janela3;

//implemetation
#include"window3_d.cc"

void
CJanela3::Window_MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{
  Janela3.WDestroy ();
//  Janela1.SetFocus();
};
