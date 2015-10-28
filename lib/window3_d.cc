CJanela3::CJanela3 (void)
{
  SetName (wxT("window3"));
  SetX (100);
  SetY (100);
  SetWidth (420);
  SetHeight (420);
  SetTitle (wxT("Splash"));
  SetCanDestroy (true);
  SetTimeout(6000);
  SetImgFileName(wxT("teste.png"));
};

