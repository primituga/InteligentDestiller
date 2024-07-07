#include "MD.h"

void toggleAutoMode()   // Toggle Auto Mode
{
static int buttonState = 0; // current state of the button
static int lastButtonState = 0; // previous state of the button

static int currentButtonState = 0;  // current state of the button
static unsigned long lastDebounceTime = 0;  // the last time the output pin was toggled
static unsigned long debounceDelay = 50;    // the debounce time; increase if the output flickers

    currentButtonState = getAutoModeSW();   // read the state of the switch into a local variable

    if (currentButtonState != lastButtonState)  // If the switch changed, due to noise or pressing
    {
        lastDebounceTime = millis();    // reset the debouncing timer
    }

    if ((millis() - lastDebounceTime) > debounceDelay)  // if the switch value has been stable for a while
    {
        if (currentButtonState != buttonState)  // if the button state has changed
        {
            buttonState = currentButtonState;   // save the new state
            if (buttonState == OFF) // if the button state is HIGH
            {
                toggleAutoModeWEB();    // Toggle Auto Mode
            }
        }
    }
    lastButtonState = currentButtonState;   // save the current state as the last state, for next time through the loop
}

void toggleAutoModeWEB()    // Toggle Auto Mode
{
    bool state = getAutoMode();

    if (state == OFF)
    {
        state = !state;
        setAutoMode(state);
    }
    else
    {
        state = !state;
        setAutoMode(state);
    }
}

void togglePump()   // Toggle Pump
{
    bool state = getPump();
    if (state == OFF)
    {
        state = !state;
        setPump(state);
    }
    else
    {
        state = !state;
        setPump(state);
    }
}

void toggleValveWaterIn()   // Toggle Valve Water In
{
    bool state = getValv_Water_In();

    if (state == OFF)
    {
        state = !state;
        setValveWaterIn(state);
    }
    else
    {
        state = !state;
        setValveWaterIn(state);
    }
}

void toggleValveWaterOut()  // Toggle Valve Water Out
{
    bool state = getValv_Water_Out();

    if (state == OFF)
    {
        state = !state;
        setValveWaterOut(state);
    }
    else
    {
        state = !state;
        setValveWaterOut(state);
    }
}

void toggleResistor()   // Toggle Resistor
{
    bool state = getResistor();

    if (state == OFF)
    {
        state = !state;
        setResistor(state);
    }
    else
    {
        state = !state;
        setResistor(state);
    }
}

void workingMax(){  // Working state when water level is max
    setResistor(ON);
    setPump(OFF);
    setValveWaterIn(ON);
    setValveWaterOut(ON);
}

void workingMaxMin(){   // Working state when water level is between max and min
    setResistor(ON);
    setValveWaterIn(ON);
    setValveWaterOut(ON);
}

void workingMin(){  // Working state when water level is min
    setPump(ON);
    setValveWaterIn(ON);
    setValveWaterOut(ON);

}

void workingAlarm(){    // Working state when water level is alarm
    setResistor(OFF);
    setPump(ON);
    setValveWaterIn(OFF);
    setValveWaterOut(OFF);
}

void workingIdle(){
    setResistor(OFF);
    setValveWaterIn(OFF);
    setValveWaterOut(OFF);
}