#ifndef CONTROLSDEF
#define CONTROLSDEF
CControl *newcontrol (lxString controltype, CControl * owner);
void resetcontrolscount (void);
void getbuttons (CControl * owner);
void drawcontrol(wxMemoryDC* NDC, CControl *ctrl);
#endif
