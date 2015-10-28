CJanela2::CJanela2 (void)
{
  SetName (wxT("window2"));
  SetX (100);
  SetY (100);
  SetWidth (840);
  SetHeight (420);
  SetTitle (wxT("draw test"));
  SetVisible (false);
  EvMouseButtonPress = EVMOUSEBUTTONPRESS & CJanela2::MouseButtonPress;


//draw1 
  draw1.SetName (wxT("draw1"));
  draw1.SetX (10);
  draw1.SetY (10);
  draw1.SetHeight (400);
  draw1.SetWidth (400);
  draw1.SetTransparent (true);
  draw1.SetFOwner (this);
  draw1.EvMouseButtonPress = EVMOUSEBUTTONPRESS & CJanela2::DrawMouseButtonPress;
  
  
  CreateChild (&draw1);

};
