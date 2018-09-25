#ifndef CPWINDOW1 
#define CPWINDOW1

#include"../include/lxrad.h"
#include<wx/textfile.h>

class CPWindow1:public CPWindow
{
  public:
  /*#Controls*/
  CMenu menu1;
  CPMenu menu1_File;
  CPMenu menu1_Edit;
  CPMenu menu1_Project;
  CPMenu menu1_Windows;
  CPMenu menu1_Help;
  CItemMenu menu1_File_NewProject;
  CItemMenu menu1_File_NewWindow;
  CItemMenu menu1_File_Save;
  CItemMenu menu1_File_Preferences;
  CItemMenu menu1_File_Exit;
  CItemMenu menu1_Edit_Options;
  CItemMenu menu1_Edit_Clear;
  CItemMenu menu1_Edit_DeleteControl;
  CItemMenu menu1_Edit_IncludeFiles;
  CItemMenu menu1_Project_Run;
  CItemMenu menu1_Project_Build;
  CItemMenu menu1_Project_Clean;
  CItemMenu menu1_Project_EditSource;
  CItemMenu menu1_Project_Debug;
  CItemMenu menu1_Help_Contents;
  CItemMenu menu1_Help_Reference;
  CItemMenu menu1_Help_About;
  CItemMenu menu1_Edit_IncludeLibs;
  /*#Events*/
  void _EvOnCreate(CControl * control);
  void menu1_File_NewProject_EvMenuActive(CControl * control);
  void menu1_File_NewWindow_EvMenuActive(CControl * control);
  void menu1_File_Save_EvMenuActive(CControl * control);
  void menu1_File_Preferences_EvMenuActive(CControl * control);
  void menu1_File_Exit_EvMenuActive(CControl * control);
  void menu1_Edit_Options_EvMenuActive(CControl * control);
  void menu1_Edit_Clear_EvMenuActive(CControl * control);
  void menu1_Edit_DeleteControl_EvMenuActive(CControl * control);
  void menu1_Edit_IncludeFiles_EvMenuActive(CControl * control);
  void menu1_Project_Run_EvMenuActive(CControl * control);
  void menu1_Project_Build_EvMenuActive(CControl * control);
  void menu1_Project_Clean_EvMenuActive(CControl * control);
  void menu1_Project_EditSource_EvMenuActive(CControl * control);
  void menu1_Project_Debug_EvMenuActive(CControl * control);
  void menu1_Help_Contents_EvMenuActive(CControl * control);
  void menu1_Help_Reference_EvMenuActive(CControl * control);
  void menu1_Help_About_EvMenuActive(CControl * control);
  void menu1_Edit_IncludeLibs_EvMenuActive(CControl * control);

  /*#Others*/
  void menu1_Windows_Windowx_EvMenuActive(CControl * control);
  void MouseButtonClick (CControl * control, uint button, uint x, uint y, uint state);
  CPWindow1(void);
};

extern CPWindow1 Window1 ;

extern int WN;
extern String Version;
extern int PNW;
extern String PName;
extern String PDir;
extern String POptions;
extern String PLibs;
extern String PIncludeFile;
extern bool Save;
extern bool Move;
extern String operation;
extern String Browser;
extern String Editor;
extern String Debuger;
extern String Home;


#endif /*#CPWINDOW1*/

