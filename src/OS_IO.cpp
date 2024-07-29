#include "OS.h"

uint8_t inputVarsImage[5];
const uint8_t inputVarsPINs[] = {PIN_SW_MAN, PIN_SMIN, PIN_SMAX, PIN_SW_AUTO, PIN_SALARM};

uint8_t outputVarsImage[9];
const uint8_t outputVarsPINs[] = {PIN_RAQ, PIN_BMB, PIN_VALV_WATER_OUT, PIN_VALV_WATER_IN, PIN_IND_ALARM, PIN_IND_MIN, PIN_IND_MAX, PIN_IND_AUTO, PIN_IND_MAN};

void writeOutputs()
{
    for (uint8_t i = 0; i < PIN_OUTPUT_COUNT; i++)
    {
        digitalWrite(outputVarsPINs[i], outputVarsImage[i]);
    }
}

void readInputs()
{
    for (uint8_t i = 0; i < PIN_INPUT_COUNT; i++)
    {
        inputVarsImage[i] = digitalRead(inputVarsPINs[i]);
        // Serial.println(inputVarsImage[i]);
    }

    // Serial.println(" ");
}

/************************************************************************/
/* INIT INPUT PINS BLOCK                                                */
/************************************************************************/
void initPinsInputs()
{
    pinMode(PIN_SW_MAN, INPUT); // on/off sw
    pinMode(PIN_SMIN, INPUT);
    pinMode(PIN_SMAX, INPUT);
    pinMode(PIN_SW_AUTO, INPUT); // push sw
    pinMode(PIN_SALARM, INPUT);
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
    return !inputVarsImage[POS_SMAX];
}

bool getWaterMin()
{
    return inputVarsImage[POS_SMIN];
}

bool getAlarm()
{
    return inputVarsImage[POS_SALARM];
}

bool getAutoModeSW()
{
    return inputVarsImage[POS_SW_AUTO];
}

bool getManualMode()
{
    return inputVarsImage[POS_SW_MAN];
}

bool getAutoMode()
{
    return outputVarsImage[POS_IND_AUTO];
}

bool getResistor()
{
    return outputVarsImage[POS_RAQ];
}

bool getValv_Water_In()
{
    return outputVarsImage[POS_VALV_WATER_IN];
}

bool getValv_Water_Out()
{
    return outputVarsImage[POS_VALV_WATER_OUT];
}

bool getPump()
{
    return outputVarsImage[POS_BMB];
}

/************************************************************************/
/* SETS BLOCK                                                           */
/************************************************************************/

void setIndMax(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_IND_MAX, ON);
        outputVarsImage[POS_IND_MAX] = ON;
        if (DEBUG)
            sPrintLnStr("setIndMax ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_IND_MAX, OFF);
        outputVarsImage[POS_IND_MAX] = OFF;
        if (DEBUG)
            sPrintLnStr("setIndMax OFF");
        OLDSTATE = state;
    }
}

void setIndMin(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_IND_MIN, ON);
        outputVarsImage[POS_IND_MIN] = ON;
        if (DEBUG)
        {
            sPrintLnStr("setIndMin ON");
        }
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_IND_MIN, OFF);
        outputVarsImage[POS_IND_MIN] = OFF;
        if (DEBUG)
        {
            sPrintLnStr("setIndMin OFF");
        }
        OLDSTATE = state;
    }
}

void setIndAlarm(bool state)
{
    static bool OLDSTATE;
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (state == ON)
    {
        if (millis() - previousTimer > ALARM_TIME_ON)
        {
            // digitalWrite(PIN_IND_ALARM, OFF);
            outputVarsImage[POS_IND_ALARM] = OFF;
            previousTimer = millis();
        }
        else if (millis() - previousTimer > ALARM_TIME_OFF)
        {
            // digitalWrite(PIN_IND_ALARM, ON);
            outputVarsImage[POS_IND_ALARM] = ON;
        }
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_IND_ALARM, OFF);
        outputVarsImage[POS_IND_ALARM] = OFF;
    }

    //  Condition to debug
    if (state == ON && OLDSTATE == OFF)
    {
        if (DEBUG)
            sPrintLnStr("setIndAlarm ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        if (DEBUG)
            sPrintLnStr("setIndAlarm OFF");
        OLDSTATE = state;
    }
}

void setIndMan(bool state)
{
    // digitalWrite(PIN_IND_MAN, deBouncing(getManualMode(), "setIndMan "));
    static int buttonState = 0;     // current state of the button
    static int lastButtonState = 0; // previous state of the button

    static int currentButtonState = 0;         // current state of the button
    static unsigned long lastDebounceTime = 0; // the last time the output pin was toggled
    static unsigned long debounceDelay = 50;   // the debounce time; increase if the output flickers

    currentButtonState = getManualMode(); // read the state of the switch into a local variable

    if (currentButtonState != lastButtonState) // If the switch changed, due to noise or pressing
    {
        lastDebounceTime = millis(); // reset the debouncing timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay) // if the switch value has been stable for a while
    {
        if (currentButtonState != buttonState) // if the button state has changed
        {
            buttonState = currentButtonState; // save the new state
            if (buttonState == ON)            // if the button state is HIGH
            {
                if (DEBUG)
                    sPrintLnStr("_setIndMan OFF");
                outputVarsImage[POS_IND_MAN] = OFF;
                // digitalWrite(PIN_IND_MAN, OFF);
                //  setIndMan(OFF); // Toggle Auto Mode
            }
            else if (buttonState == OFF)
            {
                if (DEBUG)
                    sPrintLnStr("_setIndMan ON");
                outputVarsImage[POS_IND_MAN] = ON;
                // digitalWrite(PIN_IND_MAN, ON);
                //  setIndMan(ON); // Toggle Auto Mode
            }
        }
    }
    lastButtonState = currentButtonState; // save the current state as the last state, for next time through the loop
}

void setAutoMode(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_IND_AUTO, ON);
        outputVarsImage[POS_IND_AUTO] = ON;
        if (DEBUG)
            sPrintLnStr("setAutoMode ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_IND_AUTO, OFF);

        outputVarsImage[POS_IND_AUTO] = OFF;
        if (DEBUG)
            sPrintLnStr("setAutoMode OFF");
        OLDSTATE = state;
    }
}

void setPump(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_BMB, ON);
        outputVarsImage[POS_BMB] = ON;
        if (DEBUG)
            sPrintLnStr("setPump ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_BMB, OFF);
        outputVarsImage[POS_BMB] = OFF;
        if (DEBUG)
            sPrintLnStr("setPump OFF");
        OLDSTATE = state;
    }
}

void setValveWaterIn(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_VALV_WATER_IN, ON);
        outputVarsImage[POS_VALV_WATER_IN] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_VALV_WATER_IN, OFF);
        outputVarsImage[POS_VALV_WATER_IN] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn OFF");
        OLDSTATE = state;
    }
}

void setValveWaterOut(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_VALV_WATER_OUT, ON);
        outputVarsImage[POS_VALV_WATER_OUT] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_VALV_WATER_OUT, OFF);
        outputVarsImage[POS_VALV_WATER_OUT] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut OFF");
        OLDSTATE = state;
    }
}

void setResistor(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        // digitalWrite(PIN_RAQ, ON);
        outputVarsImage[POS_RAQ] = ON;
        if (DEBUG)
            sPrintLnStr("setResistor ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        // digitalWrite(PIN_RAQ, OFF);
        outputVarsImage[POS_RAQ] = OFF;
        if (DEBUG)
            sPrintLnStr("setResistor OFF");
        OLDSTATE = state;
    }
}
