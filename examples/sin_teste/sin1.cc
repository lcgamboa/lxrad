
#include<math.h>

#include"sin1.h"
#include"sin1_d.cc"

CPWindow1 Window1;


//Implementation
void
CPWindow1::_EvOnCreate(CControl * control)
{
}

#define width  600
#define height 600

void
CPWindow1::draw1_EvMouseButtonPress(CControl * control, uint button, uint x, uint y,uint state)
{
  static unsigned int limpa=0;	
  int x1,y1,y2,y2a,c;
  float ic;
  c=0;
  ic=(0.314)*rand()/RAND_MAX;
  x1=0;
  y1=0;				
  y2=0;
  y2a=-200;
  

  if(limpa)
  {
  limpa=0;
  draw1.Canvas.Init();
  draw1.Canvas.SetBgColor(0,0,0);
  draw1.Canvas.SetFgColor(0,0,0);
  //draw1.Canvas.Rectangle(true,0,0,width, height); 
  for(int x=0; x < width; x++)
  {
  for(int y=0; y < height; y++)
  {
    draw1.Canvas.Point(x,y);
    //draw1.Canvas.Rectangle(true,x,y,2, 2); 
    //draw1.Canvas.Circle(true, x, y ,1);
  }
  }
  draw1.Canvas.End();
  }
  else
  {
  limpa=1;
  
  draw1.Canvas.Init();
  for(int x=0;x<5000;x++)  
  {
    if(x1 >400)
    {
      x1=0;
      y2a+=10;
      draw1.Canvas.End();
      draw1.Canvas.Init();
      c++;
    };
    y1=(int)(100*sin(0.04*x1-c*ic)+105);		
    draw1.Canvas.SetFgColor(25000-5*y2a,200*y2a,y2a*100);
    draw1.Canvas.SetLineWidth(2);
    draw1.Canvas.Line(x1-5,y2,x1,y1+y2a);
    x1+=5;
    y2=y1+y2a;
  };
  
  draw1.Canvas.End();
  }

}


void
CPWindow1::timer1_EvOnTime(CControl * control)
{
  
  draw1_EvMouseButtonPress(control, 0, 0, 0, 0);
}


