/*
    The code in this file uses open source libraries provided by thecoderscorner

    DO NOT EDIT THIS FILE, IT WILL BE GENERATED EVERY TIME YOU USE THE UI DESIGNER
    INSTEAD EITHER PUT CODE IN YOUR SKETCH OR CREATE ANOTHER SOURCE FILE.

    All the variables you may need access to are marked extern in this file for easy
    use elsewhere.
*/

#include <Arduino.h>
#include <tcMenu.h>
#include "tsh-watch_menu.h"
#include "utils.h"

// Global variable declarations

const PROGMEM ConnectorLocalInfo applicationInfo = { "tsh watch", "dbc86145-ea32-4366-bc86-5b0108ebab98" };

U8g2GfxMenuConfig   gfxConfig;
U8g2MenuRenderer    renderer;

// Global Menu Item declarations


const BooleanMenuInfo PROGMEM minfoPulseMeter = { "PulseMeter", 13, 0xFFFF, 1, NO_CALLBACK, NAMING_ON_OFF };
BooleanMenuItem               menuPulseMeter(&minfoPulseMeter, false, NULL);

const BooleanMenuInfo PROGMEM minfoPedoMeter = { "PedoMeter", 12, 0xFFFF, 1, onPedoMeterCh, NAMING_ON_OFF };
BooleanMenuItem               menuPedoMeter(&minfoPedoMeter, false, &menuPulseMeter);

const BooleanMenuInfo PROGMEM minfoTemperature = { "Temperature", 11, 0xFFFF, 1, onTemperatureCh, NAMING_ON_OFF };
BooleanMenuItem               menuTemperature(&minfoTemperature, false, &menuPedoMeter);

const SubMenuInfo     PROGMEM minfoSensors = { "Sensors", 10, 0xFFFF, 0, NO_CALLBACK };
RENDERING_CALLBACK_NAME_INVOKE(fnSensorsRtCall, backSubItemRenderFn, "Sensors", -1, NO_CALLBACK)
BackMenuItem                  menuBackSensors(fnSensorsRtCall, &menuTemperature);
SubMenuItem                   menuSensors(&minfoSensors, &menuBackSensors, NULL);

const char enumStrTimeZone_0[] PROGMEM  = "+9";
const char enumStrTimeZone_1[] PROGMEM  = "+8";
const char enumStrTimeZone_2[] PROGMEM  = "+7";
const char enumStrTimeZone_3[] PROGMEM  = "+6";
const char enumStrTimeZone_4[] PROGMEM  = "+5";
const char enumStrTimeZone_5[] PROGMEM  = "+4";
const char enumStrTimeZone_6[] PROGMEM  = "+3";
const char enumStrTimeZone_7[] PROGMEM  = "+2";
const char enumStrTimeZone_8[] PROGMEM  = "+1";
const char enumStrTimeZone_9[] PROGMEM  = "0";
const char enumStrTimeZone_10[] PROGMEM  = "-1";
const char enumStrTimeZone_11[] PROGMEM  = "-2";
const char enumStrTimeZone_12[] PROGMEM  = "-3";
const char enumStrTimeZone_13[] PROGMEM  = "-4";
const char enumStrTimeZone_14[] PROGMEM  = "-5";
const char enumStrTimeZone_15[] PROGMEM  = "-6";

const char* const enumStrTimeZone[] PROGMEM  = { enumStrTimeZone_0, enumStrTimeZone_1, enumStrTimeZone_2, enumStrTimeZone_3, enumStrTimeZone_4,
                                                 enumStrTimeZone_5, enumStrTimeZone_6, enumStrTimeZone_7, enumStrTimeZone_8, enumStrTimeZone_9, 
                                                 enumStrTimeZone_10, enumStrTimeZone_11, enumStrTimeZone_12, enumStrTimeZone_13, enumStrTimeZone_14, 
                                                 enumStrTimeZone_15 };
                                                 
int8_t const enumIntTimeZone[] PROGMEM  = { 9, 8, 7, 6, 5, 4, 3, 2, 1, 0, -1, -2, -3, -4, -5, -6 }; // should be synced with enumStrTimeZone_* and enumStrTimeZone


const EnumMenuInfo PROGMEM    minfoTimeZone = { "Time Zone", 9, 0xFFFF, 15, onTimezoneCh, enumStrTimeZone };
EnumMenuItem                  menuTimeZone(&minfoTimeZone, 0, NULL);

RENDERING_CALLBACK_NAME_INVOKE(fnTimeRtCall, timeItemRenderFn, "Time", -1, onTimeCh)

TimeFormattedMenuItem         menuTime(fnTimeRtCall, 8, (MultiEditWireType)EDITMODE_TIME_24H, &menuTimeZone);
RENDERING_CALLBACK_NAME_INVOKE(fnDateRtCall, dateItemRenderFn, "Date", -1, onDateCh)

DateFormattedMenuItem         menuDate(fnDateRtCall, 7, &menuTime);

