#ifndef CPWINDOW6 
#define CPWINDOW6

#include"../include/lxrad.h"

class CPWindow6:public CPWindow
{
  public:
  /*#Controls*/
  CCombo combo1;
  /*#Events*/
  void combo1_EvOnComboChange(CControl * control);

  /*#Others*/
  CPWindow6(void);
};
 extern CPWindow6 Window6 ;

#endif /*#CPWINDOW6*/

