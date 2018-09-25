CPWindow1::CPWindow1(void)
{
//lxrad automatic generated block start, don't edit below!  
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window1"));
  SetTag(0);
  SetX(23);
  SetY(31);
  SetWidth(707);
  SetHeight(90);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(1);
  SetPopupMenu(NULL);
  SetTitle(wxT("LXRAD Layout -"));
  SetOverrideRedirect(0);
  EvOnCreate=EVONCREATE & CPWindow1::_EvOnCreate;
  //menu1
  menu1.SetFOwner(this);
  menu1.SetClass(wxT("CMenu"));
  menu1.SetName(wxT("menu1"));
  menu1.SetTag(0);
  menu1.SetMenuItems(wxT("File,Edit,Project,Windows,Help,"));
  CreateChild(&menu1);
  //menu1_File
  menu1_File.SetFOwner(this);
  menu1_File.SetClass(wxT("CPMenu"));
  menu1_File.SetName(wxT("menu1_File"));
  menu1_File.SetTag(0);
  menu1_File.SetText(wxT("File"));
  menu1_File.SetMenuItems(wxT("New Project,New Window,Save,Preferences,Exit,"));
  menu1.CreateChild(&menu1_File);
  //menu1_Edit
  menu1_Edit.SetFOwner(this);
  menu1_Edit.SetClass(wxT("CPMenu"));
  menu1_Edit.SetName(wxT("menu1_Edit"));
  menu1_Edit.SetTag(0);
  menu1_Edit.SetText(wxT("Edit"));
  menu1_Edit.SetMenuItems(wxT("Options,Clear,Delete Control,Include Files,Include Libs,"));
  menu1.CreateChild(&menu1_Edit);
  //menu1_Project
  menu1_Project.SetFOwner(this);
  menu1_Project.SetClass(wxT("CPMenu"));
  menu1_Project.SetName(wxT("menu1_Project"));
  menu1_Project.SetTag(0);
  menu1_Project.SetText(wxT("Project"));
  menu1_Project.SetMenuItems(wxT("Run,Build,Clean,Edit Source,Debug,"));
  menu1.CreateChild(&menu1_Project);
  //menu1_Windows
  menu1_Windows.SetFOwner(this);
  menu1_Windows.SetClass(wxT("CPMenu"));
  menu1_Windows.SetName(wxT("menu1_Windows"));
  menu1_Windows.SetTag(0);
  menu1_Windows.SetText(wxT("Windows"));
  menu1_Windows.SetMenuItems(wxT(""));
  menu1.CreateChild(&menu1_Windows);
  //menu1_Help
  menu1_Help.SetFOwner(this);
  menu1_Help.SetClass(wxT("CPMenu"));
  menu1_Help.SetName(wxT("menu1_Help"));
  menu1_Help.SetTag(0);
  menu1_Help.SetText(wxT("Help"));
  menu1_Help.SetMenuItems(wxT("Contents,Reference,About,"));
  menu1.CreateChild(&menu1_Help);
  //menu1_File_NewProject
  menu1_File_NewProject.SetFOwner(this);
  menu1_File_NewProject.SetClass(wxT("CItemMenu"));
  menu1_File_NewProject.SetName(wxT("menu1_File_NewProject"));
  menu1_File_NewProject.SetTag(0);
  menu1_File_NewProject.SetText(wxT("New Project"));
  menu1_File_NewProject.SetSubMenu(NULL);
  menu1_File_NewProject.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_File_NewProject_EvMenuActive;
  menu1_File.CreateChild(&menu1_File_NewProject);
  //menu1_File_NewWindow
  menu1_File_NewWindow.SetFOwner(this);
  menu1_File_NewWindow.SetClass(wxT("CItemMenu"));
  menu1_File_NewWindow.SetName(wxT("menu1_File_NewWindow"));
  menu1_File_NewWindow.SetTag(0);
  menu1_File_NewWindow.SetText(wxT("New Window"));
  menu1_File_NewWindow.SetSubMenu(NULL);
  menu1_File_NewWindow.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_File_NewWindow_EvMenuActive;
  menu1_File.CreateChild(&menu1_File_NewWindow);
  //menu1_File_Save
  menu1_File_Save.SetFOwner(this);
  menu1_File_Save.SetClass(wxT("CItemMenu"));
  menu1_File_Save.SetName(wxT("menu1_File_Save"));
  menu1_File_Save.SetTag(0);
  menu1_File_Save.SetText(wxT("Save"));
  menu1_File_Save.SetSubMenu(NULL);
  menu1_File_Save.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_File_Save_EvMenuActive;
  menu1_File.CreateChild(&menu1_File_Save);
  //menu1_File_Preferences
  menu1_File_Preferences.SetFOwner(this);
  menu1_File_Preferences.SetClass(wxT("CItemMenu"));
  menu1_File_Preferences.SetName(wxT("menu1_File_Preferences"));
  menu1_File_Preferences.SetTag(0);
  menu1_File_Preferences.SetText(wxT("Preferences"));
  menu1_File_Preferences.SetSubMenu(NULL);
  menu1_File_Preferences.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_File_Preferences_EvMenuActive;
  menu1_File.CreateChild(&menu1_File_Preferences);
  //menu1_File_Exit
  menu1_File_Exit.SetFOwner(this);
  menu1_File_Exit.SetClass(wxT("CItemMenu"));
  menu1_File_Exit.SetName(wxT("menu1_File_Exit"));
  menu1_File_Exit.SetTag(0);
  menu1_File_Exit.SetText(wxT("Exit"));
  menu1_File_Exit.SetSubMenu(NULL);
  menu1_File_Exit.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_File_Exit_EvMenuActive;
  menu1_File.CreateChild(&menu1_File_Exit);
  //menu1_Edit_Options
  menu1_Edit_Options.SetFOwner(this);
  menu1_Edit_Options.SetClass(wxT("CItemMenu"));
  menu1_Edit_Options.SetName(wxT("menu1_Edit_Options"));
  menu1_Edit_Options.SetTag(0);
  menu1_Edit_Options.SetText(wxT("Options"));
  menu1_Edit_Options.SetSubMenu(NULL);
  menu1_Edit_Options.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Edit_Options_EvMenuActive;
  menu1_Edit.CreateChild(&menu1_Edit_Options);
  //menu1_Edit_Clear
  menu1_Edit_Clear.SetFOwner(this);
  menu1_Edit_Clear.SetClass(wxT("CItemMenu"));
  menu1_Edit_Clear.SetName(wxT("menu1_Edit_Clear"));
  menu1_Edit_Clear.SetTag(0);
  menu1_Edit_Clear.SetText(wxT("Clear"));
  menu1_Edit_Clear.SetSubMenu(NULL);
  menu1_Edit_Clear.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Edit_Clear_EvMenuActive;
  menu1_Edit.CreateChild(&menu1_Edit_Clear);
  //menu1_Edit_DeleteControl
  menu1_Edit_DeleteControl.SetFOwner(this);
  menu1_Edit_DeleteControl.SetClass(wxT("CItemMenu"));
  menu1_Edit_DeleteControl.SetName(wxT("menu1_Edit_DeleteControl"));
  menu1_Edit_DeleteControl.SetTag(0);
  menu1_Edit_DeleteControl.SetText(wxT("Delete Control"));
  menu1_Edit_DeleteControl.SetSubMenu(NULL);
  menu1_Edit_DeleteControl.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Edit_DeleteControl_EvMenuActive;
  menu1_Edit.CreateChild(&menu1_Edit_DeleteControl);
  //menu1_Edit_IncludeFiles
  menu1_Edit_IncludeFiles.SetFOwner(this);
  menu1_Edit_IncludeFiles.SetClass(wxT("CItemMenu"));
  menu1_Edit_IncludeFiles.SetName(wxT("menu1_Edit_IncludeFiles"));
  menu1_Edit_IncludeFiles.SetTag(0);
  menu1_Edit_IncludeFiles.SetText(wxT("Include Files"));
  menu1_Edit_IncludeFiles.SetSubMenu(NULL);
  menu1_Edit_IncludeFiles.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Edit_IncludeFiles_EvMenuActive;
  menu1_Edit.CreateChild(&menu1_Edit_IncludeFiles);
  //menu1_Project_Run
  menu1_Project_Run.SetFOwner(this);
  menu1_Project_Run.SetClass(wxT("CItemMenu"));
  menu1_Project_Run.SetName(wxT("menu1_Project_Run"));
  menu1_Project_Run.SetTag(0);
  menu1_Project_Run.SetText(wxT("Run"));
  menu1_Project_Run.SetSubMenu(NULL);
  menu1_Project_Run.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Project_Run_EvMenuActive;
  menu1_Project.CreateChild(&menu1_Project_Run);
  //menu1_Project_Build
  menu1_Project_Build.SetFOwner(this);
  menu1_Project_Build.SetClass(wxT("CItemMenu"));
  menu1_Project_Build.SetName(wxT("menu1_Project_Build"));
  menu1_Project_Build.SetTag(0);
  menu1_Project_Build.SetText(wxT("Build"));
  menu1_Project_Build.SetSubMenu(NULL);
  menu1_Project_Build.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Project_Build_EvMenuActive;
  menu1_Project.CreateChild(&menu1_Project_Build);
  //menu1_Project_Clean
  menu1_Project_Clean.SetFOwner(this);
  menu1_Project_Clean.SetClass(wxT("CItemMenu"));
  menu1_Project_Clean.SetName(wxT("menu1_Project_Clean"));
  menu1_Project_Clean.SetTag(0);
  menu1_Project_Clean.SetText(wxT("Clean"));
  menu1_Project_Clean.SetSubMenu(NULL);
  menu1_Project_Clean.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Project_Clean_EvMenuActive;
  menu1_Project.CreateChild(&menu1_Project_Clean);
  //menu1_Project_EditSource
  menu1_Project_EditSource.SetFOwner(this);
  menu1_Project_EditSource.SetClass(wxT("CItemMenu"));
  menu1_Project_EditSource.SetName(wxT("menu1_Project_EditSource"));
  menu1_Project_EditSource.SetTag(0);
  menu1_Project_EditSource.SetText(wxT("Edit Source"));
  menu1_Project_EditSource.SetSubMenu(NULL);
  menu1_Project_EditSource.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Project_EditSource_EvMenuActive;
  menu1_Project.CreateChild(&menu1_Project_EditSource);
  //menu1_Project_Debug
  menu1_Project_Debug.SetFOwner(this);
  menu1_Project_Debug.SetClass(wxT("CItemMenu"));
  menu1_Project_Debug.SetName(wxT("menu1_Project_Debug"));
  menu1_Project_Debug.SetTag(0);
  menu1_Project_Debug.SetText(wxT("Debug"));
  menu1_Project_Debug.SetSubMenu(NULL);
  menu1_Project_Debug.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Project_Debug_EvMenuActive;
  menu1_Project.CreateChild(&menu1_Project_Debug);
  //menu1_Help_Contents
  menu1_Help_Contents.SetFOwner(this);
  menu1_Help_Contents.SetClass(wxT("CItemMenu"));
  menu1_Help_Contents.SetName(wxT("menu1_Help_Contents"));
  menu1_Help_Contents.SetTag(0);
  menu1_Help_Contents.SetText(wxT("Contents"));
  menu1_Help_Contents.SetSubMenu(NULL);
  menu1_Help_Contents.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Help_Contents_EvMenuActive;
  menu1_Help.CreateChild(&menu1_Help_Contents);
  //menu1_Help_Reference
  menu1_Help_Reference.SetFOwner(this);
  menu1_Help_Reference.SetClass(wxT("CItemMenu"));
  menu1_Help_Reference.SetName(wxT("menu1_Help_Reference"));
  menu1_Help_Reference.SetTag(0);
  menu1_Help_Reference.SetText(wxT("Reference"));
  menu1_Help_Reference.SetSubMenu(NULL);
  menu1_Help_Reference.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Help_Reference_EvMenuActive;
  menu1_Help.CreateChild(&menu1_Help_Reference);
  //menu1_Help_About
  menu1_Help_About.SetFOwner(this);
  menu1_Help_About.SetClass(wxT("CItemMenu"));
  menu1_Help_About.SetName(wxT("menu1_Help_About"));
  menu1_Help_About.SetTag(0);
  menu1_Help_About.SetText(wxT("About"));
  menu1_Help_About.SetSubMenu(NULL);
  menu1_Help_About.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Help_About_EvMenuActive;
  menu1_Help.CreateChild(&menu1_Help_About);
  //menu1_Edit_IncludeLibs
  menu1_Edit_IncludeLibs.SetFOwner(this);
  menu1_Edit_IncludeLibs.SetClass(wxT("CItemMenu"));
  menu1_Edit_IncludeLibs.SetName(wxT("menu1_Edit_IncludeLibs"));
  menu1_Edit_IncludeLibs.SetTag(0);
  menu1_Edit_IncludeLibs.SetText(wxT("Include Libs"));
  menu1_Edit_IncludeLibs.SetSubMenu(NULL);
  menu1_Edit_IncludeLibs.EvMenuActive=EVMENUACTIVE & CPWindow1::menu1_Edit_IncludeLibs_EvMenuActive;
  menu1_Edit.CreateChild(&menu1_Edit_IncludeLibs);
  /*#Others*/
//lxrad automatic generated block end, don't edit above!  
};
