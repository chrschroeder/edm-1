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

#ifndef __group_h
#define __group_h 1

#include "act_grf.h"
#include "undo.h"
#include "entry_form.h"

#include "group.str"

// the following defines btnActionListType & btnActionListPtr
#include "btnActionListType.h"

#ifdef __epics__
#include "cadef.h"
#endif

class activeGroupClass : public activeGraphicClass {

private:

void * voidHead; // cast to activeGraphicListPtr at runtime
btnActionListPtr btnDownActionHead;
btnActionListPtr btnUpActionHead;
btnActionListPtr btnMotionActionHead;
btnActionListPtr btnFocusActionHead;
int depth;
undoClass undoObj;

public:

activeGroupClass ( void );

activeGroupClass
 ( const activeGroupClass *source );

~activeGroupClass ( void );

int createGroup (
  activeWindowClass *aw_obj );

int ungroup (
  void *curListNode );
 
int save (
  FILE *f );

int createFromFile (
  FILE *fptr,
  char *name,
  activeWindowClass *actWin );

int edit ( void );

void beginEdit ( void );

int checkEditStatus ( void );

int draw ( void );

int erase ( void );

int drawActive ( void );

int eraseActive ( void );

activeGraphicClass *enclosingObject (
  int x0,
  int y0 );

int doSmartDrawAllActive ( void );

int drawActiveIfIntersects (
  int x0,
  int y0,
  int x1,
  int y1 );

int smartDrawCount ( void );

void resetSmartDrawCount ( void );

int activate (
  int pass,
  void *ptr,
  int *numSubObjects );

int deactivate (
  int pass,
  int *numSubObjects );

int preReactivate (
  int pass,
  int *numSubObjects );

int moveSelectBox (
  int _x,
  int _y );

int moveSelectBoxAbs (
  int _x,
  int _y );

int moveSelectBoxMidpointAbs (
  int _x,
  int _y );

int checkResizeSelectBoxAbs (
  int _x,
  int _y,
  int _w,
  int _h );

int resizeSelectBoxAbs (
  int _x,
  int _y,
  int _w,
  int _h );

int resizeSelectBoxAbsFromUndo (
  int _x,
  int _y,
  int _w,
  int _h );

int checkResizeSelectBox (
  int _x,
  int _y,
  int _w,
  int _h );

int resizeSelectBox (
  int _x,
  int _y,
  int _w,
  int _h );

int move (
  int x,
  int y );

int moveAbs (
  int x,
  int y );

int moveMidpointAbs (
  int x,
  int y );

int rotate (
  int xOrigin,
  int yOrigin,
  char direction );

int flip (
  int xOrigin,
  int yOrigin,
  char direction );

int resize (
  int _x,
  int _y,
  int _w,
  int _h );

int resizeAbs (
  int _x,
  int _y,
  int _w,
  int _h );

int resizeAbsFromUndo (
  int _x,
  int _y,
  int _w,
  int _h );

int getButtonActionRequest (
  int *up,
  int *down,
  int *drag );

int getButtonActionRequest (
  int *up,
  int *down,
  int *drag,
  int *focus );

void btnDown (
  int x,
  int y,
  int buttonState,
  int buttonNumber,
  int *action );

void btnUp (
  int x,
  int y,
  int buttonState,
  int buttonNumber,
  int *action );

void btnDrag (
  int x,
  int y,
  int buttonState,
  int buttonNumber );

void pointerIn (
  int x,
  int y,
  int buttonState );

void pointerOut (
  int x,
  int y,
  int buttonState );

void checkMouseOver (
  int x,
  int y,
  int buttonState );

activeGraphicClass *getTail ( void );

void updateGroup ( void );

int initDefExeNode (
  void *ptr );

int containsMacros ( void );

int expand1st (
  int numMacros,
  char *macros[],
  char *expansions[] );

int expand2nd (
  int numMacros,
  char *macros[],
  char *expansions[] );

void bufInvalidate ( void );

void setNextSelectedToEdit (
  activeGraphicClass *ptr );

void clearNextSelectedToEdit ( void );

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

void flushUndo ( void );

int addUndoCreateNode ( undoClass *_undoObj );

int addUndoMoveNode ( undoClass *_undoObj );

int addUndoResizeNode ( undoClass *_undoObj );

int addUndoCopyNode ( undoClass *_undoObj );

int addUndoCutNode ( undoClass *_undoObj );

int addUndoPasteNode ( undoClass *_undoObj );

int addUndoReorderNode ( undoClass *_undoObj );

int addUndoEditNode ( undoClass *_undoObj );

int addUndoGroupNode ( undoClass *_undoObj );

int addUndoRotateNode ( undoClass *_undoObj );

int addUndoFlipNode ( undoClass *_undoObj );

int undoCreate (
  undoOpClass *opPtr );

int undoMove (
  undoOpClass *opPtr,
  int x,
  int y );

int undoResize (
  undoOpClass *opPtr,
  int x,
  int y,
  int w,
  int h );

int undoCopy (
  undoOpClass *opPtr );

int undoCut (
  undoOpClass *opPtr );

int undoPaste (
  undoOpClass *opPtr );

int undoReorder (
  undoOpClass *opPtr );

int undoEdit (
  undoOpClass *opPtr );

int undoGroup (
  undoOpClass *opPtr );

int undoRotate (
  undoOpClass *opPtr,
  int x,
  int y,
  int w,
  int h );

int undoFlip (
  undoOpClass *opPtr,
  int x,
  int y,
  int w,
  int h );

int startDrag (
  XButtonEvent *be,
  int x,
  int y
);

int selectDragValue (
  int x,
  int y
);

char *firstDragName (
  int x,
  int y
);

char *nextDragName (
  int x,
  int y
);

char *dragValue (
  int x,
  int y,
  int i
);

int atLeastOneDragPv (
  int x,
  int y
);

};

#endif
