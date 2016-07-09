/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2010 Luis Claudio Gamboa Lopes

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

   For e-mail suggestions :  lcgamboa@yahoo.com
   ######################################################################## */



#include"layout2.h"
#include"layout2_d.cc"


#include"math.h"

CPWindow2 Window2;

#include<sys/stat.h>
#include<errno.h>
#include"controlsdef.h"
#include"layout1.h"
#include"layout3.h"
#include"layout4.h"
#include"layout6.h"
#include"layout7.h"
#include"layout8.h"
#include"layout9.h"


// XPM 
static const char *b_xpm[] = {
  "15 15 2 1",
  " 	c None",
  ".	c #000000",
  "               ",
  "               ",
  "               ",
  "               ",
  "               ",
  "               ",
  " ...  ...  ... ",
  " ...  ...  ... ",
  " ...  ...  ... ",
  "               ",
  "               ",
  "               ",
  "               ",
  "               ",
  "               "
};

typedef struct
{
  CControl* ctrl;
  wxBitmap * Bitmap;
} _bitens;


#define ITEMMAX 500

_bitens itens[ITEMMAX];
int bc = 0;
int item = -1;
int selected = 1;
int xi, yi;

int op = 0;

//Implementation

#define OP_NONE		0
#define OP_MOVE		1
#define OP_RESL		2
#define OP_RESR		3
#define OP_REST		4
#define OP_RESB		5
#define OP_RESTL	6
#define OP_RESTR	7
#define OP_RESBL	8
#define OP_RESBR	9


int xo = -1, yo = -1, xp, yp;

//extern Bool predicate(Display* display,XEvent *event,XPointer arg);

CPWindow2::~CPWindow2 (void)
{
  Window2.DestroyChilds ();
};

String
spacestrip (String sstr)
{
  String out;
  int j;

  while ((j = sstr.find (wxT (" "))) >= 0)
    {
      out += sstr.substr (0, j);
      sstr = sstr.substr (j + 1, sstr.size ());
    }

  out += sstr;

  return out;
};

void
CPWindow2::_EvKeyboardPress (CControl * control, uint key, uint x, uint y, uint mask)
{
  CCanvas Canvas;
  wxMemoryDC NDC;
  wxScreenDC SDC;
  wxPoint org;
  int i;

  Draw ();

  for (i = 0; i < bc; i++)
    {
      //itens[i].ctrl->SetVisible(true);
      itens[i].ctrl->SetVisible (0); //FIXME
      Application->ProcessEvents (GetWidget ());

      Canvas.Create (this, 1);
      Canvas.Init ();
      org = ((wxFrame*) GetWidget ())->GetClientAreaOrigin ();
      GetWidget ()->ClientToScreen (&org.x, &org.y);
      NDC.SelectObject (*itens[i].Bitmap);
      drawcontrol (&NDC, itens[i].ctrl);
      //NDC.Blit(0, 0, itens[i].ctrl->GetWidth(),itens[i].ctrl->GetHeight(),&SDC,org.x+itens[i].ctrl->GetX(), org.y+itens[i].ctrl->GetY());
      //itens[i].ctrl->SetVisible(0);
      Application->ProcessEvents (GetWidget ());
      Canvas.GetDC ()->Blit (itens[i].ctrl->GetX (), itens[i].ctrl->GetY () + 0, itens[i].ctrl->GetWidth (), itens[i].ctrl->GetHeight (), &NDC, 0, 0);
      Canvas.End ();

      NDC.SelectObject (wxNullBitmap);


      /*  
      #ifdef __UNICODE__
        printf("%ls  %04ix%04i\n",itens[i].ctrl->GetName().char_str(),itens[i].ctrl->GetX(),itens[i].ctrl->GetY());
      #else
        printf("%s  %04ix%04i\n",itens[i].ctrl->GetName().char_str(),itens[i].ctrl->GetX(),itens[i].ctrl->GetY());
      #endif
       */
    };

  //code here:)
  //  mprint(wxT("_EvKeyboardPress\n"));


  this->SetColor (wxT ("darkgray"));
};

void
CPWindow2::_EvMouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{
  CCanvas Canvas;
  wxMemoryDC NDC;
  wxScreenDC SDC;
  wxPoint org;

  if (operation.compare (wxT ("editar")) != 0)
    {

      itens[bc].ctrl = newcontrol (operation, &Window2);
      itens[bc].ctrl->SetX (x);
      itens[bc].ctrl->SetY (y);
      
           
    //if control is not drawable, resize 
    if((itens[bc].ctrl->GetWidth ()==10)&&
      (itens[bc].ctrl->GetHeight () == 10))
    {
       itens[bc].ctrl->SetWidth (40);
       itens[bc].ctrl->SetHeight (15);
    }        

      
      /*
      if (ncontrol->GetClass ().compare (wxT("CFileDialog")) != 0)
      {
        itens[bc].ctrl->SetCanExecuteEvent (true);
        itens[bc].ctrl->SetCanFocus (true);
      }
      else
      {
        itens[bc].ctrl->SetCanExecuteEvent (false);
        itens[bc].ctrl->SetCanFocus (false);
        itens[bc].ctrl->SetVisible (false, false);
      };

      if (ncontrol->GetClass ().compare (wxT("CItemMenu")) == 0)
      {
        itens[bc].ctrl->SetVisible (false, false);
      }
       */

      CreateChild (itens[bc].ctrl);
      //itens[bc].ctrl->SetVisible(0); 

      Application->ProcessEvents (GetWidget ());

      itens[bc].Bitmap = new wxBitmap (itens[bc].ctrl->GetWidth (), itens[bc].ctrl->GetHeight (), -1);

      itens[bc].ctrl->SetAux (itens[bc].ctrl->GetVisible ());
      itens[bc].ctrl->SetVisible (0);


      Canvas.Create (this, 1);
      Canvas.Init ();
      org = ((wxFrame*) GetWidget ())->GetClientAreaOrigin ();
      GetWidget ()->ClientToScreen (&org.x, &org.y);
      NDC.SelectObject (*itens[bc].Bitmap);
      drawcontrol (&NDC, itens[bc].ctrl);
      //NDC.Blit(0, 0, itens[bc].ctrl->GetWidth(),itens[bc].ctrl->GetHeight(),&SDC,org.x+itens[bc].ctrl->GetX(), org.y+itens[bc].ctrl->GetY());
      //  itens[bc].ctrl->SetVisible(itens[bc].visible,false);
      Application->ProcessEvents (GetWidget ());

      Canvas.GetDC ()->Blit (itens[bc].ctrl->GetX (), itens[bc].ctrl->GetY () + 0, itens[bc].ctrl->GetWidth (), itens[bc].ctrl->GetHeight (), &NDC, 0, 0);
      Canvas.End ();
      itens[bc].ctrl->SetVisible (1);
      bc++;
      NDC.SelectObject (wxNullBitmap);


      operation = wxT ("editar");
    }

  item = -1;

  //Update();
  _EvOnDraw (this);

  /*  
    for(i=0;i<bc;i++)
    {
      if ((itens[i].ctrl->GetX() < (int)x) &&( x < itens[i].ctrl->GetX()+itens[i].ctrl->GetWidth())&&
          (itens[i].ctrl->GetY() < (int)y) &&( y < itens[i].ctrl->GetY()+itens[i].ctrl->GetHeight()))   
      {
        item=i;
        selected=1;
        break;
      }
    }

  if(item==-1)selected=0;
   */

  //Draw();
  _EvKeyboardPress (this, 0, 0, 0, 0);

  if (Mcontrol == &Window2)
    SetControlOnFocus (NULL);
  else
    SetControlOnFocus (Mcontrol);

  ListPropierties (Mcontrol);


  //code here:)
  //  mprint(wxT("_EvMouseButtonRelease\n"));
};

void
CPWindow2::_EvOnDraw (CControl * control)
{
  int i;
  CCanvas Canvas;
  wxMemoryDC NDC;
  Canvas.Create (this, 1);
  Canvas.Init ();

  for (i = 0; i < bc; i++)
    {
      NDC.SelectObject (*itens[i].Bitmap);
      Canvas.GetDC ()->Blit (itens[i].ctrl->GetX (), itens[i].ctrl->GetY (), itens[i].Bitmap->GetWidth (), itens[i].Bitmap->GetHeight (), &NDC, 0, 0);
    }
  Canvas.End ();
  //code here:)
    //mprint(wxT("_EvOnDraw CPWindow2\n"));
};

//#define MINW 30
//#define MINH 30

int MINW, MINH;

