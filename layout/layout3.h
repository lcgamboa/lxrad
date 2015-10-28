#ifndef CPWINDOW3 
#define CPWINDOW3

#include"../include/lxrad.h"

class CPWindow3:public CPWindow
{
  public:
  /*#Controls*/
  /*#Events*/

  /*#Others*/
  void editfocusout (CControl * control);
  void FileMouseButtonRelease (CControl * control, uint button, uint x, uint y,uint state);
  CPWindow3(void);
};
 extern CPWindow3 Window3 ;

#endif /*#CPWINDOW3*/

