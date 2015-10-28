
#include"imageview1.h"
#include"imageview1_d.cc"

CPWindow1 Window1;

//Implementation


void
CPWindow1::filelist1_EvFileListSelectFile(CControl * control)
{ 
  String file=filelist1.GetSelectedFile();
	
  if((file.find(wxT(".gif")) >0)||
     (file.find(wxT(".jpg")) >0)||
     (file.find(wxT(".png")) >0)||
     (file.find(wxT(".tiff"))>0)||
     (file.find(wxT(".ps"))  >0)||
     (file.find(wxT(".bmp")) >0)||
     (file.find(wxT(".xpm")) >0)||
     (file.find(wxT(".ppm")) >0)||
     (file.find(wxT(".GIF")) >0)||
     (file.find(wxT(".JPG")) >0)||
     (file.find(wxT(".PNG")) >0)||
     (file.find(wxT(".TIFF"))>0)||
     (file.find(wxT(".PS"))  >0)||
     (file.find(wxT(".BMP")) >0)||
     (file.find(wxT(".XPM")) >0)||
     (file.find(wxT(".PPM")) >0))
       draw1.SetImgFileName(filelist1.GetSelectedFile());
};

void
CPWindow1::menu1_File_Exit_EvMenuActive(CControl * control)
{
  WDestroy();
};

void
CPWindow1::menu1_Help_About_EvMenuActive(CControl * control)
{
  Message(wxT("Create By LCGamboa"));
};






