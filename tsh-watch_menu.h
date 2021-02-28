/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
*/

#ifndef MENU_GENERATED_CODE_H
#define MENU_GENERATED_CODE_H

#include <Arduino.h>
#include <tcMenu.h>
#include <RuntimeMenuItem.h>
#include "tcMenuU8g2.h"

extern int8_t const enumIntTimeZone[];


void showWindow(RendererCallbackFn displayFn);
void returnToMenu() ;
void showDialog(const char * Header, char *line2,  CompletedHandlerFn completedHandler);
void hideDialog();
void setupMenu(U8G2 *_gfx);  // forward reference of the menu setup function.
extern const PROGMEM ConnectorLocalInfo applicationInfo;  // defines the app info to the linker.

// Global variables that need exporting

extern U8G2_SH1106_128X64_NONAME_F_HW_I2C *gfx;
extern U8g2GfxMenuConfig gfxConfig;
extern U8g2MenuRenderer renderer;

// Callback functions must always include CALLBACK_FUNCTION after the return type
#define CALLBACK_FUNCTION

// Global Menu Item exports

extern ActionMenuItem menuClose;
extern BooleanMenuItem menuPulseMeter;
extern BooleanMenuItem menuPedoMeter;
extern BooleanMenuItem menuTemperature;
extern SubMenuItem menuSensors;
extern EnumMenuItem menuTimeZone;
extern TimeFormattedMenuItem menuTime;
extern DateFormattedMenuItem menuDate;
//extern BooleanMenuItem menuAutoUpdate;
extern ActionMenuItem  menuAutoUpdate;

extern SubMenuItem menuDateTime;
extern ActionMenuItem menuSetupWiFi;
extern SubMenuItem menuSettings;
extern ActionMenuItem menuGraphTemp;
extern ActionMenuItem menuGraphSteps;
extern ActionMenuItem menuSyncStatViaWiFi;

void CALLBACK_FUNCTION onBack(int id);
void CALLBACK_FUNCTION onAutoUpdateCh(int id);
void CALLBACK_FUNCTION onDateCh(int id);
void CALLBACK_FUNCTION onTimeCh(int id);
void CALLBACK_FUNCTION onTimezoneCh(int id) ;
void CALLBACK_FUNCTION onTemperatureCh(int id);
void CALLBACK_FUNCTION onPedoMeterCh(int id);
void CALLBACK_FUNCTION onGraphTempPressed(int id);
void CALLBACK_FUNCTION onGraphStepsPressed(int id);
void CALLBACK_FUNCTION onSetupWiFi(int id);
void CALLBACK_FUNCTION onSyncStatViaWiFi(int id);


#endif // MENU_GENERATED_CODE_H
