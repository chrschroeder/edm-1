//  edm - extensible display manager

//  Copyright (C) 1999 John W. Sinclair

//  This program is free software; you can redistribute it and/or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation; either version 2 of the License, or
//  (at your option) any later version.

//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
//  GNU General Public License for more details.

//  You should have received a copy of the GNU General Public License
//  along with this program; if not, write to the Free Software
//  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.

#ifndef __radio_button_h
#define __radio_button_h 1

#include "act_grf.h"
#include "entry_form.h"

#ifdef __epics__
#include "cadef.h"
#endif

#ifndef __epics__
#define MAX_ENUM_STATES 4
#define MAX_ENUM_STRING_SIZE 16
#endif

#define RBTC_K_COLORMODE_STATIC 0
#define RBTC_K_COLORMODE_ALARM 1

#define RBTC_MAJOR_VERSION 1
#define RBTC_MINOR_VERSION 0
#define RBTC_RELEASE 0

#define RBTC_K_LITERAL 1
#define RBTC_K_PV_STATE 2

#ifdef __radio_button_cc

#include "radio_button.str"

static void radioBoxEventHandler (
  Widget w,
  XtPointer client,
  XEvent *e,
  Boolean *continueToDispatch );

static char *dragName[] = {
  activeRadioButtonClass_str1,
};

static void selectDrag (
   Widget w,
   XEvent *e,
   String *params,
   Cardinal numParams );

static void rbt_infoUpdate (
  struct event_handler_args ast_args );

static void putValue (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbtc_edit_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbtc_edit_update (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbtc_edit_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbtc_edit_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbtc_edit_cancel_delete (
  Widget w,
  XtPointer client,
  XtPointer call );

static void rbt_controlUpdate (
  struct event_handler_args ast_args );

static void rbt_alarmUpdate (
  struct event_handler_args ast_args );

static void rbt_monitor_control_connect_state (
  struct connection_handler_args arg );

#endif

class activeRadioButtonClass : public activeGraphicClass {

private:

friend void radioBoxEventHandler (
  Widget w,
  XtPointer client,
  XEvent *e,
  Boolean *continueToDispatch );

friend void selectDrag (
   Widget w,
   XEvent *e,
   String *params,
   Cardinal numParams );

friend void rbt_infoUpdate (
  struct event_handler_args ast_args );

friend void putValue (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbtc_edit_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbtc_edit_update (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbtc_edit_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbtc_edit_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbtc_edit_cancel_delete (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void rbt_controlUpdate (
  struct event_handler_args ast_args );

friend void rbt_alarmUpdate (
  struct event_handler_args ast_args );

friend void rbt_monitor_control_connect_state (
  struct connection_handler_args arg );

pvConnectionClass connection;

int opComplete, pvCheckExists;

int bufX, bufY, bufW, bufH;

short curValue;

int buttonColor, bufButtonColor;
int topShadowColor, bufTopShadowColor;
int botShadowColor, bufBotShadowColor;
int bufFgColor, bufBgColor;
pvColorClass fgColor, bgColor;
colorButtonClass fgCb, bgCb, buttonCb, topShadowCb, botShadowCb;
int fgColorMode, bgColorMode, bufFgColorMode, bufBgColorMode;

char *stateString[MAX_ENUM_STATES]; // allocated at run-time
int numStates;

fontMenuClass fm;
char fontTag[63+1], bufFontTag[63+1];
XmFontList fontList;
XFontStruct *fs;
int fontAscent, fontDescent, fontHeight;

#ifdef __epics__
chid controlPvId;
evid alarmEventId, controlEventId;
#endif

char bufControlPvName[activeGraphicClass::MAX_PV_NAME+1];
expStringClass controlPvExpStr;

int controlExists, widgetsCreated, active, activeMode;

Widget radioBox, pb[MAX_ENUM_STATES];

int needConnectInit, needInfoInit, needDraw, needRefresh;

public:

activeRadioButtonClass::activeRadioButtonClass ( void );

activeRadioButtonClass::~activeRadioButtonClass ( void );

activeRadioButtonClass::activeRadioButtonClass
 ( const activeRadioButtonClass *source );

char *activeRadioButtonClass::objName ( void ) {

  return name;

}

int activeRadioButtonClass::createInteractive (
  activeWindowClass *aw_obj,
  int x,
  int y,
  int w,
  int h );

int activeRadioButtonClass::save (
  FILE *f );

int activeRadioButtonClass::createFromFile (
  FILE *fptr,
  char *name,
  activeWindowClass *actWin );

int activeRadioButtonClass::genericEdit ( void );

int activeRadioButtonClass::edit ( void );

int activeRadioButtonClass::editCreate ( void );

int activeRadioButtonClass::draw ( void );

int activeRadioButtonClass::erase ( void );

int activeRadioButtonClass::drawActive ( void );

int activeRadioButtonClass::eraseActive ( void );

int activeRadioButtonClass::expand1st (
  int numMacros,
  char *macros[],
  char *expansions[] );

int activeRadioButtonClass::expand2nd (
  int numMacros,
  char *macros[],
  char *expansions[] );

int activeRadioButtonClass::containsMacros ( void );

int activeRadioButtonClass::createWidgets ( void );

int activeRadioButtonClass::activate ( int pass, void *ptr );

int activeRadioButtonClass::deactivate ( int pass );

void activeRadioButtonClass::updateDimensions ( void );

void activeRadioButtonClass::executeDeferred ( void );

char *activeRadioButtonClass::firstDragName ( void );

char *activeRadioButtonClass::nextDragName ( void );

char *activeRadioButtonClass::dragValue (
  int i );

void activeRadioButtonClass::changeDisplayParams (
  unsigned int flag,
  char *fontTag,
  int alignment,
  char *ctlFontTag,
  int ctlAlignment,
  char *btnFontTag,
  int btnAlignment,
  int textFgColor,
  int fg1Color,
  int fg2Color,
  int offsetColor,
  int bgColor,
  int topShadowColor,
  int botShadowColor );

void activeRadioButtonClass::changePvNames (
  int flag,
  int numCtlPvs,
  char *ctlPvs[],
  int numReadbackPvs,
  char *readbackPvs[],
  int numNullPvs,
  char *nullPvs[],
  int numVisPvs,
  char *visPvs[],
  int numAlarmPvs,
  char *alarmPvs[] );

};

#ifdef __cplusplus
extern "C" {
#endif

void *create_activeRadioButtonClassPtr ( void );
void *clone_activeRadioButtonClassPtr ( void * );

#ifdef __cplusplus
}
#endif

#endif
