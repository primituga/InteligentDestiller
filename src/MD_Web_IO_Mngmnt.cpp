/**
 * @file MD_Web_IO_Mngmnt.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief
 * @version 0.1
 */
#include "MD.h"

uint8_t inputVarsImageWeb[5];  /// Input variables image

uint8_t outputVarsImageWeb[9]; /// Output variables image

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
bool getWaterMaxWeb()
{
    return !inputVarsImageWeb[POS_SMAX];
}

/**
 * @brief Get the Water Min object
 *
 * This function returns the state of the water min sensor.
 *
 * @return true
 * @return false
 */
bool getWaterMinWeb()
{
    return inputVarsImageWeb[POS_SMIN];
}

/**
 * @brief Get the Alarm object
 *
 * This function returns the state of the alarm.
 *
 * @return true
 * @return false
 */
bool getAlarmWeb()
{
    return inputVarsImageWeb[POS_SALARM];
}

/**
 * @brief Get the Auto Mode SW object
 *
 * This function returns the state of the auto mode switch.
 *
 * @return true
 * @return false
 */
bool getAutoModeSWWeb()
{
    return inputVarsImageWeb[POS_SW_AUTO];
}

/**
 * @brief Get the Manual Mode object
 *
 * This function returns the state of the manual mode switch.
 *
 * @return true
 * @return false
 */
bool getManualModeWeb()
{
    return inputVarsImageWeb[POS_SW_MAN];
}

/**
 * @brief Get the Ind Max object
 *
 * This function returns the state of the max indicator.
 *
 * @return true
 * @return false
 */
bool getAutoModeWeb()
{
    return outputVarsImageWeb[POS_IND_AUTO];
}

/**
 * @brief Get the Ind Min object
 *
 * This function returns the state of the min indicator.
 *
 * @return true
 * @return false
 */
bool getResistorWeb()
{
    return outputVarsImageWeb[POS_RAQ];
}

/**
 * @brief Get the Ind Alarm object
 *
 * This function returns the state of the alarm indicator.
 *
 * @return true
 * @return false
 */
bool getValv_Water_InWeb()
{
    return outputVarsImageWeb[POS_VALV_WATER_IN];
}

/**
 * @brief Get the Valv Water Out object
 *
 * This function returns the state of the water out valve.
 *
 * @return true
 * @return false
 */
bool getValv_Water_OutWeb()
{
    return outputVarsImageWeb[POS_VALV_WATER_OUT];
}

/**
 * @brief Get the Pump object
 *
 * This function returns the state of the water pump.
 *
 * @return true
 * @return false
 */
bool getPumpWeb()
{
    return outputVarsImageWeb[POS_BMB];
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
void setIndMaxWeb(bool state)
{
    static bool OLDSTATE;   /// Old state of the indicator
    if (state == ON && OLDSTATE == OFF) 
    {
        outputVarsImageWeb[POS_IND_MAX] = ON;
        if (DEBUG)
            sPrintLnStr("setIndMax ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_MAX] = OFF;
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
void setIndMinWeb(bool state)
{
    static bool OLDSTATE;   /// Old state of the indicator
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_IND_MIN] = ON;
        if (DEBUG)
        {
            sPrintLnStr("setIndMin ON");
        }
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_MIN] = OFF;
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
void setIndAlarmWeb(bool state)
{
    static bool OLDSTATE;   /// Old state of the indicator
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (state == ON && OLDSTATE == OFF)
    {
        //if (millis() - previousTimer > ALARM_TIME_ON)
        //{
        //    outputVarsImage[POS_IND_ALARM] = OFF;
         //   previousTimer = millis();
        //}
        //else if (millis() - previousTimer > ALARM_TIME_OFF)
        //{
            outputVarsImageWeb[POS_IND_ALARM] = ON;
        //}
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_ALARM] = OFF;
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
void setIndManWeb(bool state)
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
                outputVarsImageWeb[POS_IND_MAN] = OFF;
            }
            else if (buttonState == OFF)
            {
                if (DEBUG)
                    sPrintLnStr("_setIndMan ON");
                outputVarsImageWeb[POS_IND_MAN] = ON;
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
void setAutoModeWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_IND_AUTO] = ON;
        if (DEBUG)
            sPrintLnStr("setAutoMode ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_AUTO] = OFF;
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
void setPumpWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_BMB] = ON;
        if (DEBUG)
            sPrintLnStr("setPump ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_BMB] = OFF;
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
void setValveWaterInWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = OFF;
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
void setValveWaterOutWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = OFF;
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
void setResistorWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_RAQ] = ON;
        if (DEBUG)
            sPrintLnStr("setResistor ON");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_RAQ] = OFF;
        if (DEBUG)
            sPrintLnStr("setResistor OFF");
        OLDSTATE = state;
    }
}
