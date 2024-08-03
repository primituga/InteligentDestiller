#include "OS.h"

bool ALARM_STATE;

/************************************************************************/
/* INIT INPUT PINS BLOCK                                                */
/************************************************************************/
void initPinsInputs()
{
    const uint8_t inputPins[] = {PIN_SW_MAN, PIN_SMIN, PIN_SMAX, PIN_SW_AUTO, PIN_SALARM};
    for (uint8_t pin : inputPins) {
        pinMode(pin, INPUT);
    }
}

/************************************************************************/
/* INIT OUTPUT PINS BLOCK                                               */
/************************************************************************/
void initPinsOutputs()
{
    const uint8_t outputPins[] = {
        PIN_RAQ, PIN_VALV_WATER_IN, PIN_VALV_WATER_OUT, PIN_BMB,
        PIN_IND_MIN, PIN_IND_MAX, PIN_IND_ALARM, PIN_IND_MAN, PIN_IND_AUTO
    };
    for (uint8_t pin : outputPins) {
        pinMode(pin, OUTPUT);
    }
}

/************************************************************************/
/* GETS BLOCK                                                           */
/************************************************************************/
#define DEFINE_GETTER(name, pin, activeState) \
bool name() { return digitalRead(pin) == activeState ? ON : OFF; }

DEFINE_GETTER(getWaterMax, PIN_SMAX, OFF)
DEFINE_GETTER(getWaterMin, PIN_SMIN, ON)
DEFINE_GETTER(getWaterAlarm, PIN_SALARM, ON)
DEFINE_GETTER(getAutoMode, PIN_IND_AUTO, ON)
DEFINE_GETTER(getAutoModeSW, PIN_SW_AUTO, ON)
DEFINE_GETTER(getManualMode, PIN_SW_MAN, ON)
DEFINE_GETTER(getResistor, PIN_RAQ, ON)
DEFINE_GETTER(getValv_Water_In, PIN_VALV_WATER_IN, ON)
DEFINE_GETTER(getValv_Water_Out, PIN_VALV_WATER_OUT, ON)
DEFINE_GETTER(getPump, PIN_BMB, ON)
DEFINE_GETTER(getAlarm, PIN_SALARM, ON)

/************************************************************************/
/* SETS BLOCK                                                           */
/************************************************************************/

void setPinState(uint8_t pin, bool state, bool& oldState, const char* debugMsg)
{
    if (state != oldState) {
        digitalWrite(pin, state);
        if (DEBUG) {
            sPrintLnStr(debugMsg);
        }
        oldState = state;
    }
}

void setIndMax(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_IND_MAX, state, OLDSTATE, state ? "setIndMax ON" : "setIndMax OFF");
}

void setIndMin(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_IND_MIN, state, OLDSTATE, state ? "setIndMin ON" : "setIndMin OFF");
}

void setIndAlarm(bool state)
{
    static bool OLDSTATE;
    static unsigned long previousTimer = 0;

    if (state) {
        ALARM_STATE = ON;
        unsigned long currentTimer = millis();
        if (currentTimer - previousTimer > (digitalRead(PIN_IND_ALARM) ? ALARM_TIME_ON : ALARM_TIME_OFF)) {
            digitalWrite(PIN_IND_ALARM, !digitalRead(PIN_IND_ALARM));
            previousTimer = currentTimer;
        }
    } else if (OLDSTATE) {
        ALARM_STATE = OFF;
        digitalWrite(PIN_IND_ALARM, OFF);
    }

    if (state != OLDSTATE) {
        if (DEBUG) {
            sPrintLnStr(state ? "setIndAlarm ON" : "setIndAlarm OFF");
        }
        OLDSTATE = state;
    }
}

void setIndMan(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_IND_MAN, state, OLDSTATE, state ? "setIndMan ON" : "setIndMan OFF");
}

void setAutoMode(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_IND_AUTO, state, OLDSTATE, state ? "setAutoMode ON" : "setAutoMode OFF");
}

void setPump(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_BMB, state, OLDSTATE, state ? "setPump ON" : "setPump OFF");
}

void setValveWaterIn(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_VALV_WATER_IN, state, OLDSTATE, state ? "setValveWaterIn ON" : "setValveWaterIn OFF");
}

void setValveWaterOut(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_VALV_WATER_OUT, state, OLDSTATE, state ? "setValveWaterOut ON" : "setValveWaterOut OFF");
}

void setResistor(bool state) {
    static bool OLDSTATE;
    setPinState(PIN_RAQ, state, OLDSTATE, state ? "setResistor ON" : "setResistor OFF");
}
