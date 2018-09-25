#ifndef CPWINDOW5 
#define CPWINDOW5

#include"../include/lxrad.h"

class CPWindow5:public CPWindow
{
  public:
  /*#Controls*/
  CCheckBox checkbox1;
  CCheckBox checkbox2;
  CLabel string1;
  CLabel string2;
  CLabel string3;
  CEdit edit1;
  CEdit edit2;
  CEdit edit3;
  CButton button1;
  CButton button2;
  CButton button3;
  CButton button4;
  CFileDialog filedialog1;
  CDirDialog dirdialog1;
  /*#Events*/
  void _EvOnCreate(CControl * control);
  void checkbox1_EvOnCheckBox(CControl * control);
  void checkbox2_EvOnCheckBox(CControl * control);
  void button1_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  void button2_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  void button3_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  void button4_EvMouseButtonRelease(CControl * control, uint button, uint x, uint y,uint state);
  void Filedialog1OnClose (int retId);
  void Dirdialog1OnClose (int retId);

  /*#Others*/
  CPWindow5(void);
};
 extern CPWindow5 Window5 ;

#endif /*#CPWINDOW5*/

