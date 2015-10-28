#include<stdlib.h>
#include<time.h>
#include<stdio.h>


#include"../include/lxrad.h"
#include"window2.h"


CJanela2 Janela2;


//implemetation
#include"window2_d.cc"

int x2, y2;

int x3, y3;

void
CJanela2::DrawMouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{

  draw1.Canvas.Init();
  draw1.Canvas.SetLineWidth (2);
  draw1.Canvas.SetFgColor (200, 0, 0);
  draw1.Canvas.Point (x, y);
  draw1.Canvas.SetFgColor (0, 0, 200);
  draw1.Canvas.Line (x2, y2, x - 10, y - 10);
  draw1.Canvas.End();

  x2 = x - 10;
  y2 = y - 10;

  draw1.Update ();

};

void
CJanela2::MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{
  if(canvas.GetDrawable() == NULL)
  {
    canvas.Create(this,1);
  }
  
  canvas.Init();
  canvas.SetLineWidth (2);
  canvas.SetFgColor (0,200, 0);
  canvas.Point (x, y);
  canvas.SetFgColor (200,0,0);
  canvas.Line (x3, y3, x - 10, y - 10);
  canvas.End();

  x3 = x - 10;
  y3 = y - 10;

  Update ();
}

