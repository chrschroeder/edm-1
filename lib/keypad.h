#ifndef __keypad_h
#define __keypad_h 1

#include <stdlib.h>
#include <string.h>

#include <X11/Xlib.h>
#include <Xm/Xm.h>
#include <Xm/MainW.h>
#include <Xm/BulletinB.h>
#include <Xm/DrawingA.h>
#include <Xm/PushBG.h>
#include <Xm/PushB.h>
#include <Xm/ToggleB.h>
#include <Xm/ArrowBG.h>
#include <Xm/Label.h>
#include <Xm/Form.h>
#include <Xm/Frame.h>
#include <Xm/RowColumn.h>
#include <Xm/DialogS.h>
#include <Xm/ScrolledW.h>
#include <Xm/PanedW.h>
#include <Xm/TextF.h>
#include <Xm/Text.h>

typedef struct keypadWidgetListTag {
  struct widgetListTag *flink;
  Widget pb;
  char *ascii;
} keypadWidgetListType, *keypadWidgetListPtr;

#ifdef __keypad_cc

static void keypadPress (
  Widget w,
  XtPointer client,
  XtPointer call,
  int dataType );

static void doubleKeypadPress (
  Widget w,
  XtPointer client,
  XtPointer call );

static void intKeypadPress (
  Widget w,
  XtPointer client,
  XtPointer call );

#endif

class keypadClass {

private:

friend void keypadPress (
  Widget w,
  XtPointer client,
  XtPointer call,
  int dataType );

friend void doubleKeypadPress (
  Widget w,
  XtPointer client,
  XtPointer call );

friend void intKeypadPress (
  Widget w,
  XtPointer client,
  XtPointer call );

static const int MAXCHARS = 14;
static const int ZERO = 0;
static const int NODECPOINT = 1;
static const int DECPOINT = 2;
static const int INT = 100;
static const int DOUBLE = 101;

int x, y, count, positive, state, poppedUp;
char *entryTag, *actionTag;
Display *display;
Widget shell, rowcol, kprowcol, topForm, mainForm, bottomForm, text,
 pb0, pb1, pb2, pb3, pb4, pb5, pb6, pb7, pb8, pb9,
 pbPoint, pbSign, pbOK, pbApply, pbCancel, pbBksp;
keypadWidgetListPtr wlHead, wlTail;
char buf[MAXCHARS+1];

int *intDest;
double *doubleDest;

void *userPtr;
void (*okFunc)(Widget,XtPointer,XtPointer);
void (*cancelFunc)(Widget,XtPointer,XtPointer);

public:

keypadClass::keypadClass ();

keypadClass::~keypadClass ( void );

void keypadClass::popup ( void );

void keypadClass::popdown ( void );

int keypadClass::isPoppedUp ( void );

int keypadClass::create (
  Widget top,
  //Colormap cmap,
  int _x,
  int _y,
  char *label,
  //fontInfoClass *fi,
  //const char *entryFontTag,
  //const char *actionFontTag,
  int dataType,
  void *destination,
  void *_userPtr,
  XtCallbackProc _okFunc,
  XtCallbackProc _cancelFunc );

int keypadClass::create (
  Widget top,
  //Colormap cmap,
  int _x,
  int _y,
  char *label,
  //fontInfoClass *fi,
  //const char *entryFontTag,
  //const char *actionFontTag,
  int *destination,
  void *_userPtr,
  XtCallbackProc _okFunc,
  XtCallbackProc _cancelFunc );

int keypadClass::create (
  Widget top,
  //Colormap cmap,
  int _x,
  int _y,
  char *label,
  //fontInfoClass *fi,
  //const char *entryFontTag,
  //const char *actionFontTag,
  double *destination,
  void *_userPtr,
  XtCallbackProc _okFunc,
  XtCallbackProc _cancelFunc );

};

#endif




