//const BooleanMenuInfo PROGMEM minfoAutoUpdate = { "Update via Internet", 5, 0xFFFF, 1, onAutoUpdateCh, NAMING_ON_OFF };
//BooleanMenuItem               menuAutoUpdate(&minfoAutoUpdate, false, &menuDate);
const AnyMenuInfo PROGMEM     minfoAutoUpdate = { "Update via Internet", 6, 0xFFFF, 0, onAutoUpdateCh };
ActionMenuItem                menuAutoUpdate(&minfoAutoUpdate,  &menuDate);

const SubMenuInfo PROGMEM     minfoDateTime = { "Date/Time", 5, 0xFFFF, 0, NO_CALLBACK };
RENDERING_CALLBACK_NAME_INVOKE(fnDateTimeRtCall, backSubItemRenderFn, "Date/Time", -1, NO_CALLBACK)
BackMenuItem                  menuBackDateTime(fnDateTimeRtCall, &menuAutoUpdate);
SubMenuItem                   menuDateTime(&minfoDateTime, &menuBackDateTime, &menuSensors);

//onSetupWiFi

//const BooleanMenuInfo PROGMEM minfoSetupWiFi = { "Setup WiFi", 2, 0xFFFF, 1, onSetupWiFi, NAMING_ON_OFF };
//BooleanMenuItem               menuSetupWiFi(&minfoSetupWiFi, false, &menuDateTime);

const AnyMenuInfo PROGMEM     minfoSetupWiFi = { "Setup WiFi", 4, 0xFFFF, 0, onSetupWiFi };
ActionMenuItem                menuSetupWiFi(&minfoSetupWiFi,  &menuDateTime);


const SubMenuInfo PROGMEM     minfoSettings = { "Settings", 3, 0xFFFF, 0, NO_CALLBACK };

RENDERING_CALLBACK_NAME_INVOKE(fnSettingsRtCall, backSubItemRenderFn, "Settings", -1, NO_CALLBACK)
BackMenuItem                  menuBackSettings(fnSettingsRtCall, &menuSetupWiFi);
SubMenuItem                   menuSettings(&minfoSettings, &menuBackSettings, NULL);

//menuSyncStatViaWiFi
const AnyMenuInfo PROGMEM minfoSyncStatViaWiFi = { "Sync action data", 14, 0xFFFF, 0, onSyncStatViaWiFi };
ActionMenuItem menuSyncStatViaWiFi(&minfoSyncStatViaWiFi, &menuSettings);

/*
const AnyMenuInfo PROGMEM     minfoGraphTemp = { "Graph Temp.", 2, 0xFFFF, 0, onGraphTempPressed };
ActionMenuItem                menuGraphTemp(&minfoGraphTemp, &menuSettings);

const AnyMenuInfo PROGMEM     minfoGraphSteps = { "Graph Steps", 1, 0xFFFF, 0, onGraphStepsPressed };
ActionMenuItem                menuGraphSteps(&minfoGraphSteps, &menuGraphTemp);
*/
const AnyMenuInfo PROGMEM minfoGraphTemp = { "Graph Temp.", 2, 0xFFFF, 0, onGraphTempPressed };
ActionMenuItem menuGraphTemp(&minfoGraphTemp,  &menuSyncStatViaWiFi);

const AnyMenuInfo PROGMEM minfoGraphSteps = { "Graph Steps", 1, 0xFFFF, 0, onGraphStepsPressed };
ActionMenuItem menuGraphSteps(&minfoGraphSteps, &menuGraphTemp);

const AnyMenuInfo     PROGMEM minfoClose = { "Close", 14, 0xFFFF, 0, onBack };
ActionMenuItem                menuClose(&minfoClose, &menuGraphSteps);


void myDisplayFunction(unsigned int encoderValue, RenderPressMode clicked) {

}

// Set up code
void setupMenu( U8G2 *_gfx ) {
    menuPulseMeter.setReadOnly(true);
    
    prepareBasicU8x8Config(gfxConfig);
    renderer.setGraphicsDevice(_gfx, &gfxConfig);
    /*
    renderer.setResetCallback([] {
        startedCustomRender = false;
        renderer.takeOverDisplay(myDisplayFunction);
    });
*/
    
    switches.initialise(internalDigitalIo(), true);
    menuMgr.initForUpDownOk(&renderer, &menuClose, 33, 14, 27);
}


void showDialog(const char * Header, char *line2, CompletedHandlerFn completedHandler) {
    BaseDialog* dlg = renderer.getDialog();
    if (!dlg) 
        return;

    // first we set the buttons how we want them. BTNTYPE_NONE means no button.
    dlg->setButtons(BTNTYPE_NONE, BTNTYPE_CLOSE); 

    // then we show the dialog - 2nd boolean parameter is if dialog is local only
    dlg->show(Header, false, completedHandler);
    // and then we set the second line (buffer) - must be after show.
    dlg->copyIntoBuffer(line2);
//    dlg->setUserData((void*)"Something else");
}

void hideDialog() {
    BaseDialog* dlg = renderer.getDialog();
    if (!dlg) 
        return;
    dlg->hide();
}

void showWindow(RendererCallbackFn displayFn){
    renderer.takeOverDisplay(displayFn);
}
void returnToMenu() {
    renderer.giveBackDisplay();
}
