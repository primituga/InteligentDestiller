#include "MD.h"

/*void toggleAutoMode()
{
    static bool currentState;
    static bool lastState = ON;
    static bool state = OFF;
    currentState = getAutoModeSW();

    if (lastState == ON && currentState == OFF)
    {
        state = !state;
        toggleAutoModeWEB();
        //setAutoMode(state);
    }
    lastState = currentState;
}
*/


void toggleAutoMode()
{
static int buttonState = 0;
static int lastButtonState = 0;

static int currentButtonState = 0;
static unsigned long lastDebounceTime = 0;
static unsigned long debounceDelay = 50;

    currentButtonState = getAutoModeSW();

    if (currentButtonState != lastButtonState)
    {
        lastDebounceTime = millis();
    }

    if ((millis() - lastDebounceTime) > debounceDelay)
    {
        if (currentButtonState != buttonState)
        {
            buttonState = currentButtonState;
            if (buttonState == OFF)
            {
                toggleAutoModeWEB();
            }
        }
    }
    lastButtonState = currentButtonState;
}

void toggleAutoModeWEB()
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

void togglePump()
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

void toggleValveWaterIn()
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

void toggleValveWaterOut()
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

void toggleResistor()
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

void workingMax(){
    setResistor(ON);
    setPump(OFF);
    //setValveWaterIn(ON);
    //setValveWaterOut(ON);
}

void workingMin(){
    setPump(ON);
    //setValveWaterIn(ON);
    //setValveWaterOut(ON);

}

void workingAlarm(){
    setResistor(OFF);
    setPump(ON);
    //setValveWaterIn(OFF);
    //setValveWaterOut(OFF);
}

void workingIdle(){
    setResistor(OFF);
    setValveWaterIn(OFF);
    setValveWaterOut(OFF);
}