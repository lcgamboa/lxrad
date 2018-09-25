CPWindow3::CPWindow3(void)
{
//lxrad automatic generated block start, don't edit below!  
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window3"));
  SetTag(0);
  SetX(13);
  SetY(260);
  SetWidth(194);
  SetHeight(382);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(1);
  SetPopupMenu(NULL);
  SetTitle(wxT("Propierties"));
  SetOverrideRedirect(0);
  //filedialog1
  filedialog1.SetFOwner(this);
  filedialog1.SetClass(wxT("CFileDialog"));
  filedialog1.SetName(wxT("filedialog1"));
  filedialog1.SetTag(0);
  filedialog1.SetFileName(wxT("untitled.txt"));
  filedialog1.SetFilter(wxT("All Files (*.*)|*.*"));
  filedialog1.SetType(129);
  filedialog1.EvOnClose = EVONCLOSE &CPWindow3::Filedialog1OnClose;
  CreateChild(&filedialog1);
  /*#Others*/
  ctrl=NULL;
//lxrad automatic generated block end, don't edit above!
};