void
CPWindow2::_EvMouseMove (CControl * control, uint button, uint x, uint y, uint state)
{
  CCanvas Canvas;

  wxMemoryDC NDC;
  wxScreenDC SDC;
  wxPoint org;
  wxSize csize;

  int i, nb;

  int width, height;

  if (item != -1)
    {
      nb = 0;
      /* 
       Canvas.Create (this,0);
       Canvas.Init(); 
       //NDC.SelectObject(*itens[item].Bitmap);
       //Canvas.GetDC()->Blit(itens[item].ctrl->GetX(),itens[item].ctrl->GetY(),itens[item].Bitmap->GetWidth(),itens[item].Bitmap->GetHeight(),&NDC,0,0); 
    
       Canvas.Rectangle(1,itens[item].ctrl->GetX()-2,itens[item].ctrl->GetY()-2,itens[item].ctrl->GetWidth()+4,itens[item].ctrl->GetHeight()+4);
       //Canvas.Rectangle(1,0,0,GetWidth(),GetHeight());
       Canvas.End();
       */

      //itens[item].ctrl->SetVisible(true);

      if (itens[item].ctrl->GetCanVisible ())
        {
          csize = itens[item].ctrl->GetWidget ()->GetMinSize ();
          MINH = csize.GetHeight ();
          MINW = csize.GetWidth ();
        }
      else
        {
          MINH = 26;
          MINW = 26;
        }

      switch (op)
        {
        case OP_MOVE:
          //itens[item].ctrl->SetVisible(false);
          itens[item].ctrl->SetX (x - xi);
          itens[item].ctrl->SetY (y - yi);
          nb = 0;
          break;
        case OP_RESL:
          width = itens[item].ctrl->GetWidth () + itens[item].ctrl->GetX () - x;
          if (width <= MINW)
            {
              itens[item].ctrl->SetX (itens[item].ctrl->GetX ()+(itens[item].ctrl->GetWidth () - MINW));
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            {
              itens[item].ctrl->SetWidth (width);
              itens[item].ctrl->SetX (x);
            }
          nb = 1;
          break;
        case OP_RESR:
          width = x - itens[item].ctrl->GetX ();
          if (width <= MINW)
            {
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            itens[item].ctrl->SetWidth (width);
          nb = 1;
          break;
        case OP_REST:
          height = itens[item].ctrl->GetHeight () + itens[item].ctrl->GetY () - y;
          if (height <= MINH)
            {
              itens[item].ctrl->SetY (itens[item].ctrl->GetY ()+(itens[item].ctrl->GetHeight () - MINH));
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            {
              itens[item].ctrl->SetHeight (height);
              itens[item].ctrl->SetY (y);
            }
          nb = 1;
          break;
        case OP_RESB:
          height = y - itens[item].ctrl->GetY ();
          if (height <= MINH)
            {
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            itens[item].ctrl->SetHeight (height);
          nb = 1;
          break;
        case OP_RESTL:
          height = itens[item].ctrl->GetHeight () + itens[item].ctrl->GetY () - y;
          if (height <= MINH)
            {
              itens[item].ctrl->SetY (itens[item].ctrl->GetY ()+(itens[item].ctrl->GetHeight () - MINH));
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            {
              itens[item].ctrl->SetHeight (height);
              itens[item].ctrl->SetY (y);
            }
          width = itens[item].ctrl->GetWidth () + itens[item].ctrl->GetX () - x;
          if (width <= MINW)
            {
              itens[item].ctrl->SetX (itens[item].ctrl->GetX ()+(itens[item].ctrl->GetWidth () - MINW));
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            {
              itens[item].ctrl->SetWidth (width);
              itens[item].ctrl->SetX (x);
            }
          nb = 1;
          break;
        case OP_RESTR:
          height = itens[item].ctrl->GetHeight () + itens[item].ctrl->GetY () - y;
          if (height <= MINH)
            {
              itens[item].ctrl->SetY (itens[item].ctrl->GetY ()+(itens[item].ctrl->GetHeight () - MINH));
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            {
              itens[item].ctrl->SetHeight (height);
              itens[item].ctrl->SetY (y);
            }
          width = x - itens[item].ctrl->GetX ();
          if (width <= MINW)
            {
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            itens[item].ctrl->SetWidth (width);
          nb = 1;
          break;
        case OP_RESBL:
          width = itens[item].ctrl->GetWidth () + itens[item].ctrl->GetX () - x;
          if (width <= MINW)
            {
              itens[item].ctrl->SetX (itens[item].ctrl->GetX ()+(itens[item].ctrl->GetWidth () - MINW));
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            {
              itens[item].ctrl->SetWidth (width);
              itens[item].ctrl->SetX (x);
            }
          height = y - itens[item].ctrl->GetY ();
          if (height <= MINH)
            {
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            itens[item].ctrl->SetHeight (height);
          nb = 1;
          break;
        case OP_RESBR:
          width = x - itens[item].ctrl->GetX ();
          if (width <= MINW)
            {
              itens[item].ctrl->SetWidth (MINW);
            }
          else
            itens[item].ctrl->SetWidth (width);
          height = y - itens[item].ctrl->GetY ();
          if (height <= MINH)
            {
              itens[item].ctrl->SetHeight (MINH);
            }
          else
            itens[item].ctrl->SetHeight (height);
          nb = 1;
          break;
        default:
          nb = 0;
          break;
        };

      if ((nb)&&(item != -1))
        {
          int xitem = item;

          //itens[xitem].ctrl->SetVisible(1); //FIXME

          Application->ProcessEvents (GetWidget ());
          delete itens[xitem].Bitmap;
          itens[xitem].Bitmap = new wxBitmap (itens[xitem].ctrl->GetWidth (), itens[xitem].ctrl->GetHeight (), -1);
          Canvas.Create (this, 1);
          Canvas.Init ();



          org = ((wxFrame*) GetWidget ())->GetClientAreaOrigin ();
          GetWidget ()->ClientToScreen (&org.x, &org.y);
          NDC.SelectObject (*itens[xitem].Bitmap);
          drawcontrol (&NDC, itens[xitem].ctrl);
          //	NDC.Blit(0, 0, itens[xitem].ctrl->GetWidth(),itens[xitem].ctrl->GetHeight(),&SDC,org.x+itens[xitem].ctrl->GetX(), org.y+itens[xitem].ctrl->GetY());
          //	itens[xitem].ctrl->SetVisible(false);
          Application->ProcessEvents (GetWidget ());
          Canvas.GetDC ()->Blit (itens[xitem].ctrl->GetX (), itens[xitem].ctrl->GetY () + 0, itens[xitem].ctrl->GetWidth (), itens[xitem].ctrl->GetHeight (), &NDC, 0, 0);
          Canvas.End ();

          NDC.SelectObject (*itens[xitem].Bitmap);
          Canvas.End ();


          NDC.SelectObject (wxNullBitmap);
          /*
          #ifdef __UNICODE__
                  printf("%ls  %04ix%04i\n",itens[xitem].ctrl->GetName().char_str(),itens[xitem].ctrl->GetX(),itens[xitem].ctrl->GetY());
          #else  	
                  printf("%s  %04ix%04i\n",itens[xitem].ctrl->GetName().char_str(),itens[xitem].ctrl->GetX(),itens[xitem].ctrl->GetY());
          #endif
           */
        }
      Draw ();
      _EvOnDraw (this);

      //    printf("item=%i  %04ix%04i\n",item,x,y);
    }
  else
    {
      if (selected == 1)
        {
          for (i = 0; i < bc; i++)
            {

              if ((itens[i].ctrl->GetX () < (int) x) &&(x < itens[i].ctrl->GetX () + itens[i].ctrl->GetWidth ())&&
                  (itens[i].ctrl->GetY () < (int) y) &&(y < itens[i].ctrl->GetY () + itens[i].ctrl->GetHeight ()))
                {
                  /*
                  #ifdef __UNICODE__
                          printf("Over control %ls\n",itens[i].ctrl->GetName().char_str());
                  #else
                          printf("Over control %s\n",itens[i].ctrl->GetName().char_str());
                  #endif
                   */
                  if ((x - itens[i].ctrl->GetX ()) <= 3)
                    {

                      //	  printf("Left Board\n");
                      if ((y - itens[i].ctrl->GetY ()) <= 3)
                        {
                          wxSetCursor (wxCursor (wxCURSOR_SIZING));
                          op = OP_RESTL;
                          //	   printf("Top Board\n");
                          break;
                        };
                      if ((itens[i].ctrl->GetY () + itens[i].ctrl->GetHeight () - y) <= 3)
                        {
                          wxSetCursor (wxCursor (wxCURSOR_SIZING));
                          op = OP_RESBL;
                          //	   printf("Botton Board\n");
                          break;
                        };

                      op = OP_RESL;
                      wxSetCursor (wxCursor (wxCURSOR_SIZEWE));
                      break;
                    }

                  if ((itens[i].ctrl->GetX () + itens[i].ctrl->GetWidth () - x) <= 3)
                    {
                      //	  printf("Right Board\n");

                      if ((y - itens[i].ctrl->GetY ()) <= 3)
                        {
                          wxSetCursor (wxCursor (wxCURSOR_SIZING));
                          //	   printf("Top Board\n");
                          op = OP_RESTR;
                          break;
                        };
                      if ((itens[i].ctrl->GetY () + itens[i].ctrl->GetHeight () - y) <= 3)
                        {
                          wxSetCursor (wxCursor (wxCURSOR_SIZING));
                          //	   printf("Botton Board\n");
                          op = OP_RESBR;
                          break;
                        };
                      op = OP_RESR;
                      wxSetCursor (wxCursor (wxCURSOR_SIZEWE));
                      break;
                    }

                  if ((y - itens[i].ctrl->GetY ()) <= 3)
                    {
                      wxSetCursor (wxCursor (wxCURSOR_SIZENS));
                      //	 printf("Top Board\n");
                      op = OP_REST;
                      break;
                    };

                  if ((itens[i].ctrl->GetY () + itens[i].ctrl->GetHeight () - y) <= 3)
                    {
                      wxSetCursor (wxCursor (wxCURSOR_SIZENS));
                      //	  printf("Botton Board\n");
                      op = OP_RESB;
                      break;
                    }

                  op = OP_MOVE;
                  wxSetCursor (wxCursor (wxCURSOR_SIZENWSE));
                  break;
                }
              else
                {
                  op = OP_NONE;
                  wxSetCursor (wxCursor (wxCURSOR_ARROW));
                }

            }
        }

    }

  //  printf("EvMouseMove Op=%i\n",op);
  //code here:)
  //  mprint(wxT("_EvMouseMove\n"));
};

void
CPWindow2::_EvMouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{

  int i;

  item = -1;

  //  printf("EvMouseButtonPress Op=%i\n",op);

  Mcontrol = &Window2;

  if ((button == wxMOUSE_BTN_LEFT)&&(op != OP_NONE))
    {
      for (i = 0; i < bc; i++)
        {
          if ((itens[i].ctrl->GetX () < (int) x) &&(x < itens[i].ctrl->GetX () + itens[i].ctrl->GetWidth ())&&
              (itens[i].ctrl->GetY () < (int) y) &&(y < itens[i].ctrl->GetY () + itens[i].ctrl->GetHeight ()))
            {
              item = i;
              xi = x - itens[i].ctrl->GetX ();
              yi = y - itens[i].ctrl->GetY ();

              Mcontrol = itens[i].ctrl;
              /*
              #ifdef __UNICODE__  
                printf("*****************Move=%i  mcontrol=%ls ",Move,Mcontrol->GetName().char_str());	
              #else
                printf("*****************Move=%i  mcontrol=%s ",Move,Mcontrol->GetName().char_str());	
              #endif
               */
              break;
            }
        }

    }

  //code here:)
  //  mprint(wxT("_EvMouseButtonPress\n"));
};

//--------------------------------------------------------------------------------------------------------------

/*
void
CPWindow2::Draw (void)
{

  if (!Visible)
    {
      SetCanExecuteEvent (true);
      Visible = 1;
      CWindow::Draw ();
      Visible = 0;
    }
  else
    CWindow::Draw ();
};
 */


int
CPWindow2::Create (CControl * control)
{
  int ret = CPWindow::Create (control);
  //  Canvas.Create (this,1);
  Mcontrol = this;
  return ret;
};

CControl *
CPWindow2::GetControlOnFocus (void)
{
  //  return CPWindow::GetControlOnFocus ();
  if (Mcontrol == this)
    return NULL;
  else
    return Mcontrol;
}

/*
bool CPWindow2::WEvent (wxWindow * widget, wxEvent * event)
{

  switch (CEvent(event->GetEventType()))
    {
    case lxEVT_DESTROY:
      on_destroy ();
      return 1;
      break;
    case lxEVT_MAXIMIZE:
    case lxEVT_SIZE:
      on_show ();
      return 1;
      break;
    case lxEVT_CLOSE_WINDOW:
      on_hide ();
      return 1;
      break;
    case lxEVT_PAINT:
    case lxEVT_KILL_FOCUS:
    case lxEVT_SET_FOCUS:
     CControl::Event (widget, event);
     return 1;
     break;
     
    default:
      //CControl::Event (WEvent);
      {

        if (Widget != NULL)
          {
            CControl *  control = this;

            if (ChildCount > -1)
              {
                for (int i = 0; i <= ChildCount; i++)
                  {
                    if ((Child[i]->GetWidget () == widget))
                      {
                        control = Child[i];
                        break;
                      };
                  }
              };


            CWindow *   iswin =  dynamic_cast < CWindow * >(control);
            CWindow *   owneriswin = dynamic_cast < CWindow * >(control->GetOwner ());

//activate event in control
            switch (CEvent(event->GetEventType()))
              {
              case lxEVT_MOTION:
                //printf("%s\n",control->GetName().char_str());
                if (iswin)
                  {
                    control->mouse_move ((wxMouseEvent*) event);
                  }
                else
                  {  
                    if (owneriswin)
                      {
                        wxMouseEvent*  Nevent = (wxMouseEvent *) event;
                        _MouseMove (control,0, Nevent->m_x, Nevent->m_y,0);
                      };
                  };
                return false;
                break;
              case lxEVT_KEY_DOWN:
//		   XXLookupString (NULL, &WEvent.xkey, text, 10, &key, &status);
//		   if (key == XK_Tab)
//		   {
//		   Win->CirculateFocus (true);
//		   return 1;
//		   };
//		   if (key == XK_Delete)
//		   {
//		   DestroyChild (Window2.GetControlOnFocus ());
//		   ListPropierties (&Window2);
//		   Save = true;
//		   return 1;
//		   };
                   //_KeyboardPress (control, WEvent.xkey.keycode, WEvent.xkey.x,
                   //WEvent.xkey.y, WEvent.xkey.state);
                return 1;
                break;
              case lxEVT_KEY_UP:

                return 1;
                break;
              case lxEVT_LEFT_DOWN:
                if (iswin)
                  {
                    control->button_press ((wxMouseEvent*) event);
                  }
                else
                  {
                    if (owneriswin)
                      {
                         wxMouseEvent*  Nevent = (wxMouseEvent*) event;
                        _MouseButtonPress (control, Nevent->GetButton(), Nevent->m_x, Nevent->m_y, 0);
                      };
                  };
                return false;
                break;
              case lxEVT_LEFT_UP:
                if (iswin)
                  {
                    control->button_release ((wxMouseEvent*) event);
                  }
                else
                  {
                    if (owneriswin)
                      {
                        wxMouseEvent*  Nevent = (wxMouseEvent*)  event;
                        _MouseButtonRelease (control, Nevent->GetButton(), Nevent->m_x, Nevent->m_y, 0);
                      };
                  };
                return false;
                break;
              default:
                return 1;
                break;
              };

          };

      };
      return 1;
    };

    
  return 1;
};
 */

void
CPWindow2::Reset (void)
{
  int i;

  for (i = 0; i < bc; i++)
    {
      delete itens[i].Bitmap;
    };

  bc = 0;
  item = -1;
  selected = 1;
  op = 0;

  resetcontrolscount ();
};

String
CPWindow2::getalign (CAlign align)
{
  String
  a;
  switch (align)
    {
    case CA_RIGHT:
      a = wxT ("CA_RIGHT");
      break;
    case CA_CENTER:
      a = wxT ("CA_CENTER");
      break;
    case CA_LEFT:
      a = wxT ("CA_LEFT");
      break;
    case CA_FILL:
      a = wxT ("CA_FILL");
      break;
    };
  return a;
};

bool
CPWindow2::testline (String line)
{
  int
  pos;

  String
  temp;

  for (uint a = 0; a < linesbak.GetLinesCount (); a++)
    {
      temp = linesbak.GetLine (a);
      pos = line.compare (linesbak.GetLine (a));
      if (pos == 0)
        return true;
    };

  return false;
};


//create or update project files

void
CPWindow2::MakeOrUpdateFiles (bool prompt)
{
  wxTextFile fbak;
  String lbak;
  wxTextFile file;
  String filename, filec = wxT (""), filec2 = wxT ("");
  CControl *controle;
  String ctname;
  CStringList List;
  String line, arg, ctype;


  if (prompt)
    {
      if (!Dialog (wxT ("Do you want to save changes?")))
        {
          return;
        };
    };


  String dirname = PDir;
  String basename = PName;

  //dirname += "/" + basename;
  //PName = basename;

  if ((WN > PNW) && (WN == PNW + 1))
    {
      PNW++;
    }
  else
    {
      if (WN > PNW)
        {
          Message (wxT ("Window Number Invalid!"));
          return;
        };
    };

  //write project options an window xml files   
  MakeProject (dirname + wxT ("/") + basename);

  //================================================================================================
  //makefile        
  //================================================================================================
  filename = dirname + wxT ("/Makefile");

  int mfexist = wxFileExists (filename);

  if (mfexist != true)
    {
      //new file 
      file.Create (filename);

      file.AddLine (wxT ("CC = g++\n"));
      file.AddLine (wxT ("#lxrad automatic generated block start, don't edit below!\n"));
      if (POptions.size () > 0)
        {
          file.AddLine (wxT ("FLAGS = ") + POptions + wxT (" `lxrad-config --cxxflags`\n"));
        }
      else
        {
          file.AddLine (wxT ("FLAGS = `lxrad-config --cxxflags`\n"));
        };

      if (PLibs.size () > 0)
        {
          file.AddLine (wxT ("LIBS = `lxrad-config --libs` " + PLibs + wxT ("\n")));
        }
      else
        {
          file.AddLine (wxT ("LIBS = `lxrad-config --libs` \n"));
        }

      line = wxT ("OBJS = p") + PName + wxT (".o");

      for (int c = 1; c <= PNW; c++)
        line += wxT (" ") + PName + itoa (c) + wxT (".o");

      if (PIncludeFile.size () > 0)
        line += wxT (" ") + PIncludeFile;

      file.AddLine (line);

      file.AddLine (wxT ("\n#lxrad automatic generated block end, don't edit above!"));

      file.AddLine (wxT ("\n\nall: $(OBJS)"));
      file.AddLine (wxT ("\t$(CC) $(FLAGS) $(OBJS) -o") + PName + wxT (" $(LIBS)\n"));
      file.AddLine (wxT ("%.o: %.cc\n\t$(CC) -c $(FLAGS) $< \n"));
      file.AddLine (wxT ("run: all\n\t./") + PName + wxT ("\n"));
      file.AddLine (wxT ("install:\n\nclean:\n\trm -f ") + PName + wxT (" *.o core"));
      file.Write ();
      file.Close ();
    }
  else //update makefile
    {
      wxRenameFile (filename, filename + wxT (".bak"));
      fbak.Open (filename + wxT (".bak"));
      fbak.GoToLine (-1);
      file.Create (filename);

      while (fgetline (fbak, lbak))
        {

          if (lbak.Contains (wxT ("FLAGS =")))
            {

              if (POptions.size () > 0)
                {
                  lbak = (wxT ("FLAGS = ") + POptions + wxT (" `lxrad-config --cxxflags`"));
                }
              else
                {
                  lbak = (wxT ("FLAGS = `lxrad-config --cxxflags`"));
                }
            }
          if (lbak.Contains (wxT ("LIBS =")))
            {


              if (PLibs.size () > 0)
                {
                  lbak = (wxT ("LIBS = `lxrad-config --libs` " + PLibs ));
                }
              else
                {
                  lbak = (wxT ("LIBS = `lxrad-config --libs` "));
                }


            }

          if (lbak.Contains (wxT ("OBJS =")))
            {
              line = wxT ("OBJS = p") + PName + wxT (".o");

              for (int c = 1; c <= PNW; c++)
                line += wxT (" ") + PName + itoa (c) + wxT (".o");

              if (PIncludeFile.size () > 0)
                line += wxT (" ") + PIncludeFile;
              
              lbak = line;
            }
          file.AddLine (lbak);

        }

      file.Write ();
      file.Close ();
      fbak.Close ();
      wxRemoveFile (filename + wxT (".bak"));

    }

  //================================================================================================
  //project        
  //================================================================================================

  filename = dirname + wxT ("/p") + basename + wxT (".cc");


  int pfexist = wxFileExists (filename);

  if (pfexist != true)
    {
      //new file              
      file.Create (filename);
      file.AddLine (wxT ("#include<lxrad/lxrad.h>"));
      for (int c = 1; c <= PNW; c++)
        file.AddLine (wxT ("#include\"") + PName + itoa (c) + wxT (".h\"\n"));
      file.AddLine (wxT ("//Program____________________________________________________________\n"));
      file.AddLine (wxT ("Initialize\n{\n  Application->Start ();"));
      for (int c = 1; c <= PNW; c++)
        file.AddLine (wxT ("  Application->ACreateWindow (&Window") + itoa (c) + wxT (");"));
      file.AddLine (wxT ("  Application->Load ();\n\n  return 0;\n};\n"));
      file.Write ();
      file.Close ();
    }
  else
    {
      wxRenameFile (filename, filename + wxT (".bak"));
      fbak.Open (filename + wxT (".bak"));
      fbak.GoToLine (-1);
      file.Create (filename);

      int c = 0, u = 0;
      while (fgetline (fbak, lbak))
        {

          int pos = lbak.compare (wxT ("#include\"") + PName + itoa (c + 1) + wxT (".h\""));
          if (pos == 0)
            {
              c++;
              if (c != PNW)
                file.AddLine (lbak);
            }
          else
            {
              if (c == 0)
                file.AddLine (lbak);
              else
                {
                  u = c;
                  for (int i = c + 1; i <= PNW; i++)
                    {
                      file.AddLine (wxT ("#include\"") + PName + itoa (i) + wxT (".h\""));
                      c = i;
                    };
                };
            };

          if (c == PNW)
            {
              file.AddLine (lbak);
              while (fgetline (fbak, lbak))
                {
                  int pos1 = lbak.compare (wxT ("  Application->ACreateWindow (&Window") + itoa (u) + wxT (");"));

                  if (u > 0)
                    {
                      if (pos1 == 0)
                        {
                          file.AddLine (lbak);
                          for (int i = u + 1; i <= PNW; i++)
                            file.AddLine (wxT ("  Application->ACreateWindow (&Window") + itoa (i) + wxT (");"));
                        }
                      else
                        file.AddLine (lbak);

                    }
                  else
                    file.AddLine (lbak);
                };
            }

        };
      file.Write ();
      file.Close ();
      fbak.Close ();
      wxRemoveFile (filename + wxT (".bak"));
    };

  //================================================================================================
  //window.h
  //================================================================================================
  filename = dirname + wxT ("/") + basename + itoa (WN) + wxT (".h");

  int hfexist = wxFileExists (filename);

  if (hfexist != true)
    {
      //new file              
      file.Create (filename);

      file.AddLine (wxT ("#ifndef CPWINDOW") + itoa (WN) + wxT (" \n#define CPWINDOW") + itoa (WN) + wxT ("\n\n#include<lxrad/lxrad.h>\n\nclass CPWindow") + itoa (WN) + wxT (":public CPWindow\n{\n  public:"));
      List = GetContext ();
      for (uint a = 0; a < List.GetLinesCount (); a++)
        {
          line = List.GetLine (a);
          //ctype = eqparse (line, arg);
          xml_in (line, line, ctype, arg);
          if (ctype.compare (wxT ("Event")) == 0)
            {
              if (atob (arg))
                {
                  filec += wxT ("  void ") + WriteEvents (wxT (""), line) + wxT (";\n");
                };
            };
        };
      file.AddLine (wxT ("//lxrad automatic generated block start, don't edit below!"));
      file.AddLine (wxT ("  /*#Controls*/"));
      for (int count = 0; count <= ChildCount; count++)
        {
          controle = Child[count];
          ctname = controle->GetName ();
          file.AddLine (wxT ("  ") + controle->GetClass () + wxT (" ") + ctname + wxT (";"));

          List = controle->GetContext ();
          for (uint a = 0; a < List.GetLinesCount (); a++)
            {
              line = List.GetLine (a);
              //ctype = eqparse (line, arg);
              xml_in (line, line, ctype, arg);
              if (ctype.compare (wxT ("Event")) == 0)
                {
                  if (atob (arg))
                    {
                      filec += wxT ("  void ") + WriteEvents (ctname, line) + wxT (";\n");
                    };
                };
            };
        };

      file.AddLine (wxT ("  /*#Events*/"));
      file.AddLine (filec);
      file.AddLine (wxT ("  /*#Others*/"));
      file.AddLine (wxT ("//lxrad automatic generated block end, don't edit above!"));
      file.AddLine (wxT ("  CPWindow") + itoa (WN) + wxT ("(void);\n};\n\nextern CPWindow") + itoa (WN) + wxT (" Window") + itoa (WN) + wxT (" ;"));
      file.AddLine (wxT ("\n#endif /*#CPWINDOW") + itoa (WN) + wxT ("*/\n"));
      file.Write ();
      file.Close ();
    }
  else
    {
      wxRenameFile (filename, filename + wxT (".bak"));
      fbak.Open (filename + wxT (".bak"));
      fbak.GoToLine (-1);
      file.Create (filename);

      while (fgetline (fbak, lbak))
        {
          int pos = lbak.compare (wxT ("  /*#Controls*/"));
          int pos1 = lbak.compare (wxT ("#endif /*#CPWINDOW") + itoa (WN) + wxT ("*/"));
          if (pos1 == 0)
            break;
          if (pos == 0)
            {
              int pos2 = 1;
              while (fgetline (fbak, lbak) && pos2)
                {
                  pos2 = lbak.compare (wxT ("  /*#Others*/"));
                };

              filec = wxT ("");
              List = GetContext ();
              for (uint a = 0; a < List.GetLinesCount (); a++)
                {
                  line = List.GetLine (a);
                  //ctype = eqparse (line, arg);
                  xml_in (line, line, ctype, arg);
                  if (ctype.compare (wxT ("Event")) == 0)
                    {
                      if (atob (arg))
                        {
                          filec += wxT ("  void ") + WriteEvents (wxT (""), line) + wxT (";\n");
                        };
                    };
                };
              file.AddLine (wxT ("  /*#Controls*/"));
              for (int count = 0; count <= ChildCount; count++)
                {
                  controle = Child[count];
                  ctname = controle->GetName ();
                  file.AddLine (wxT ("  ") + controle->GetClass () + wxT (" ") + ctname + wxT (";"));
                  List = controle->GetContext ();
                  for (uint a = 0; a < List.GetLinesCount (); a++)
                    {
                      line = List.GetLine (a);
                      //ctype = eqparse (line, arg);
                      xml_in (line, line, ctype, arg);
                      if (ctype.compare (wxT ("Event")) == 0)
                        {
                          if (atob (arg))
                            {
                              filec += wxT ("  void ") + WriteEvents (ctname, line) + wxT (";\n");
                            };
                        };
                    };
                };

              file.AddLine (wxT ("  /*#Events*/"));
              file.AddLine (filec);
              file.AddLine (wxT ("  /*#Others*/"));
            };
          file.AddLine (lbak);
        };
      file.AddLine (wxT ("#endif /*#CPWINDOW") + itoa (WN) + wxT ("*/\n"));

      file.Write ();
      file.Close ();
      fbak.Close ();
      wxRemoveFile (filename + wxT (".bak"));
    };

  //================================================================================================
  //window.cc      
  //================================================================================================
  filename = dirname + wxT ("/") + basename + itoa (WN) + wxT (".cc");

  int fexist = wxFileExists (filename);

  if (fexist != true)
    {
      //new file              
      file.Create (filename);
      List = GetContext ();
      for (uint a = 0; a < List.GetLinesCount (); a++)
        {
          line = List.GetLine (a);
          //ctype = eqparse (line, arg);
          xml_in (line, line, ctype, arg);
          if (ctype.compare (wxT ("Event")) == 0)
            {
              if (atob (arg))
                {
                  filec2 += wxT ("void\nCPWindow") + itoa (WN) + wxT ("::") + WriteEvents (wxT (""), line) + wxT ("\n{\n  //code here:)\n  mprint(wxT(\"_") + line + wxT ("\\n\"));\n};\n\n");
                };
            };
        };
      //fprintf(file,"  /*#Controls*/\n");
      for (int count = 0; count <= ChildCount; count++)
        {
          controle = Child[count];
          ctname = controle->GetName ();
          //fprintf(file,"  %s %s;\n",controle->GetClass ().char_str(),ctname.char_str());

          List = controle->GetContext ();
          for (uint a = 0; a < List.GetLinesCount (); a++)
            {
              line = List.GetLine (a);
              //ctype = eqparse (line, arg);
              xml_in (line, line, ctype, arg);
              if (ctype.compare (wxT ("Event")) == 0)
                {
                  if (atob (arg))
                    {
                      filec2 += wxT ("void\nCPWindow") + itoa (WN) + wxT ("::") + WriteEvents (ctname, line) + wxT ("\n{\n  //code here:)\n  mprint(wxT(\"") + ctname + wxT ("_") + line + wxT ("\\n\"));\n};\n\n");
                    };
                };
            };
        };

      file.AddLine (wxT ("#include\"") + PName + itoa (WN) + wxT (".h\"\n#include\"") + PName + itoa (WN) + wxT ("_d.cc\"\n\nCPWindow") + itoa (WN) + wxT (" Window") + itoa (WN) + wxT (";\n"));
      file.AddLine (wxT ("\n//Implementation"));
      file.AddLine (wxT ("\n") + filec2);
      file.AddLine (wxT ("\n"));
      file.Write ();
      file.Close ();
    }
  else
    {
      wxRenameFile (filename, filename + wxT (".bak"));

      //update file
      linesbak.Clear ();
      linesbak.LoadFromFile (filename + wxT (".bak"));

      fbak.Open (filename + wxT (".bak"));
      fbak.GoToLine (-1);
      file.Create (filename);

      while (fgetline (fbak, lbak))
        {
          int pos = lbak.compare (wxT ("//Implementation"));
          if (pos == 0)
            {
              filec2 = wxT ("");
              List = GetContext ();
              for (uint a = 0; a < List.GetLinesCount (); a++)
                {
                  line = List.GetLine (a);
                  //ctype = eqparse (line, arg);
                  xml_in (line, line, ctype, arg);
                  if (ctype.compare (wxT ("Event")) == 0)
                    {
                      if (atob (arg))
                        {
                          if (!testline (wxT ("CPWindow") + itoa (WN) + wxT ("::") + WriteEvents (wxT (""), line)))
                            {
                              filec2 += wxT ("void\nCPWindow") + itoa (WN) + wxT ("::") + WriteEvents (wxT (""), line) + wxT ("\n{\n  //code here:)\n  mprint(wxT(\"_") + line + wxT ("\\n\"));\n};\n\n");
                            };
                        };
                    };
                };
              for (int count = 0; count <= ChildCount; count++)
                {
                  controle = Child[count];
                  ctname = controle->GetName ();
                  List = controle->GetContext ();
                  for (uint a = 0; a < List.GetLinesCount (); a++)
                    {
                      line = List.GetLine (a);
                      //ctype = eqparse (line, arg);
                      xml_in (line, line, ctype, arg);
                      if (ctype.compare (wxT ("Event")) == 0)
                        {
                          if (atob (arg))
                            {
                              if (!testline (wxT ("CPWindow") + itoa (WN) + wxT ("::") + WriteEvents (ctname, line)))
                                {
                                  filec2 += wxT ("void\nCPWindow") + itoa (WN) + wxT ("::") + WriteEvents (ctname, line) + wxT ("\n{\n  //code here:)\n  mprint(wxT(\"") + ctname + wxT ("_") + line + wxT ("\\n\"));\n};\n\n");
                                };
                            };
                        };
                    };
                };
            };
          file.AddLine (lbak); //+lbak 2.8
        };
      if (filec2.length () > 0) file.AddLine (filec2);
      file.Write ();
      file.Close ();
      fbak.Close ();
      wxRemoveFile (filename + wxT (".bak"));
    };


  //================================================================================================
  //window description
  //================================================================================================
  filename = dirname + wxT ("/") + basename + itoa (WN) + wxT ("_d.cc");

  int dfexist = wxFileExists (filename);

  if (dfexist != true)
    {
      //new file              

      file.Create (filename);
      file.AddLine (wxT ("CPWindow") + itoa (WN) + wxT ("::CPWindow") + itoa (WN) + wxT ("(void)\n{"));
      file.AddLine (wxT ("//lxrad automatic generated block start, don't edit below!"));
      file.AddLine (wxT ("  SetFOwner(this);"));
      List = GetContext ();
      for (uint a = 0; a < List.GetLinesCount (); a++)
        {
          line = List.GetLine (a);
          //ctype = eqparse (line, arg);
          xml_in (line, line, ctype, arg);
          if (ctype.compare (wxT ("Event")) != 0)
            {
              if ((ctype.compare (wxT ("String")) == 0) || (ctype.compare (wxT ("StringList")) == 0) || (ctype.compare (wxT ("File")) == 0))
                {
                  if (arg.size () > 0)
                    file.AddLine (wxT ("  Set") + line + wxT ("(wxT(\"") + arg + wxT ("\"));"));
                  else
                    file.AddLine (wxT ("  Set") + line + wxT ("(wxT(\"\"));"));
                }
              else
                {
                  if ((ctype.compare (wxT ("SubMenu")) != 0) && (ctype.compare (wxT ("PopupMenu")) != 0))
                    file.AddLine (wxT ("  Set") + line + wxT ("(") + arg + wxT (");"));
                  else if (arg.compare (wxT ("NULL")) != 0)
                    file.AddLine (wxT ("  Set") + line + wxT ("(&") + arg + wxT (");"));
                  else
                    file.AddLine (wxT ("  Set") + line + wxT ("(NULL);"));
                };
            }
          else
            {
              if (ctype.compare (wxT ("Event")) == 0)
                {
                  if (atob (arg))
                    file.AddLine (wxT ("  ") + WriteControlEvents (wxT (""), line));
                }
            };
        };


      for (int count = 0; count <= ChildCount; count++)
        {
          controle = Child[count];
          ctname = controle->GetName ();
          file.AddLine (wxT ("  //") + ctname);
          file.AddLine (wxT ("  ") + ctname + wxT (".SetFOwner(this);"));
          controle->SetVisible (controle->GetAux ());
          List = controle->GetContext ();
          for (uint a = 0; a < List.GetLinesCount (); a++)
            {
              line = List.GetLine (a);
              //ctype = eqparse (line, arg);
              xml_in (line, line, ctype, arg);
              if (ctype.compare (wxT ("Event")) != 0)
                {
                  if ((ctype.compare (wxT ("String")) == 0) || (ctype.compare (wxT ("StringList")) == 0) || (ctype.compare (wxT ("File")) == 0) || (ctype.compare (wxT ("MenuItems")) == 0))
                    {
                      if (arg.size () > 0)
                        file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(wxT(\"") + arg + wxT ("\"));"));
                      else
                        file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(wxT(\"\"));"));
                    }
                  else
                    {
                      if ((ctype.compare (wxT ("SubMenu")) != 0) && (ctype.compare (wxT ("PopupMenu")) != 0))
                        file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(") + arg + wxT (");"));
                      else if (arg.compare (wxT ("NULL")) != 0)
                        file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(&") + arg + wxT (");"));
                      else
                        file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(NULL);"));
                    }
                }
              else
                {
                  if (ctype.compare (wxT ("Event")) == 0)
                    {
                      if (atob (arg))
                        file.AddLine (wxT ("  ") + ctname + wxT (".") + WriteControlEvents (ctname, line));
                    }


                };
            };

          int i = ctname.rfind (wxT ("_"));
          if (i < 0)
            file.AddLine (wxT ("  CreateChild(&") + ctname + wxT (");"));
          else
            file.AddLine (wxT ("  ") + ctname.substr (0, i) + wxT (".CreateChild(&") + ctname + wxT (");"));
        };
      file.AddLine (wxT ("  /*#Others*/"));
      file.AddLine (wxT ("//lxrad automatic generated block end, don't edit above!"));
      file.AddLine (wxT ("};"));
      file.Write ();
      file.Close ();
    }
  else //file exists
    {
      wxRenameFile (filename, filename + wxT (".bak"));
      fbak.Open (filename + wxT (".bak"));
      fbak.GoToLine (-1);
      file.Create (filename);

      while (fgetline (fbak, lbak))
        {
          int pos = lbak.compare (wxT ("  SetFOwner(this);"));

          if (pos == 0)
            {
              int pos2 = 1;
              while (fgetline (fbak, lbak) && pos2)
                {
                  pos2 = lbak.compare (wxT ("  /*#Others*/"));
                };

              file.AddLine (wxT ("  SetFOwner(this);"));
              List = GetContext ();
              for (uint a = 0; a < List.GetLinesCount (); a++)
                {
                  line = List.GetLine (a);
                  //ctype = eqparse (line, arg);
                  xml_in (line, line, ctype, arg);
                  if (ctype.compare (wxT ("Event")) != 0)
                    {
                      if ((ctype.compare (wxT ("String")) == 0) || (ctype.compare (wxT ("StringList")) == 0) || (ctype.compare (wxT ("File")) == 0))
                        {
                          if (arg.size () > 0)
                            file.AddLine (wxT ("  Set") + line + wxT ("(wxT(\"") + arg + wxT ("\"));"));
                          else
                            file.AddLine (wxT ("  Set") + line + wxT ("(wxT(\"\"));"));
                        }
                      else
                        {
                          if ((ctype.compare (wxT ("SubMenu")) != 0) && (ctype.compare (wxT ("PopupMenu")) != 0))
                            file.AddLine (wxT ("  Set") + line + wxT ("(") + arg + wxT (");"));
                          else if (arg.compare (wxT ("NULL")) != 0)
                            file.AddLine (wxT ("  Set") + line + wxT ("(&") + arg + wxT (");"));
                          else
                            file.AddLine (wxT ("  Set") + line + wxT ("(NULL);"));
                        };
                    }
                  else
                    {
                      if (ctype.compare (wxT ("Event")) == 0)
                        {
                          if (atob (arg))
                            file.AddLine (wxT ("  ") + WriteControlEvents (wxT (""), line));
                        }
                    };
                };


              for (int count = 0; count <= ChildCount; count++)
                {
                  controle = Child[count];
                  ctname = controle->GetName ();
                  file.AddLine (wxT ("  //") + ctname);
                  file.AddLine (wxT ("  ") + ctname + wxT (".SetFOwner(this);"));
                  controle->SetVisible (controle->GetAux ());
                  List = controle->GetContext ();
                  for (uint a = 0; a < List.GetLinesCount (); a++)
                    {
                      line = List.GetLine (a);
                      //ctype = eqparse (line, arg);
                      xml_in (line, line, ctype, arg);
                      if (ctype.compare (wxT ("Event")) != 0)
                        {
                          if ((ctype.compare (wxT ("String")) == 0) || (ctype.compare (wxT ("StringList")) == 0) || (ctype.compare (wxT ("File")) == 0) || (ctype.compare (wxT ("MenuItems")) == 0))
                            {
                              if (arg.size () > 0)
                                file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(wxT(\"") + arg + wxT ("\"));"));
                              else
                                file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(wxT(\"\"));"));
                            }
                          else
                            {
                              if ((ctype.compare (wxT ("SubMenu")) != 0) && (ctype.compare (wxT ("PopupMenu")) != 0))
                                file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(") + arg + wxT (");"));
                              else if (arg.compare (wxT ("NULL")) != 0)
                                file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(&") + arg + wxT (");"));
                              else
                                file.AddLine (wxT ("  ") + ctname + wxT (".Set") + line + wxT ("(NULL);"));
                            }
                        }
                      else
                        {
                          if (ctype.compare (wxT ("Event")) == 0)
                            {
                              if (atob (arg))
                                file.AddLine (wxT ("  ") + ctname + wxT (".") + WriteControlEvents (ctname, line));
                            }


                        };
                    };

                  int i = ctname.rfind (wxT ("_"));
                  if (i < 0)
                    file.AddLine (wxT ("  CreateChild(&") + ctname + wxT (");"));
                  else
                    file.AddLine (wxT ("  ") + ctname.substr (0, i) + wxT (".CreateChild(&") + ctname + wxT (");"));
                };
              file.AddLine (wxT ("  /*#Others*/"));

            };
          file.AddLine (lbak);
        };


      file.Write ();
      file.Close ();
      fbak.Close ();
      wxRemoveFile (filename + wxT (".bak"));
    }
}

void
CPWindow2::MakeProject (String basename)
{
  String filename, ctname;
  wxTextFile file;
  CStringList List;
  int i;


  //write xml project
  filename = basename + wxT (".prj_lxrad");
  file.Create (filename);
  file.AddLine (wxT ("<LXRAD_Project>"));
  file.AddLine (xml_out (wxT ("Version"), wxT ("String"), Version));
  file.AddLine (xml_out (wxT ("PName"), wxT ("String"), PName));
  if (POptions.size () > 0)
    file.AddLine (xml_out (wxT ("POptions"), wxT ("String"), POptions));
  else
    file.AddLine (xml_out (wxT ("POptions"), wxT ("String"), wxT ("")));
  if (PLibs.size () > 0)
    file.AddLine (xml_out (wxT ("PLibs"), wxT ("String"), PLibs));
  else
    file.AddLine (xml_out (wxT ("PLibs"), wxT ("String"), wxT ("")));
  if (PIncludeFile.size () > 0)
    file.AddLine (xml_out (wxT ("PIncludeFile"), wxT ("String"), PIncludeFile));
  else
    file.AddLine (xml_out (wxT ("PIncludeFile"), wxT ("String"), wxT ("")));
  file.AddLine (xml_out (wxT ("PNW"), wxT ("String"), itoa (PNW)));
  file.AddLine (wxT ("</LXRAD_Project>"));
  file.Write ();
  file.Close ();

  filename = basename + wxT ("_") + itoa (WN) + wxT (".lxrad");


  Window2.SetVisible (Window2.GetAux (), false);
  for (i = 0; i < bc; i++)
    {
      itens[i].ctrl->SetVisible (itens[i].ctrl->GetAux (), false);
    }

  //write window xml
  Window2.WriteXMLContext (filename);
};

void
ControlLoadXMLContext (CControl * ctrl, String filename)
{
  wxTextFile file2;
  CStringList list;
  String line;

  file2.Open (filename);
  file2.GoToLine (-1);

  if (file2.IsOpened ())
    {
      list.Clear ();
      while (fgetline (file2, line))
        {
          if (line.compare (wxT ("<") + ctrl->GetName () + wxT (">")) == 0)
            {
              fgetline (file2, line);
              do
                {
                  list.AddLine (line);
                  fgetline (file2, line);
                }
              while (line[0] == ' ');
              ctrl->SetContext (list);
              ctrl->SetAux (ctrl->GetVisible ());

              while (line.compare (wxT ("</") + ctrl->GetName () + wxT (">")) != 0)
                {
                  String controlclass, ctype, name, cname;

                  cname = line.substr (1, line.size () - 2);
                  fgetline (file2, line);
                  xml_in (line, name, ctype, controlclass);

                  CControl *ch = newcontrol (controlclass, ctrl);
                  ch->SetName (cname);

                  //funcionalidades
                  ch->SetCanFocus (true);
                  ch->SetCanExecuteEvent (true);
                  ch->SetFOwner (ctrl);
                  ch->SetAux (ch->GetVisible ());
                  if (ch->GetClass ().compare (wxT ("CItemMenu")) == 0)
                    {
                      ch->SetVisible (false, false);
                    };
                  //ch->EvMouseButtonPress = EVMOUSEBUTTONPRESS & CPWindow2::_MouseButtonPress;
                  //ch->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow2::_MouseButtonRelease;
                  //ch->EvMouseMove = EVMOUSEMOVE & CPWindow2::_MouseMove;
                  //ch->EvKeyboardPress = EVKEYBOARDPRESS & CPWindow2::_KeyboardPress;

                  ctrl->CreateChild (ch);

                  //mprint (cname + wxT("\n"));

                  if (ch != NULL)
                    ControlLoadXMLContext (ch, filename);
                  else
                    printf ("Child Not Found! %s \n", (char*) name.char_str ());

                  do
                    {
                      fgetline (file2, line);
                    }
                  while ((line.compare (wxT ("</") + cname + wxT (">")) != 0));
                  fgetline (file2, line);
                };

            };

        };

      file2.Close ();
    }
  else
    printf ("File not found!\n");

};

bool
CPWindow2::ReLoadProject (void)
{
  return LoadProject (PDir, PName + wxT (".prj_lxrad"));
}

bool
CPWindow2::LoadProject (String dirname, String filename)
{
  /*
    String dirname ="./"+filename.substr(0,filename.find(".lxrad"));
    cout<<"file= "<<filename<<endl;
    cout<<"dir = "<<dirname<<endl;
   */
  String basename, name;
  wxTextFile file1;
  String line, oname, type, value;
  CStringList list;
  int pos;

  /*
    int pos = dirname.rfind ("/");
    if (pos >= 0)
      {
        basename = dirname + dirname.substr (pos, dirname.size () - 1-pos);
      }
    else
      {
        basename = dirname + "/" + dirname;
      };
   */

  pos = filename.find (wxT (".prj_lxrad"));

  if (pos <= 0)
    {
      Message (wxT ("Invalid File!"));
      return false;
    };

  basename = dirname + wxT ("/") + filename.substr (0, pos);
  name = basename + wxT (".prj_lxrad");


  file1.Open (name);
  file1.GoToLine (-1);
  if (file1.IsOpened ())
    {
      while (fgetline (file1, line))
        {
          xml_in (line, oname, type, value);
          if (oname.compare (wxT ("PName")) == 0)
            PName = value;
          if (oname.compare (wxT ("POptions")) == 0)
            POptions = value;
          if (oname.compare (wxT ("PLibs")) == 0)
            PLibs = value;
          if (oname.compare (wxT ("PIncludeFile")) == 0)
            PIncludeFile = value;
          if (oname.compare (wxT ("PNW")) == 0)
            PNW = atoi (value);
          //  if (line.compare ("Version") == 0)
        };
      file1.Close ();
    }
  else
    {
      Message (wxT ("File not Found!"));
      return false;
    };

  if ((WN > PNW) && (WN == PNW + 1))
    {
      PNW++;
    }
  else
    {
      if (WN > PNW)
        {
          Message (wxT ("Window Number Invalid!"));
          return false;
        };
    };

  basename += wxT ("_") + itoa (WN) + wxT (".lxrad");

  SetName (wxT ("window") + itoa (WN));
  ControlLoadXMLContext (dynamic_cast<CControl *> (this), basename);

  //SetVisible(true);

  int ys=0;
  for (bc = 0; bc <= GetChildCount (); bc++)
    {
      itens[bc].ctrl = GetChild (bc);
      
      //if control is not drawable 
      if(((itens[bc].ctrl->GetX() == 0)&&
      (itens[bc].ctrl->GetY()==0)&&
      (itens[bc].ctrl->GetWidth ()==10)&&
      (itens[bc].ctrl->GetHeight () == 10))||(itens[bc].ctrl->GetClass () == wxT("CPMenu")))
      {
         itens[bc].ctrl->SetX(2);
         itens[bc].ctrl->SetY(ys);
         itens[bc].ctrl->SetWidth (40);
         itens[bc].ctrl->SetHeight (15);
         ys+=20;
      }        
      
      itens[bc].Bitmap = new wxBitmap (itens[bc].ctrl->GetWidth (), itens[bc].ctrl->GetHeight (), -1);
    }


  ListPropierties (this);


  return true;
};

void
CPWindow2::ListPropierties (CControl * control)
{
  String line, arg, ctype;
  CStringList cList;
  cList.Clear ();

  if (control == NULL)control = &Window2;


  control->SetVisible (control->GetAux (), false);

  cList = control->GetContext ();

  //debug
  /*
     printf("***********************************************\n");
     for (guint l = 0; l < cList.GetLinesCount (); l++)
     printf("%s\n",cList.GetLine(l).char_str()); 
     printf("***********************************************\n");
   */

  Window3.DestroyChilds ();
  Window4.DestroyChilds ();
  Window6.combo1.DeleteItems ();
  Window6.combo1.AddItem (GetName ());
  for (int i = 0; i <= GetChildCount (); i++)
    Window6.combo1.AddItem (GetChild (i)->GetName ());
  Window6.combo1.SetSelectedItem (control->GetName ());

  int b = 0, c = 0;
  for (uint a = 0; a < cList.GetLinesCount (); a++)
    {
      line = cList.GetLine (a);
      //ctype = eqparse (line, arg);
      xml_in (line, line, ctype, arg);

      if (ctype.compare (wxT ("Event")) == 0)
        {
          CCheckBox *control1;
          control1 = new CCheckBox;
          control1->SetName (wxT ("ccheckbox") + itoa (b + 1));
          control1->SetX (15);
          control1->SetY (3 + 22 * b);
          control1->SetWidth (150);
          control1->SetCheck (atob (arg));
          control1->SetFOwner (this);
          control1->EvOnCheckBox = EVONCHECKBOX & CPWindow4::checkboxclick;
          control1->SetText (line);
          Window4.CreateChild (control1);
          b++;
        }
      else
        {
          if (ctype.compare (wxT ("Event")) != 0)
            {
              CLabel *control1;
              control1 = new CLabel;
              control1->SetText (wxT (""));
              control1->SetName (wxT ("clabel") + itoa (c + 1));
              control1->SetX (0);
              control1->SetWidth (85);
              control1->SetY (3 + 26 * c);
              control1->SetText (line);
              Window3.CreateChild (control1);

              CEdit *control2;
              control2 = new CEdit;
              control2->SetName (wxT ("cedit") + itoa (c + 1));
              control2->SetX (85);
              control2->SetY (3 + 26 * c);
              control2->SetFOwner (&Window3);
              control2->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
              control2->SetText (arg);
              Window3.CreateChild (control2);

              if (ctype.compare (wxT ("File")) == 0)
                {
                  CToolButton *control3;
                  control3 = new CToolButton;
                  control3->SetName (wxT ("ctoolbutton") + itoa (c + 1));
                  control3->SetX (165);
                  control3->SetY (3 + 26 * c);
                  control3->SetWidth (26);
                  control3->SetHeight (26);
                  control3->SetTag (c + 1);
                  control3->SetImgData (b_xpm);
                  control3->SetFOwner (&Window3);
                  control3->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow3::FileMouseButtonRelease;
                  control3->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
                  Window3.CreateChild (control3);
                };
              if (ctype.compare (wxT ("StringList")) == 0)
                {
                  control2->SetText (wxT ("CList"));
                  control2->SetReadOnly (true);
                  CToolButton *control3;
                  control3 = new CToolButton;
                  control3->SetName (wxT ("ctoolbutton") + itoa (c + 1));
                  control3->SetX (165);
                  control3->SetY (3 + 26 * c);
                  control3->SetWidth (26);
                  control3->SetHeight (26);
                  control3->SetTag (c + 1);
                  control3->SetImgData (b_xpm);
                  control3->SetFOwner (&Window3);
                  control3->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow7::StringListMouseButtonRelease;
                  control3->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
                  Window3.CreateChild (control3);
                };
              if (ctype.compare (wxT ("MenuItems")) == 0)
                {
                  //control2->SetText ("CMenuItens");
                  control2->SetReadOnly (true);
                  CToolButton *control3;
                  control3 = new CToolButton;
                  control3->SetName (wxT ("ctoolbutton") + itoa (c + 1));
                  control3->SetX (165);
                  control3->SetY (3 + 26 * c);
                  control3->SetWidth (26);
                  control3->SetHeight (26);
                  control3->SetTag (c + 1);
                  control3->SetImgData (b_xpm);
                  control3->SetFOwner (&Window3);
                  control3->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow8::MenuItensMouseButtonRelease;
                  control3->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
                  Window3.CreateChild (control3);
                };
              if (ctype.compare (wxT ("SubMenu")) == 0)
                {
                  //control2->SetText ("SubMenu");
                  control2->SetReadOnly (true);
                  CToolButton *control3;
                  control3 = new CToolButton;
                  control3->SetName (wxT ("ctoolbutton") + itoa (c + 1));
                  control3->SetX (165);
                  control3->SetY (3 + 26 * c);
                  control3->SetWidth (26);
                  control3->SetHeight (26);
                  control3->SetTag (c + 1);
                  control3->SetEnable (0);
                  control3->SetImgData (b_xpm);
                  control3->SetFOwner (&Window3);
                  control3->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow9::SubMenuMouseButtonRelease;
                  control3->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
                  Window3.CreateChild (control3);
                };
              if (ctype.compare (wxT ("PopupMenu")) == 0)
                {
                  //control2->SetText ("PoupMenu");
                  control2->SetReadOnly (true);
                  CToolButton *control3;
                  control3 = new CToolButton;
                  control3->SetName (wxT ("ctoolbutton") + itoa (c + 1));
                  control3->SetX (165);
                  control3->SetY (3 + 26 * c);
                  control3->SetWidth (26);
                  control3->SetHeight (26);
                  control3->SetTag (c + 1);
                  control3->SetEnable (0);
                  control3->SetImgData (b_xpm);
                  control3->SetFOwner (&Window3);
                  control3->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow9::SubMenuMouseButtonRelease;
                  control3->EvOnFocusOut = EVONFOCUSOUT & CPWindow3::editfocusout;
                  Window3.CreateChild (control3);
                };

              c++;
            };
        };
    };
  Window3.Draw ();
  Window4.Draw ();
  Window3.Update ();
  Window4.Update ();

  _EvKeyboardPress (this, 0, 0, 0, 0);

};

void
CPWindow2::SCreateChild (CControl * control)
{
  CreateChild (control);

  if (control->GetClass ().compare (wxT ("CPMenu")) == 0)
    {
      CControl *ctrl;

      for (int c = 0; c <= ChildCount; c++)
        {
          if (Child[c]->GetClass ().compare (wxT ("CPMenu")) != 0)
            {
              ctrl = Child[c];
              Child[c] = Child[ChildCount];
              Child[ChildCount] = ctrl;
              break;
            };
        };
    };
};

/*
void
CPWindow2::_KeyboardPress (CControl * control, uint x, uint y, char *key, uint mask)
{
	
  KeySym dkey = XKeycodeToKeysym (Window2.GetADisplay (), key, 1);


  if (mask & ShiftMask)
    switch (dkey)
      {

//case XK_Delete:
//cout<<"delete\n";	
//break;

      case XK_Right:
        control->SetX (control->GetX () + 1);
        break;
      case XK_Left:
        control->SetX (control->GetX () - 1);
        break;
      case XK_Down:
        control->SetY (control->GetY () + 1);
        break;
      case XK_Up:
        control->SetY (control->GetY () - 1);
        break;
      };

  if (mask & ControlMask)
    switch (dkey)
      {
      case XK_Right:
        control->SetWidth (control->GetWidth () + 1);
        break;
      case XK_Left:
        control->SetWidth (control->GetWidth () - 1);
        break;
      case XK_Down:
        control->SetHeight (control->GetHeight () + 1);
        break;
      case XK_Up:
        control->SetHeight (control->GetHeight () - 1);
        break;
      };

};
 */

/*
void
CPWindow2::_MouseButtonClick (CControl * control, uint button, uint x, uint y, uint state)
{
#ifdef __UNICODE__		  
  printf("_MouseButtonClick %ls\n",control->GetClass().char_str());
#else
  printf("_MouseButtonClick %s\n",control->GetClass().char_str());
#endif
  if (operation.compare (wxT("editar")) == 0)
    {
      if (button == 1)
        {
          Move = false;
        }
    }
  else
    {
      CControl *ncontrol = newcontrol (operation, &Window2);
      ncontrol->SetVisible (false, false);
      ncontrol->SetVisible (true, false);

      if (ncontrol->GetClass ().compare (wxT("CFileDialog")) != 0)
        {
          ncontrol->SetCanExecuteEvent (true);
          ncontrol->SetCanFocus (true);
        }
      else
        {
          ncontrol->SetCanExecuteEvent (false);
          ncontrol->SetCanFocus (false);
          ncontrol->SetVisible (false, false);
        };

      if (ncontrol->GetClass ().compare (wxT("CItemMenu")) == 0)
        {
          ncontrol->SetVisible (false, false);
        }
      ncontrol->SetFOwner (&Window2);
      ncontrol->EvMouseButtonPress = EVMOUSEBUTTONPRESS & CPWindow2::_MouseButtonPress;
      ncontrol->EvMouseButtonRelease = EVMOUSEBUTTONRELEASE & CPWindow2::_MouseButtonRelease;
      ncontrol->EvMouseMove = EVMOUSEMOVE & CPWindow2::_MouseMove;
      //ncontrol->EvKeyboardPress = EVKEYBOARDPRESS & CPWindow2::_KeyboardPress;
      SCreateChild (ncontrol);
      ncontrol->SetX (x);
      ncontrol->SetY (y);
      ncontrol->Draw ();
      operation = wxT("editar");
    };
};
 */

/*
void
CPWindow2::_MouseButtonPress (CControl * control, uint button, uint x, uint y, uint state)
{	
  Mcontrol=&Window2;
  if ((button == wxMOUSE_BTN_LEFT)&&(control != NULL)&&(control != &Window2))
    {	    
      Move = true;
      
//      xp = control->GetX () - x;
//      yp = control->GetY () - y;
      
      xp = - x;
      yp = - y;
      Mcontrol=control;
      
      //Mcontrol->SetEnable(false);
      Mcontrol->SetVisible (false);
#ifdef __UNICODE__  
  printf("*****************Move=%i  mcontrol=%ls ",Move,Mcontrol->GetName().char_str());	
#else
  printf("*****************Move=%i  mcontrol=%s ",Move,Mcontrol->GetName().char_str());	
#endif
  };

};
 */

/*
void
CPWindow2::_MouseButtonRelease (CControl * control, uint button, uint x, uint y, uint state)
{
 
  if ((button == wxMOUSE_BTN_LEFT) && (Move) )
    {
      Move = false;
      if(Mcontrol == control)
      {
        xp += control->GetX ();
        yp += control->GetY ();
      
      };
      
      if(Mcontrol != &Window2)
      {
      //if (Mcontrol->GetClass ().compare ("CWindow") != 0)
        {

        if (xo + yo != -2)
            {
              Window2.Canvas.Init();	
              Window2.Canvas.Rectangle (false, xo + xp, yo + yp, Mcontrol->GetWidth ()-1, Mcontrol->GetHeight ()-1);
              Window2.Canvas.End();
              xo = -1;
              yo = -1;
            };

          Window2.Canvas.SetFunction (wxCOPY);

          //control->Eraser ();

//	  Mcontrol->SetVisible (false);
          Mcontrol->SetX (x + xp);
          Mcontrol->SetY (y + yp);
//	  Mcontrol->SetVisible (true);
           
          Mcontrol->SetVisible (true);

          //control->Draw ();
          //Window2.Update ();
          //Mcontrol=&Window2;
        };
        };
      //Window2.Draw();
      Window2.Update ();
      
    }

  if (Mcontrol == &Window2)
    SetControlOnFocus (NULL);
  else
    SetControlOnFocus (Mcontrol);

  ListPropierties (Mcontrol);
  
  //debug 
  
//  if (GetControlOnFocus () == NULL)
//    printf ("control = %s \t NULL \n", control->GetName ().char_str ());
//  else
//    printf ("control = %s \t%s\n", control->GetName ().char_str (), GetControlOnFocus ()->GetName ().char_str ());
  
};
 */

/*
void
CPWindow2::_MouseMove (CControl * control, uint button, uint x, uint y, uint state)
{


if(control != NULL)
{
//#ifdef __UNICODE__  
//  printf("$$$$$$$$$$$$$$Move=%i  mcontrol=%ls  control=%ls\n",Move,Mcontrol->GetName().char_str(),control->GetName().char_str());	
//#else
//  printf("$$$$$$$$$$$$$$Move=%i  mcontrol=%s  control=%s\n",Move,Mcontrol->GetName().char_str(),control->GetName().char_str());	
//#endif
//};


  if (Move)
    {
      if (Mcontrol != &Window2)
      {
      
//      if(Mcontrol->GetVisible()) 
//       {
//         Mcontrol->SetVisible(false);
//       };
      
      Window2.Canvas.Init();
      Window2.Canvas.SetFunction (wxINVERT);
      if (xo + yo != -2)
          Window2.Canvas.Rectangle (false, xp + xo, yp + yo, Mcontrol->GetWidth ()-1, Mcontrol->GetHeight ()-1);
       
//       if(control == &Window2)
//       {
//        Mcontrol->SetX(xp+x);
//        Mcontrol->SetY(yp+y);
//	}
//	else
//	{
//        Mcontrol->SetX(xp+x+control->GetX());
//        Mcontrol->SetY(yp+y+control->GetY());
//	};
	
       if(control == &Window2)
       {
        Window2.Canvas.Rectangle (false, xp + x, yp + y, Mcontrol->GetWidth ()-1, Mcontrol->GetHeight ()-1);
        xo = x;
        yo = y;
       }
       else
       {
        Window2.Canvas.Rectangle (false, xp + x+xo-control->GetX(), yp + y-control->GetY(), Mcontrol->GetWidth ()-1, Mcontrol->GetHeight ()-1);
        xo = x-control->GetX();
        yo = y-control->GetY();
       }
       
       Window2.Canvas.End();

       
        };
    };
};
 */


String
CPWindow2::WriteEvents (String name, String event)
{
  int pos = 0;
  String out = name + wxT ("_") + event;

  pos = event.find (wxT ("Mouse"));
  if (pos >= 0)
    {
      out += wxT ("(CControl * control, uint button, uint x, uint y,uint state)");
    }
  else
    {
      pos = event.find (wxT ("Keyboard"));
      if (pos >= 0)
        out += wxT ("(CControl * control, uint key, uint x, uint y,uint mask)");
      else
        out += wxT ("(CControl * control)");
    };
  return out;
};

String
CPWindow2::WriteControlEvents (String name, String event)
{
  String
  SWN =
          itoa (WN);
  String out = event + wxT ("=") + uppercase (event) + wxT (" & CPWindow") + SWN + wxT ("::") + name + wxT ("_") + event + wxT (";");
  return out;
};


void
CPWindow2::_EvOnShow(CControl * control)
{
  //FIXME control disaper on resize
  //code here:)
  //mprint(wxT("_EvOnShow\n"));
  //_EvOnDraw(control);
};


