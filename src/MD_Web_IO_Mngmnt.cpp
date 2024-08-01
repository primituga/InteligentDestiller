/**
 * @file MD_Web_IO_Mngmnt.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief
 * @version 0.1
 */
#include "MD.h"

// uint8_t inputVarsImageWeb[5];  /// Input variables image
// nao, vou a origem

uint8_t outputVarsImageWeb[9]; /// Output variables image

////////////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS BLOCK
////////////////////////////////////////////////////////////////////////////////////////
void updateOutputsWeb()
{
    outputVarsImageWeb[0] = getResistor();
    outputVarsImageWeb[1] = getPump();
    outputVarsImageWeb[2] = getValv_Water_Out();
    outputVarsImageWeb[3] = getValv_Water_In();
    outputVarsImageWeb[4] = getAlarm();
    outputVarsImageWeb[5] = getWaterMin();
    outputVarsImageWeb[6] = getWaterMax();
    outputVarsImageWeb[7] = getIndAuto();
    outputVarsImageWeb[8] = getManualMode();
}

////////////////////////////////////////////////////////////////////////////////////////
/// GETS BLOCK
////////////////////////////////////////////////////////////////////////////////////////

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
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_AUTO] = OFF;
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
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_BMB] = OFF;
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
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = OFF;
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
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = OFF;
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
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_RAQ] = OFF;
        OLDSTATE = state;
    }
}

////////////////////////////////////////////////////////////////////////////////////////
/// TOGGLES BLOCK
////////////////////////////////////////////////////////////////////////////////////////

void toggleAutoModeWeb()
{
    bool state = getIndAuto();

    if (state == OFF && !getManualMode())
    {
        state = !state;
        setAutoModeWeb(state);
    }
    else if (state == ON && !getManualMode())
    {
        state = !state;
        setAutoModeWeb(state);
    }
}

void togglePumpWeb() /// Toggle Pump
{
    bool state = getPump();
    if (state == OFF)
    {
        state = !state;
        setPumpWeb(state);
    }
    else
    {
        state = !state;
        setPumpWeb(state);
    }
}

void toggleValveWaterInWeb() /// Toggle Valve Water In
{
    bool state = getValv_Water_In();

    if (state == OFF)
    {
        state = !state;
        setValveWaterInWeb(state);
    }
    else
    {
        state = !state;
        setValveWaterInWeb(state);
    }
}

void toggleValveWaterOutWeb() /// Toggle Valve Water Out
{
    bool state = getValv_Water_Out();

    if (state == OFF)
    {
        state = !state;
        setValveWaterOutWeb(state);
    }
    else
    {
        state = !state;
        setValveWaterOutWeb(state);
    }
}

void toggleResistorWeb() /// Toggle Resistor
{
    bool state = getResistor();

    if (state == OFF)
    {
        state = !state;
        setResistorWeb(state);
    }
    else
    {
        state = !state;
        setResistorWeb(state);
    }
}