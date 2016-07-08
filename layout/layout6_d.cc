CPWindow6::CPWindow6(void)
{
//lxrad automatic generated block start, don't edit below!  
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window6"));
  SetTag(0);
  SetX(22);
  SetY(128);
  SetWidth(198);
  SetHeight(85);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(1);
  SetPopupMenu(NULL);
  SetTitle(wxT("LXRAD Layout -"));
  SetOverrideRedirect(0);
  //combo1
  combo1.SetFOwner(this);
  combo1.SetClass(wxT("CCombo"));
  combo1.SetName(wxT("combo1"));
  combo1.SetTag(0);
  combo1.SetX(4);
  combo1.SetY(6);
  combo1.SetWidth(180);
  combo1.SetHeight(26);
  combo1.SetHint(wxT(""));
  combo1.SetEnable(1);
  combo1.SetVisible(1);
  combo1.SetPopupMenu(NULL);
  combo1.SetText(wxT(""));
  combo1.SetItems(wxT(""));
  combo1.EvOnComboChange=EVONCOMBOCHANGE & CPWindow6::combo1_EvOnComboChange;
  CreateChild(&combo1);
  /*#Others*/
//lxrad automatic generated block end, don't edit above!
};
