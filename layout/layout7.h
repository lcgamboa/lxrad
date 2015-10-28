#ifndef CPWINDOW7 
#define CPWINDOW7

#include"../include/lxrad.h"

class CPWindow7:public CPWindow
{
  public:
  /*#Controls*/
  CButton button1;
  CButton button2;
  CList list1;
  CButton button3;
  CButton button4;
  /*#Events*/
  void button1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button2_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button3_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);
  void button4_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state);

  /*#Others*/
  CList *cl;
  CCombo *cc;
  CStatusbar *cs;
  void  StringListMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  CPWindow7(void);
};
 extern CPWindow7 Window7 ;

#endif /*#CPWINDOW7*/

