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
        // ws.textAll(String(state));
        ws.textAll(String(" autoMode: " + state));
    }
    else
    {
        state = !state;
        setIndAuto(state);
        setAutoModeWeb(state);
        // ws.textAll(String(state));
        ws.textAll(String(" autoMode: " + state));
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

void indicatorsManagement()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    /// INDICATORS BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    setIndMax(getWaterMax());   /// Set the maximum water level indicator
    setIndMin(getWaterMin());   /// Set the minimum water level indicator
    setIndAlarm(getAlarmIND());    /// Set the alarm indicator
    setIndMan(getManualMode()); /// Set the manual mode indicator
}

void modeManagement()
{
    ////////////////////////////////////////////////////////////////////////////////////////
    /// MACHINE MODE MANAGEMENT BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    /// If the machine is in manual mode, turn off the auto mode indicator
    if (!getManualMode())
    {
        toggleAutoMode();             /// Toggle the auto mode
        setIndAuto(getAutoModeWeb()); /// Set the auto mode indicator to the web value of the auto mode
    }
    else
    {
        setIndAuto(OFF); /// Set the auto mode indicator to OFF
    }

    /// If the machine is in manual mode, turn off the timer
    if (!getIndAuto())
    {
        setTimer(OFF);  /// Turn off the timer
    }
}