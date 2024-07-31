/**
 * @file OS_GPIO.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief 
 * @version 0.1
 * @date 2024-07-31
 * 
 * @copyright Copyright (c) 2024
 * 
 */

#include "OS.h"

////////////////////////////////////////////////////////////////////////////////////////
/// GPIO Images
////////////////////////////////////////////////////////////////////////////////////////
uint8_t inputVarsImage[5];
const uint8_t inputVarsPINs[] = {PIN_SW_MAN, PIN_SMIN, PIN_SMAX, PIN_SW_AUTO, PIN_SALARM};

uint8_t outputVarsImage[9];
const uint8_t outputVarsPINs[] = {PIN_RAQ, PIN_BMB, PIN_VALV_WATER_OUT, PIN_VALV_WATER_IN, PIN_IND_ALARM, PIN_IND_MIN, PIN_IND_MAX, PIN_IND_AUTO, PIN_IND_MAN};

////////////////////////////////////////////////////////////////////////////////////////
/// Read ESP32 GPIOs and stores in the image array
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Read all inputs and store in the image array
 * 
 * This function reads all the inputs and stores them in the image array.
 * The image array is used to store the current state of the inputs and outputs.
 *
 */
void readInputs()
{
    for (uint8_t i = 0; i < PIN_INPUT_COUNT; i++)
    {
        inputVarsImage[i] = digitalRead(inputVarsPINs[i]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////
/// Write Outputs from array image to GPIO
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Write all outputs from the image array to the GPIOs
 * 
 * This function writes all the outputs from the image array to the GPIOs.
 * The image array is used to store the current state of the inputs and outputs.
 *
 */
void writeOutputs()
{
    for (uint8_t i = 0; i < PIN_OUTPUT_COUNT; i++)
    {
        digitalWrite(outputVarsPINs[i], outputVarsImage[i]);
    }
}

////////////////////////////////////////////////////////////////////////////////////////
/// Configure GPIOs as INPUT
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Configure GPIOs as INPUTs
 * 
 * This function configures the GPIOs as INPUTs.
 * The GPIOs are used to read the state of the switches and sensors.
 *
 */
void initPinsInputs()
{
    pinMode(PIN_SW_MAN, INPUT); /// on/off sw
    pinMode(PIN_SMIN, INPUT);
    pinMode(PIN_SMAX, INPUT);
    pinMode(PIN_SW_AUTO, INPUT); /// push sw
    pinMode(PIN_SALARM, INPUT);
}

////////////////////////////////////////////////////////////////////////////////////////
///  Configure GPIOs as OUTPUTs
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Configure GPIOs as OUTPUTs
 * 
 * This function configures the GPIOs as OUTPUTs.
 * The GPIOs are used to control the indicators, valves, pump, and resistor.
 *
 */
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

////////////////////////////////////////////////////////////////////////////////////////
/// GETS BLOCK
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Get the Water Max object
 * 
 * This function returns the state of the water max sensor.
 * 
 * @return true 
 * @return false 
 */
bool getWaterMax()
{
    return !inputVarsImage[POS_SMAX];
}

/**
 * @brief Get the Water Min object
 * 
 * This function returns the state of the water min sensor.
 * 
 * @return true 
 * @return false 
 */
bool getWaterMin()
{
    return inputVarsImage[POS_SMIN];
}

/**
 * @brief Get the Alarm object
 * 
 * This function returns the state of the alarm.
 * 
 * @return true 
 * @return false 
 */
bool getAlarm()
{
    return inputVarsImage[POS_SALARM];
}

/**
 * @brief Get the Auto Mode SW object
 * 
 * This function returns the state of the auto mode switch.
 * 
 * @return true 
 * @return false 
 */
bool getAutoModeSW()
{
    return inputVarsImage[POS_SW_AUTO];
}

/**
 * @brief Get the Manual Mode object
 * 
 * This function returns the state of the manual mode switch.
 * 
 * @return true 
 * @return false 
 */
bool getManualMode()
{
    return inputVarsImage[POS_SW_MAN];
}

/**
 * @brief Get the Ind Max object
 * 
 * This function returns the state of the max indicator.
 * 
 * @return true 
 * @return false 
 */
bool getAutoMode()
{
    return outputVarsImage[POS_IND_AUTO];
}

/**
 * @brief Get the Ind Min object
 * 
 * This function returns the state of the min indicator.
 * 
 * @return true 
 * @return false 
 */
bool getResistor()
{
    return outputVarsImage[POS_RAQ];
}

/**
 * @brief Get the Ind Alarm object
 * 
 * This function returns the state of the alarm indicator.
 * 
 * @return true 
 * @return false 
 */
bool getValv_Water_In()
{
    return outputVarsImage[POS_VALV_WATER_IN];
}

/**
 * @brief Get the Valv Water Out object
 * 
 * This function returns the state of the water out valve.
 * 
 * @return true 
 * @return false 
 */
bool getValv_Water_Out()
{
    return outputVarsImage[POS_VALV_WATER_OUT];
}

/**
 * @brief Get the Pump object
 * 
 * This function returns the state of the water pump.
 * 
 * @return true 
 * @return false 
 */
bool getPump()
{
    return outputVarsImage[POS_BMB];
}

////////////////////////////////////////////////////////////////////////////////////////
/// SETS BLOCK
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Set the Ind Max object
 * 
 * This function sets the state of the max indicator.
 * 
 * @param state
 * 
 * @return void
 */
void setIndMax(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_IND_MAX] = ON;
        if (DEBUG)
            sPrintLnStr("setIndMax ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_IND_MAX] = OFF;
        if (DEBUG)
            sPrintLnStr("setIndMax OFF");
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Ind Min object
 * 
 * This function sets the state of the min indicator.
 * 
 * @param state
 * 
 * @return void
 */
void setIndMin(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_IND_MIN] = ON;
        if (DEBUG)
        {
            sPrintLnStr("setIndMin ON");
        }
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_IND_MIN] = OFF;
        if (DEBUG)
        {
            sPrintLnStr("setIndMin OFF");
        }
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Ind Alarm object
 * 
 * This function sets the state of the alarm indicator.
 * 
 * @param state
 * 
 * @return void
 */
void setIndAlarm(bool state)
{
    static bool OLDSTATE;
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (state == ON)
    {
        if (millis() - previousTimer > ALARM_TIME_ON)
        {
            outputVarsImage[POS_IND_ALARM] = OFF;
            previousTimer = millis();
        }
        else if (millis() - previousTimer > ALARM_TIME_OFF)
        {
            outputVarsImage[POS_IND_ALARM] = ON;
        }
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_IND_ALARM] = OFF;
    }

    ///  Condition to debug
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

/**
 * @brief Set the Ind Man object
 * 
 * This function sets the state of the manual indicator.
 * 
 * @param state 
 * 
 * @return void
 * 
 */
void setIndMan(bool state)
{
    static int buttonState = 0;     /// current state of the button
    static int lastButtonState = 0; /// previous state of the button

    static int currentButtonState = 0;         /// current state of the button
    static unsigned long lastDebounceTime = 0; /// the last time the output pin was toggled
    static unsigned long debounceDelay = 50;   /// the debounce time; increase if the output flickers

    currentButtonState = getManualMode(); /// read the state of the switch into a local variable

    if (currentButtonState != lastButtonState) /// If the switch changed, due to noise or pressing
    {
        lastDebounceTime = millis(); /// reset the debouncing timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay) /// if the switch value has been stable for a while
    {
        if (currentButtonState != buttonState) /// if the button state has changed
        {
            buttonState = currentButtonState; /// save the new state
            if (buttonState == ON)            /// if the button state is HIGH
            {
                if (DEBUG)
                    sPrintLnStr("_setIndMan OFF");
                outputVarsImage[POS_IND_MAN] = OFF;
            }
            else if (buttonState == OFF)
            {
                if (DEBUG)
                    sPrintLnStr("_setIndMan ON");
                outputVarsImage[POS_IND_MAN] = ON;
            }
        }
    }
    lastButtonState = currentButtonState; /// save the current state as the last state, for next time through the loop
}

/**
 * @brief Set the Auto Mode object
 * 
 * This function sets the state of the auto mode.
 * 
 * @param state 
 * 
 * @return void
 */
void setAutoMode(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_IND_AUTO] = ON;
        if (DEBUG)
            sPrintLnStr("setAutoMode ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_IND_AUTO] = OFF;
        if (DEBUG)
            sPrintLnStr("setAutoMode OFF");
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Pump object
 * 
 * This function sets the state of the pump.
 * 
 * @param state 
 * 
 * @return void
 */
void setPump(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_BMB] = ON;
        if (DEBUG)
            sPrintLnStr("setPump ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_BMB] = OFF;
        if (DEBUG)
            sPrintLnStr("setPump OFF");
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Valve Water In object
 * 
 * This function sets the state of the water in valve.
 * 
 * @param state 
 * 
 * @return void
 */
void setValveWaterIn(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_VALV_WATER_IN] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_VALV_WATER_IN] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn OFF");
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Valve Water Out object
 * 
 * This function sets the state of the water out valve.
 * 
 * @param state 
 * 
 * @return void
 */
void setValveWaterOut(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_VALV_WATER_OUT] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_VALV_WATER_OUT] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut OFF");
        OLDSTATE = state;
    }
}

/**
 * @brief Set the Resistor object
 * 
 * This function sets the state of the resistor.
 * 
 * @param state 
 * 
 * @return void
 */
void setResistor(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImage[POS_RAQ] = ON;
        if (DEBUG)
            sPrintLnStr("setResistor ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImage[POS_RAQ] = OFF;
        if (DEBUG)
            sPrintLnStr("setResistor OFF");
        OLDSTATE = state;
    }
}
