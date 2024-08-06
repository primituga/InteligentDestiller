/**
 * @file MD_Web_IO_Mngmnt.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief
 * @version 0.1
 */
#include "MD.h"

uint8_t outputVarsImageWeb[9]; /// Output variables image

////////////////////////////////////////////////////////////////////////////////////////
/// FUNCTIONS BLOCK
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Update Outputs Web
 *
 * This function updates the outputs for the web interface.
 *
 * @return void
 */
void updateOutputsWeb()
{
    outputVarsImageWeb[0] = getResistor();       /// Update the resistor state
    outputVarsImageWeb[1] = getPump();           /// Update the pump state
    outputVarsImageWeb[2] = getValv_Water_Out(); /// Update the water out valve state
    outputVarsImageWeb[3] = getValv_Water_In();  /// Update the water in valve state
    outputVarsImageWeb[4] = getAlarm();          /// Update the alarm state
    outputVarsImageWeb[5] = getWaterMin();       /// Update the water min state
    outputVarsImageWeb[6] = getWaterMax();       /// Update the water max state
    outputVarsImageWeb[8] = getManualMode();     /// Update the manual mode state
    /// outputVarsImageWeb[7] = getIndAuto();        /// Update the auto indicator state
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
    static bool OLDSTATE; /// Static variable to store the old state
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_IND_AUTO] = ON; /// Set the auto indicator to ON
        OLDSTATE = state;                      /// Set the old state to the current state
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_AUTO] = OFF; /// Set the auto indicator to OFF
        OLDSTATE = state;                       /// Set the old state to the current state
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
    static bool OLDSTATE; /// Static variable to store the old state
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_BMB] = ON; /// Set the pump to ON
        OLDSTATE = state;                 /// Set the old state to the current state
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_BMB] = OFF; /// Set the pump to OFF
        OLDSTATE = state;                  /// Set the old state to the current state
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
    static bool OLDSTATE; /// Static variable to store the old state
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = ON; /// Set the water in valve to ON
        OLDSTATE = state;                           /// Set the old state to the current state
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = OFF; /// Set the water in valve to OFF
        OLDSTATE = state;                            /// Set the old state to the current state
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
    static bool OLDSTATE; /// Static variable to store the old state
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = ON; /// Set the water out valve to ON
        OLDSTATE = state;                            /// Set the old state to the current state
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = OFF; /// Set the water out valve to OFF
        OLDSTATE = state;                             /// Set the old state to the current state
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
    static bool OLDSTATE; /// Static variable to store the old state
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_RAQ] = ON; /// Set the resistor to ON
        OLDSTATE = state;                 /// Set the old state to the current state
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_RAQ] = OFF; /// Set the resistor to OFF
        OLDSTATE = state;                  /// Set the old state to the current state
    }
}

////////////////////////////////////////////////////////////////////////////////////////
/// TOGGLES BLOCK
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Toggle Auto Mode Web
 *
 * This function toggles the auto mode.
 *
 * @return void
 */
void toggleAutoModeWeb()
{
    bool state = getIndAuto(); /// Get the auto indicator state
    if (state == OFF && !getManualMode())
    {
        state = !state;        /// Toggle the auto indicator state
        setAutoModeWeb(state); /// Set the auto indicator state
    }
    else if (state == ON && !getManualMode())
    {
        state = !state;        /// Toggle the auto indicator state
        setAutoModeWeb(state); /// Set the auto indicator state
    }
}

/**
 * @brief Toggle Pump Web
 *
 * This function toggles the pump.
 *
 * @return void
 */
void togglePumpWeb() /// Toggle Pump
{
    bool state = getPumpWeb(); /// Get the pump state
    if (state == OFF && getManualMode())
    {
        state = !state;              /// Toggle the pump state
        setPumpWeb(state);           /// Set the pump state
        sPrintStr("togglePumpWeb "); /// Print the pump state
        Serial.println(state);       /// Print the pump state
    }
    else if (state == ON && getManualMode())
    {
        state = !state;              /// Toggle the pump state
        setPumpWeb(state);           /// Set the pump state
        sPrintStr("togglePumpWeb "); /// Print the pump state
        Serial.println(state);       /// Print the pump state
    }
}

/**
 * @brief Toggle Valve Water In Web
 *
 * This function toggles the water in valve.
 *
 * @return void
 */
void toggleValveWaterInWeb() /// Toggle Valve Water In
{
    bool state = getValv_Water_In(); /// Get the water in valve state
    if (state == OFF && getManualMode())
    {
        state = !state;            /// Toggle the water in valve state
        setValveWaterInWeb(state); /// Set the water in valve state
    }
    else if (state == ON && getManualMode())
    {
        state = !state;            /// Toggle the water in valve state
        setValveWaterInWeb(state); /// Set the water in valve state
    }
}

/**
 * @brief Toggle Valve Water Out Web
 *
 * This function toggles the water out valve.
 *
 * @return void
 */
void toggleValveWaterOutWeb() /// Toggle Valve Water Out
{
    bool state = getValv_Water_Out();    /// Get the water out valve state
    if (state == OFF && getManualMode()) /// If the water out valve state is OFF and the manual mode is ON
    {
        state = !state;             /// Toggle the water out valve state
        setValveWaterOutWeb(state); /// Set the water out valve state
    }
    else if (state == ON && getManualMode())
    {
        state = !state;             /// Toggle the water out valve state
        setValveWaterOutWeb(state); /// Set the water out valve state
    }
}

/**
 * @brief Toggle Resistor Web
 *
 * This function toggles the resistor.
 *
 * @return void
 */
void toggleResistorWeb() /// Toggle Resistor
{
    bool state = getResistor(); /// Get the resistor state

    if (state == OFF && getManualMode())
    {
        state = !state;        /// Toggle the resistor state
        setResistorWeb(state); /// Set the resistor state
    }
    else if (state == ON && getManualMode())
    {
        state = !state;        /// Toggle the resistor state
        setResistorWeb(state); /// Set the resistor state
    }
}