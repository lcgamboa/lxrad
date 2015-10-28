#include"../include/lxrad.h"
#include"layout1.h"
#include"layout2.h"
#include"layout3.h"
#include"layout4.h"
#include"layout5.h"
#include"layout6.h"
#include"layout7.h"
#include"layout8.h"
#include"layout9.h"


#include"layout0.h"
#include<unistd.h>

//Program____________________________________________________________
Initialize
{
  Application->Start ();

  Window0.WCreate (100);

  Application->ACreateWindow (&Window1);
  Application->ACreateWindow (&Window2);
  Application->ACreateWindow (&Window4);
  Application->ACreateWindow (&Window3);
  Application->ACreateWindow (&Window6);
  Application->ACreateWindow (&Window7);
  Application->ACreateWindow (&Window8);
  Application->ACreateWindow (&Window9);
  Application->ACreateWindow (&Window5);
  
  Window0.WDestroy ();

  //Window5.ShowExclusive();

  Window5.Show();

  Application->Load ();



  return 0;	
};



















































































































