#include "OS.h"

bool ALARM_STATE;

/************************************************************************/
/* INIT INPUT PINS BLOCK                                                */
/************************************************************************/
void initPinsInputs()
{
    pinMode(PIN_SMAX, INPUT);
    pinMode(PIN_SMIN, INPUT);
    pinMode(PIN_SW_AUTO, INPUT); // push sw
    pinMode(PIN_SW_MAN, INPUT);  // on/off sw
}

/************************************************************************/
/* INIT OUTUP PINS BLOCK                                                */
/************************************************************************/
void initPinsOutputs()
{
    pinMode(PIN_RAQ, OUTPUT);
    pinMode(PIN_VALV_WATER_IN, OUTPUT);
    pinMode(PIN_VALV_WATER_OUT, OUTPUT);
    pinMode(PIN_BMB, OUTPUT);
    pinMode(PIN_IND_MIN, OUTPUT);
    pinMode(PIN_IND_MAX, OUTPUT);
    pinMode(PIN_IND_ALARM, OUTPUT);
    pinMode(PIN_IND_MAN, OUTPUT);
    pinMode(PIN_IND_AUTO, OUTPUT);
}

/************************************************************************/
/* GETS BLOCK                                                           */
/************************************************************************/

bool getWaterMax()
{
    if (digitalRead(PIN_SMAX) == OFF)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getWaterMin()
{
    if (digitalRead(PIN_SMIN) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getWaterAlarm()
{
    if (digitalRead(PIN_SALARM) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getAutoMode()
{
    if (digitalRead(PIN_IND_AUTO) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getAutoModeSW()
{
    if (digitalRead(PIN_SW_AUTO) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getManualMode()
{
    if (digitalRead(PIN_SW_MAN) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getResistor()
{
    if (digitalRead(PIN_RAQ) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getValv_Water_In()
{
    if (digitalRead(PIN_VALV_WATER_IN) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getValv_Water_Out()
{
    if (digitalRead(PIN_VALV_WATER_OUT) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getPump()
{
    if (digitalRead(PIN_BMB) == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

bool getAlarm()
{
    if (ALARM_STATE == ON)
    {
        return ON;
    }
    else
    {
        return OFF;
    }
}

/************************************************************************/
/* SETS BLOCK                                                           */
/************************************************************************/

void setIndMax(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_IND_MAX, ON);
        if (DEBUG)
            sPrintLnStr("setIndMax ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_IND_MAX, OFF);
        if (DEBUG)
            sPrintLnStr("setIndMax OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setIndMin(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_IND_MIN, ON);
        if (DEBUG)
            sPrintLnStr("setIndMin ON");
        sPrintLnNbr(getWaterMin());
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_IND_MIN, OFF);
        if (DEBUG)
            sPrintLnStr("setIndMin OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setIndAlarm(bool state)
{
    static bool OLDSTATE;
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (state == ON && OLDSTATE == OFF)
    {
        ALARM_STATE = ON;
        if (DEBUG)
            sPrintLnStr("setIndAlarm ON");
        if (millis() - previousTimer > ALARM_TIME_ON)
        {
            digitalWrite(PIN_IND_ALARM, OFF);
            previousTimer = millis();
        }
        else if (millis() - previousTimer > ALARM_TIME_OFF)
        {
            digitalWrite(PIN_IND_ALARM, ON);
        }
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        ALARM_STATE = OFF;
        digitalWrite(PIN_IND_ALARM, OFF);
        if (DEBUG)
            sPrintLnStr("setIndAlarm OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setIndMan(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_IND_MAN, ON);
        if (DEBUG)
            sPrintLnStr("setIndMan ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_IND_MAN, OFF);
        if (DEBUG)
            sPrintLnStr("setIndMan OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setAutoMode(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_IND_AUTO, ON);
        if (DEBUG)
            sPrintLnStr("setAutoMode ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_IND_AUTO, OFF);
        if (DEBUG)
            sPrintLnStr("setAutoMode OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setPump(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_BMB, ON);
        if (DEBUG)
            sPrintLnStr("setPump ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_BMB, OFF);
        if (DEBUG)
            sPrintLnStr("setPump OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setValveWaterIn(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_VALV_WATER_IN, ON);
        if (DEBUG)
            sPrintLnStr("setValveWaterIn ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_VALV_WATER_IN, OFF);
        if (DEBUG)
            sPrintLnStr("setValveWaterIn OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setValveWaterOut(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_VALV_WATER_OUT, ON);
        if (DEBUG)
            sPrintLnStr("setValveWaterOut ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_VALV_WATER_OUT, OFF);
        if (DEBUG)
            sPrintLnStr("setValveWaterOut OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}

void setResistor(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        digitalWrite(PIN_RAQ, ON);
        if (DEBUG)
            sPrintLnStr("setResistor ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        digitalWrite(PIN_RAQ, OFF);
        if (DEBUG)
            sPrintLnStr("setResistor OFF");
        OLDSTATE = state;
    }
    else
    {
        OLDSTATE = state;
    }
}