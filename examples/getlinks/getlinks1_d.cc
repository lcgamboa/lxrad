CPWindow1::CPWindow1(void)
{
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window1"));
  SetTag(0);
  SetX(351);
  SetY(196);
  SetWidth(401);
  SetHeight(522);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(1);
  SetColor(wxT("#000001"));
  SetPopupMenu(NULL);
  SetTitle(wxT("getlinks"));
  SetOverrideRedirect(0);
  //filedialog1
  filedialog1.SetFOwner(this);
  filedialog1.SetClass(wxT("CFileDialog"));
  filedialog1.SetName(wxT("filedialog1"));
  filedialog1.SetTag(0);
  filedialog1.SetFileName(wxT("untitled.txt"));
  filedialog1.SetFilter(wxT("All Files (*.*)|*.*"));
  filedialog1.SetType(129);
  filedialog1.EvOnClose=EVONCLOSE & CPWindow1::filedialog1_EvOnClose;
  CreateChild(&filedialog1);
  //list1
  list1.SetFOwner(this);
  list1.SetClass(wxT("CList"));
  list1.SetName(wxT("list1"));
  list1.SetTag(0);
  list1.SetX(12);
  list1.SetY(93);
  list1.SetWidth(378);
  list1.SetHeight(300);
  list1.SetHint(wxT(""));
  list1.SetEnable(1);
  list1.SetVisible(1);
  list1.SetColor(wxT("#000001"));
  list1.SetPopupMenu(NULL);
  list1.SetItems(wxT(""));
  CreateChild(&list1);
  //button1
  button1.SetFOwner(this);
  button1.SetClass(wxT("CButton"));
  button1.SetName(wxT("button1"));
  button1.SetTag(0);
  button1.SetX(20);
  button1.SetY(10);
  button1.SetWidth(160);
  button1.SetHeight(28);
  button1.SetHint(wxT(""));
  button1.SetEnable(1);
  button1.SetVisible(1);
  button1.SetColor(wxT("#000001"));
  button1.SetPopupMenu(NULL);
  button1.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button1_EvMouseButtonClick;
  button1.SetText(wxT("Choose One File"));
  CreateChild(&button1);
  //button2
  button2.SetFOwner(this);
  button2.SetClass(wxT("CButton"));
  button2.SetName(wxT("button2"));
  button2.SetTag(0);
  button2.SetX(213);
  button2.SetY(9);
  button2.SetWidth(160);
  button2.SetHeight(28);
  button2.SetHint(wxT(""));
  button2.SetEnable(1);
  button2.SetVisible(1);
  button2.SetColor(wxT("#000001"));
  button2.SetPopupMenu(NULL);
  button2.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button2_EvMouseButtonClick;
  button2.SetText(wxT("Save List To File"));
  CreateChild(&button2);
  //edit1
  edit1.SetFOwner(this);
  edit1.SetClass(wxT("CEdit"));
  edit1.SetName(wxT("edit1"));
  edit1.SetTag(0);
  edit1.SetX(132);
  edit1.SetY(43);
  edit1.SetWidth(241);
  edit1.SetHeight(26);
  edit1.SetHint(wxT(""));
  edit1.SetEnable(1);
  edit1.SetVisible(1);
  edit1.SetColor(wxT("#000001"));
  edit1.SetPopupMenu(NULL);
  edit1.SetText(wxT(""));
  edit1.SetReadOnly(0);
  CreateChild(&edit1);
  //string2
  string2.SetFOwner(this);
  string2.SetClass(wxT("CLabel"));
  string2.SetName(wxT("string2"));
  string2.SetTag(0);
  string2.SetX(26);
  string2.SetY(45);
  string2.SetWidth(100);
  string2.SetHeight(20);
  string2.SetHint(wxT(""));
  string2.SetEnable(1);
  string2.SetVisible(1);
  string2.SetColor(wxT("#000001"));
  string2.SetPopupMenu(NULL);
  string2.SetText(wxT("Base Address"));
  string2.SetAlign(1);
  CreateChild(&string2);
  //button3
  button3.SetFOwner(this);
  button3.SetClass(wxT("CButton"));
  button3.SetName(wxT("button3"));
  button3.SetTag(0);
  button3.SetX(17);
  button3.SetY(406);
  button3.SetWidth(160);
  button3.SetHeight(28);
  button3.SetHint(wxT(""));
  button3.SetEnable(1);
  button3.SetVisible(1);
  button3.SetColor(wxT("#000001"));
  button3.SetPopupMenu(NULL);
  button3.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button3_EvMouseButtonClick;
  button3.SetText(wxT("Download All"));
  CreateChild(&button3);
  //button4
  button4.SetFOwner(this);
  button4.SetClass(wxT("CButton"));
  button4.SetName(wxT("button4"));
  button4.SetTag(0);
  button4.SetX(229);
  button4.SetY(407);
  button4.SetWidth(160);
  button4.SetHeight(28);
  button4.SetHint(wxT(""));
  button4.SetEnable(1);
  button4.SetVisible(1);
  button4.SetColor(wxT("#000001"));
  button4.SetPopupMenu(NULL);
  button4.EvMouseButtonClick=EVMOUSEBUTTONCLICK & CPWindow1::button4_EvMouseButtonClick;
  button4.SetText(wxT("Remove Selected"));
  CreateChild(&button4);
  /*#Others*/
  Op=0;
}
