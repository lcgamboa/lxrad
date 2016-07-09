CPWindow2::CPWindow2(void)
{
//lxrad automatic generated block start, don't edit below!  
  SetFOwner(this);
  SetClass(wxT("CPWindow"));
  SetName(wxT("window2"));
  SetTag(0);
  SetX(307);
  SetY(140);
  SetWidth(400);
  SetHeight(400);
  SetHint(wxT(""));
  SetEnable(1);
  SetVisible(1);
  SetPopupMenu(NULL);
  EvMouseMove=EVMOUSEMOVE & CPWindow2::_EvMouseMove;
  EvMouseButtonPress=EVMOUSEBUTTONPRESS & CPWindow2::_EvMouseButtonPress;
  EvMouseButtonRelease=EVMOUSEBUTTONRELEASE & CPWindow2::_EvMouseButtonRelease;
  EvKeyboardPress=EVKEYBOARDPRESS & CPWindow2::_EvKeyboardPress;
  EvOnDraw=EVONDRAW & CPWindow2::_EvOnDraw;
  SetTitle(wxT("layout"));
  SetOverrideRedirect(0);
  EvOnShow=EVONSHOW & CPWindow2::_EvOnShow;
  /*#Others*/
//lxrad automatic generated block end, don't edit above!  
};
