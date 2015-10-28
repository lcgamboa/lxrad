CSWindow0::CSWindow0 (void)
{
  SetName (wxT("window0"));
  SetX (284);
  SetY (212);
  SetWidth (302);
  SetHeight (202);
  SetTitle (wxT("Splash"));
  SetCanDestroy(true);          
  SetTimeout(6000);
  SetImgFileName (String (wxT(_SHARE)) +wxT("/icons/splash.png"));
};
