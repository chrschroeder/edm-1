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

#ifndef __message_button_h
#define __message_button_h 1

#include "act_grf.h"
#include "entry_form.h"

#include "cadef.h"

#define MSGBTC_MAJOR_VERSION 2
#define MSGBTC_MINOR_VERSION 5
#define MSGBTC_RELEASE 0

#define MSGBTC_K_PUSH 1
#define MSGBTC_K_TOGGLE 2

#ifdef __message_button_cc

#include "message_button.str"

static char *dragName[] = {
  activeMessageButtonClass_str18,
  activeMessageButtonClass_str32,
  activeMessageButtonClass_str28
};

static void doBlink (
  void *ptr
);

static void pw_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

static void pw_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

static void pw_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

static void unconnectedTimeout (
  XtPointer client,
  XtIntervalId *id );

static void msgbtc_edit_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

static void msgbtc_edit_update (
  Widget w,
  XtPointer client,
  XtPointer call );

static void msgbtc_edit_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

static void msgbtc_edit_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

static void msgbtc_edit_cancel_delete (
  Widget w,
  XtPointer client,
  XtPointer call );

#if 0
static void msgbt_sourcePressUpdate (
  struct event_handler_args ast_args );

static void msgbt_monitor_sourcePress_connect_state (
  struct connection_handler_args arg );

static void msgbt_sourceReleaseUpdate (
  struct event_handler_args ast_args );

static void msgbt_monitor_sourceRelease_connect_state (
  struct connection_handler_args arg );
#endif

static void msgbt_monitor_dest_connect_state (
  struct connection_handler_args arg );

static void msgbt_monitor_vis_connect_state (
  struct connection_handler_args arg );

static void msgbt_destInfoUpdate (
  struct event_handler_args ast_args );

static void msgbt_visInfoUpdate (
  struct event_handler_args ast_args );

static void msgbt_visUpdate (
  struct event_handler_args ast_args );

static void msgbt_monitor_color_connect_state (
  struct connection_handler_args arg );

static void msgbt_colorInfoUpdate (
  struct event_handler_args ast_args );

static void msgbt_colorUpdate (
  struct event_handler_args ast_args );

#endif

