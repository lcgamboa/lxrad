#ifndef CPWINDOW9 
#define CPWINDOW9

#include"../include/lxrad.h"

class CPWindow9:public CPWindow
{
  public:
  /*#Controls*/
  CList list1;
  CButton button1;
  CButton button2;
  /*#Events*/
  void button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);

  /*#Others*/
  void SubMenuMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  CPWindow9(void);
};
 extern CPWindow9 Window9 ;

#endif /*#CPWINDOW9*/

