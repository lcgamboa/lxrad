/* ########################################################################

   LXRAD -  GUI for X programing

   ########################################################################

   Copyright (c) : 2001  Luis Claudio Gamboa Lopes

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

/**
 * \file cobject.h
 * \author Luis Claudio Gamboa Lopes
 * \date 05-30-2008
 */

#ifndef COBJECT
#define COBJECT

#include"clxrad.h"

/** \brief Generic Object.
 *
 * Generic Object Class.
 */

class CObject
{
protected:
  bool Ev[EVMAX];
  uint Evcount;
  lxString Name;
  lxString Class;
  lxStringList Context;
  uint Tag;
  int Aux;
public:
    CObject (void);
    virtual ~ CObject (void);
//proprierties
 /**
  * Set Control  Name.
  *
  * \param name new name.
  * \return void.
  */
  void SetName (const lxString name);
 /**
  * Get Control Name.
  *
  * \return Object Name.
  */
  lxString GetName (void);
 /**
  * Get Classe Name.
  *
  * \return Object Class Name
  */
  lxString GetClass (void);
 /**
  * Set Classe Name.
  *
  * \param classn new class name.
  * \return void.
  */
  void SetClass (const lxString classn);
 /**
  * Get XML Context Name.
  *
  * \return XML context.
  */
  virtual lxStringList GetContext (void);
 /**
  * Set XML Context .
  *
  * \param context XML context.
  * \return void.
  */
  virtual void SetContext (lxStringList context);
 /**
  * Get Object Events.
  *
  * \return bool 
  */
  bool GetEv (bool reset = false);
 /**
  * Set Object Events.
  *
  * \param reset.
  * \return bool.
  */
  void SetEv (bool value, bool reset = false);
 /**
  * Set Object Tag.
  *
  * \param tag.
  * \return void.
  */
  void SetTag (uint tag);
 /**
  * Get Object Tag.
  *
  * \return Object Tag
  */
  uint GetTag (void);
 /**
  * Set Object Aux.
  *
  * \param tag.
  * \return void.
  */
  void SetAux (int tag);
 /**
  * Get Object Aux.
  *
  * \return Object Aux
  */
  int GetAux (void);
};

#endif
