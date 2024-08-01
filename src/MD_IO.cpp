/**
 * @author Sérgio Carmo
 * @file MD_IO.cpp
 * @brief IO functions for the MD project
 * <This file contains the IO functions for the MD project that are used to control the Machine and
 * its peripherals using the ESP32 GPIOs and the Web Interface of the project.>
 * @version 1.0
 */

#include "MD.h"
/**
 * @brief Toggle the Auto Mode of the Machine
 *
 * @note This function is used to toggle the Auto Mode of the Machine
 *
 */
void toggleIndAuto()
{
    bool state = getIndAuto();

    if (state == OFF)
    {
        state = !state;
        setIndAuto(state);
        setAutoModeWeb(state);
    }
    else
    {
        state = !state;
        setIndAuto(state);
        setAutoModeWeb(state);
    }
}

/**
 * @brief Toggle the Auto Mode of the Machine using a switch connected to the ESP32 GPIO 4 (D4)
 *
 * @note This function is used to toggle the Auto Mode of the Machine using a switch connected to the ESP32 GPIO 4 (D4)
 */
void toggleAutoMode()
{
    static int buttonState = 0;     /// current state of the button
    static int lastButtonState = 0; /// previous state of the button

    static int currentButtonState = 0;         /// current state of the button
    static unsigned long lastDebounceTime = 0; /// the last time the output pin was toggled
    static unsigned long debounceDelay = 50;   /// the debounce time; increase if the output flickers

    currentButtonState = getAutoModeSW(); /// read the state of the switch into a local variable

    if (currentButtonState != lastButtonState) /// If the switch changed, due to noise or pressing
    {
        lastDebounceTime = millis(); /// reset the debouncing timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay) /// if the switch value has been stable for a while
    {
        if (currentButtonState != buttonState) /// if the button state has changed
        {
            buttonState = currentButtonState; /// save the new state
            if (buttonState == OFF)           /// if the button state is HIGH
            {
                toggleIndAuto(); /// Toggle Auto Mode
            }
        }
    }
    lastButtonState = currentButtonState; /// save the current state as the last state, for next time through the loop
}

void togglePump() /// Toggle Pump
{
    bool state = getPump();
    if (state == OFF)
    {
        state = !state;
        setPump(state);
        setPumpWeb(state);
    }
    else
    {
        state = !state;
        setPump(state);
        setPumpWeb(state);
    }
}

void toggleValveWaterIn() /// Toggle Valve Water In
{
    bool state = getValv_Water_In();

    if (state == OFF)
    {
        state = !state;
        setValveWaterIn(state);
        setValveWaterInWeb(state);
    }
    else
    {
        state = !state;
        setValveWaterIn(state);
        setValveWaterInWeb(state);
    }
}

void toggleValveWaterOut() /// Toggle Valve Water Out
{
    bool state = getValv_Water_Out();

    if (state == OFF)
    {
        state = !state;
        setValveWaterOut(state);
        setValveWaterOutWeb(state);
    }
    else
    {
        state = !state;
        setValveWaterOut(state);
        setValveWaterOutWeb(state);
    }
}

void toggleResistor() /// Toggle Resistor
{
    bool state = getResistor();

    if (state == OFF)
    {
        state = !state;
        setResistor(state);
        setResistorWeb(state);
    }
    else
    {
        state = !state;
        setResistor(state);
        setResistorWeb(state);
    }
}

////////////////////////////////////////////////////////////////////////////////////////
// DESTILLER STATE MANAGEMENT BLOCK
////////////////////////////////////////////////////////////////////////////////////////

void workingMax()
{ /// Working state when water level is max
    setResistor(ON);
    setValveWaterIn(ON);
    setValveWaterOut(OFF);
}

void workingMaxMin()
{ /// Working state when water level is between max and min
    setResistor(ON);
    setValveWaterIn(ON);
    setValveWaterOut(OFF);
}

void workingMin()
{ /// Working state when water level is min
    setValveWaterIn(ON);
    setValveWaterOut(OFF);
}

void workingAlarm()
{ /// Working state when water level is alarm
    setResistor(OFF);
    setValveWaterIn(OFF);
    setValveWaterOut(ON);
}

void workingIdle()
{ /// Working state when water level is idle
    setResistor(OFF);
    setValveWaterIn(OFF);
    setValveWaterOut(OFF);
}

void workingOFF()
{ /// Working state when water level is idle
    setResistor(OFF);
    setValveWaterIn(OFF);
    setValveWaterOut(OFF);
    setPump(OFF);


    /*setResistorWeb(OFF);
    setValveWaterInWeb(OFF);
    setValveWaterOutWeb(OFF);
    setPumpWeb(OFF);*/
}

void waterManagementAuto()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    // WATER MANAGEMENT BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    if (getWaterMax())
    {
        setPump(OFF);
    }
    else if (getWaterMin())
    {
        setPump(ON);
    }
    else if (getAlarm())
    {
        setPump(ON);
    }
}

void waterManagementManual()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    // WATER MANAGEMENT BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    if (getWaterMax())
    {
        setPump(OFF);
    }

    if (getAlarm())
    {
        setResistor(OFF);
    }
}

void indicatorsManagement()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    /// INDICATORS BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    if (getWaterMax())
    {
        setIndMax(ON);
    }
    else if (!getWaterMax())
    {
        setIndMax(OFF);
    }

    if (getWaterMin())
    {
        setIndMin(ON);
    }
    else if (!getWaterMin())
    {
        setIndMin(OFF);
    }

    if (getAlarm())
    {
        setIndAlarm(ON);
    }
    else if (!getAlarm())
    {
        setIndAlarm(OFF);
    }

    if (getManualMode())
    {
        setIndMan(ON);
    }
    else if (!getManualMode())
    {
        setIndMan(OFF);
    }
}

void modeManagement()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    /// MACHINE MODE MANAGEMENT BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    if (!getManualMode())
    {
        toggleAutoMode();
        setIndAuto(getAutoModeWeb());
    }

    /*if (getAutoModeWeb() && !getManualMode())
    {
        setIndAuto(ON);
    }
    else
    {
        setIndAuto(OFF);
    }*/
}