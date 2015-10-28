#ifndef CPWINDOW8 
#define CPWINDOW8

#include"../include/lxrad.h"

class CPWindow8:public CPWindow
{
  public:
  /*#Controls*/
  CList list1;
  CButton button1;
  CButton button2;
  CButton button3;
  CButton button4;
  CButton button5;
  CButton button6;
  /*#Events*/
  void button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button3_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button4_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button5_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button6_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);

  /*#Others*/
  CMenu *menu;
  CPMenu *pmenu;
  void MenuItensMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  CPWindow8(void);
};
 extern CPWindow8 Window8 ;

#endif /*#CPWINDOW8*/