class activeMessageButtonClass : public activeGraphicClass {

private:

friend void doBlink (
  void *ptr
);

friend void pw_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void pw_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void pw_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void unconnectedTimeout (
  XtPointer client,
  XtIntervalId *id );

friend void msgbtc_edit_ok (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void msgbtc_edit_update (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void msgbtc_edit_apply (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void msgbtc_edit_cancel (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void msgbtc_edit_cancel_delete (
  Widget w,
  XtPointer client,
  XtPointer call );

#if 0
friend void msgbt_sourcePressUpdate (
  struct event_handler_args ast_args );

friend void msgbt_monitor_sourcePress_connect_state (
  struct connection_handler_args arg );

friend void msgbt_sourceReleaseUpdate (
  struct event_handler_args ast_args );

friend void msgbt_monitor_sourceRelease_connect_state (
  struct connection_handler_args arg );
#endif

friend void msgbt_monitor_dest_connect_state (
  struct connection_handler_args arg );

friend void msgbt_monitor_vis_connect_state (
  struct connection_handler_args arg );

friend void msgbt_destInfoUpdate (
  struct event_handler_args ast_args );

friend void msgbt_visInfoUpdate (
  struct event_handler_args ast_args );

friend void msgbt_visUpdate (
  struct event_handler_args ast_args );

friend void msgbt_monitor_color_connect_state (
  struct connection_handler_args arg );

friend void msgbt_colorInfoUpdate (
  struct event_handler_args ast_args );

friend void msgbt_colorUpdate (
  struct event_handler_args ast_args );

int opComplete;

int minW;
int minH;

int bufX, bufY, bufW, bufH;

int sourcePressType, sourceReleaseType, destType;

int bufFgColor, bufOnColor, bufOffColor;
pvColorClass fgColor, onColor, offColor;
int topShadowColor, bufTopShadowColor;
int botShadowColor, bufBotShadowColor;
colorButtonClass fgCb, onCb, offCb, topShadowCb, botShadowCb;
expStringClass onLabel, offLabel;
char bufOnLabel[MAX_ENUM_STRING_SIZE+1];
char bufOffLabel[MAX_ENUM_STRING_SIZE+1];
// char onLabel[MAX_ENUM_STRING_SIZE+1], bufOnLabel[MAX_ENUM_STRING_SIZE+1];
// char offLabel[MAX_ENUM_STRING_SIZE+1], bufOffLabel[MAX_ENUM_STRING_SIZE+1];
int buttonType, bufButtonType, _3D, buf3D, invisible, bufInvisible,
 toggle, bufToggle, pressAction, bufPressAction,
 releaseAction, bufReleaseAction;

fontMenuClass fm;
char fontTag[63+1], bufFontTag[63+1];
XFontStruct *fs;
int fontAscent, fontDescent, fontHeight;

chid sourcePressPvId, sourceReleasePvId, destPvId;
evid sourcePressEventId, sourceReleaseEventId;

int destIsAckS;

expStringClass destPvExpString;
char bufDestPvName[activeGraphicClass::MAX_PV_NAME+1];
expStringClass sourcePressPvExpString;
char bufSourcePressPvName[39+1];
expStringClass sourceReleasePvExpString;
char bufSourceReleasePvName[39+1];

//-------------------------------------------------------
static const int destPvConnection = 1;
static const int visPvConnection = 2;
static const int colorPvConnection = 3;
pvConnectionClass connection;
//-------------------------------------------------------

//-------------------------------------------------------
chid visPvId;
evid visEventId;
expStringClass visPvExpString;
char bufVisPvName[activeGraphicClass::MAX_PV_NAME+1];
int visExists;
double visValue, curVisValue, minVis, maxVis;
char minVisString[39+1], bufMinVisString[39+1];
char maxVisString[39+1], bufMaxVisString[39+1];
int prevVisibility, visibility, visInverted, bufVisInverted;
int needVisConnectInit, needVisInit, needVisUpdate;
//-------------------------------------------------------

//-------------------------------------------------------
chid colorPvId;
evid colorEventId;
expStringClass colorPvExpString;
char bufColorPvName[activeGraphicClass::MAX_PV_NAME+1];
int colorExists;
double colorValue, curColorValue;
int needColorConnectInit, needColorInit, needColorUpdate;
//-------------------------------------------------------

pvValType sourcePressV, sourceReleaseV, destV;

int destExists, sourcePressExists, sourceReleaseExists, buttonPressed;

int sourcePressPvConnected, sourceReleasePvConnected, destPvConnected,
 active, activeMode, init;

int needConnectInit, needErase, needDraw, needToEraseUnconnected,
 needToDrawUnconnected;
int unconnectedTimer;

char pw[31+1];
char bufPw1[31+1];
char bufPw2[31+1];
int usePassword;

int lock, bufLock;

int useEnumNumeric, bufUseEnumNumeric;

char *stateString[MAX_ENUM_STATES]; // allocated at run-time
int numStates;

int pwFormX, pwFormY, pwFormW, pwFormH, pwFormMaxH;

int needPerformDownAction, needPerformUpAction, needWarning;

public:

activeMessageButtonClass ( void );

activeMessageButtonClass
 ( const activeMessageButtonClass *source );

~activeMessageButtonClass ( void );

char *objName ( void ) {

  return name;

}

int createInteractive (
  activeWindowClass *aw_obj,
  int x,
  int y,
  int w,
  int h );

int save (
  FILE *f );

int createFromFile (
  FILE *fptr,
  char *name,
  activeWindowClass *actWin );

int importFromXchFile (
  FILE *f,
  char *name,
  activeWindowClass *_actWin );

int genericEdit ( void );

int edit ( void );

int editCreate ( void );

int draw ( void );

int erase ( void );

int drawActive ( void );

int eraseActive ( void );

int activate ( int pass, void *ptr );

int deactivate ( int pass );

void updateDimensions ( void );

void performBtnUpAction ( void );

void btnUp (
  int x,
  int y,
  int buttonState,
  int buttonNumber,
  int *action );

void performBtnDownAction ( void );

void btnDown (
  int x,
  int y,
  int buttonState,
  int buttonNumber,
  int *action );

void pointerIn (
  int _x,
  int _y,
  int buttonState );

int getButtonActionRequest (
  int *up,
  int *down,
  int *drag,
  int *focus );

int expand1st (
  int numMacros,
  char *macros[],
  char *expansions[] );

int expand2nd (
  int numMacros,
  char *macros[],
  char *expansions[] );

int containsMacros ( void );

void executeDeferred ( void );

char *firstDragName ( void );

char *nextDragName ( void );

char *dragValue (
  int i );

void changeDisplayParams (
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

void changePvNames (
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

int getEnumNumeric (
  char *string,
  short *value );

};

#ifdef __cplusplus
extern "C" {
#endif

void *create_activeMessageButtonClassPtr ( void );
void *clone_activeMessageButtonClassPtr ( void * );

#ifdef __cplusplus
}
#endif

#endif
