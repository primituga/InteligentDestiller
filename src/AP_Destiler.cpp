/**
 * @author Sérgio Carmo
 * @file AP_Destiler.cpp
 * @brief Application file for the MD project.
 * @version 1.0
 */

#include "AP.h"

/**
 * @brief Destiler function
 *
 * This function is responsible for managing the operation of the machine.
 *
 */
void destiler()
{
    /**
     * @brief BMB_FLAG, RAQ_FLAG
     * BMB_FLAG and RAQ_FLAG are flags that are used to control the operation of the machine.
     * BMB_FLAG is used to control the operation of the water pump.
     * RAQ_FLAG is used to control the operation of the water heater resistor.
     * @note BMB_FLAG and RAQ_FLAG are used to control the operation of the machine.
     * @note BMB_FLAG is used to control the operation of the water pump.
     * @note RAQ_FLAG is used to control the operation of the water heater resistor.
     */
    static bool BMB_FLAG, RAQ_FLAG = OFF;

    if (DEBUGlog) /**< Debug information logging */
    {
        static unsigned long previousTimer = 0;
        unsigned long currentTimer = millis();
        if (millis() - previousTimer > 5000)
        {
            previousTimer = millis();
            sPrintLnStr("  ");
            sPrintStr("getWaterMax ");
            sPrintLnNbr(getWaterMax());
            sPrintStr("getWaterMin ");
            sPrintLnNbr(getWaterMin());
            sPrintStr("getAlarm ");
            sPrintLnNbr(getAlarm());
            sPrintStr("getManualMode ");
            sPrintLnNbr(getManualMode());
            sPrintStr("getPump ");
            sPrintLnNbr(getPump());
            sPrintStr("getValv_Water_In ");
            sPrintLnNbr(getValv_Water_In());
            sPrintStr("getValv_Water_Out ");
            sPrintLnNbr(getValv_Water_Out());
            sPrintStr("getResistor ");
            sPrintLnNbr(getResistor());
            sPrintStr("getIndAuto ");
            sPrintLnNbr(getIndAuto());
            sPrintStr("WifiConnected: ");
            sPrintLnNbr(WiFi.isConnected());
            sPrintStr("TxPower: ");
            sPrintNbr(WiFi.getTxPower());
            sPrintLnStr(" dBm");
            sPrintLnStr(wifiQuality());
            sPrintStr("IP address: ");
            Serial.println(WiFi.localIP());
            sPrintStr("timer ");
            sPrintNbr(getTimerHour());
            sPrintStr(":");
            sPrintNbr(getTimerMinute());
            sPrintStr(":");
            sPrintLnNbr(getTimerSecound());
        }
    }

    indicatorsManagement(); /// Call the indicatorsManagement function to manage the indicators of the machine
    modeManagement();       /// Call the modeManagement function to manage the different modes of the machine (Auto and Manual)

    ////////////////////////////////////////////////////////////////////////////////////////
    /// WORKING BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    /**
     * @brief Flag to control the operation of the water pump
     *
     * If the water level is at the maximum, the water pump is turned off.
     * If the water level is at the minimum or there is an alarm, the water pump is turned on.
     * @note If the water level is at the maximum, the water pump is turned off.
     * @note If the water level is at the minimum or there is an alarm, the water pump is turned on.
     */
    if (getWaterMax()) /// If the water level is at the maximum turn off the water pump
    {
        BMB_FLAG = OFF;  /// Turn off the water pump
        setPumpWeb(OFF); /// Set the water pump to OFF in the web interface
    }
    else if (getWaterMin() || getAlarm())   /// If the water level is at the minimum or at the alarm level, turn on the water pump
    {
        BMB_FLAG = ON;  /// Turn on the water pump
    }
    /**
     * @brief Control of the operation of the water heater resistor
     *
     * If the water level is at the maximum, the water heater resistor is turned off.
     * If the water level is at the minimum or there is an alarm, the water heater resistor is turned on.
     * @note If the water level is at the maximum, the water heater resistor is turned off.
     * @note If the water level is at the minimum or there is an alarm, the water heater resistor is turned on. *
     */
    if (getWaterMax() || getWaterMin() || !getAlarm())  /// If the water level is at the maximum or min or is not at alarm lvl, turn ON the water heater resistor
    {
        RAQ_FLAG = ON;
    }
    else    /// If the water level is at the alarmlvl, turn OFF the water heater resistor
    {
        RAQ_FLAG = OFF;
    }

    /**
     * @brief BMB, RAQ, V_IN, V_OUT
     * BMB, RAQ, V_IN, V_OUT are variables that are used to control the operation of the machine.
     * BMB is used to control the operation of the water pump.
     * RAQ is used to control the operation of the water heater resistor.
     * V_IN is used to control the operation of the water inlet valve.
     * V_OUT is used to control the operation of the water outlet valve.
     * @note BMB is used to control the operation of the water pump.
     * @note RAQ is used to control the operation of the water heater resistor.
     * @note V_IN is used to control the operation of the water inlet valve.
     * @note V_OUT is used to control the operation of the water outlet valve.
     */
    /// If the water pump is on and the machine is in auto mode or the water pump is on in manual mode and the water level is not at the maximum, turn on the water pump
    bool BMB = (BMB_FLAG && getIndAuto() || getPumpWeb() && getManualMode()) && !getWaterMax(); 
    /// If the water heater resistor is on and the machine is in auto mode or the water heater resistor is on in manual mode and the alarm is not on, turn on the water heater resistor
    bool RAQ = (RAQ_FLAG && getIndAuto() && getTimerStatus() || getResistorWeb() && getManualMode()) && !getAlarm();
    /// If the water inlet valve is on and the machine is in auto mode or the water inlet valve is on in manual mode and the alarm is not on, turn on the water inlet valve
    bool V_IN = (RAQ_FLAG && getIndAuto() && getTimerStatus() || getValv_Water_InWeb() && getManualMode()) && !getAlarm();
    /// If the water outlet valve is on and the machine is in auto mode or the water outlet valve is on in manual mode and the alarm is not on, turn on the water outlet valve
    bool V_OUT = (RAQ_FLAG && getIndAuto() && getTimerStatus() || !getValv_Water_OutWeb() && getManualMode()) && !getAlarm();

    /**
     * @brief Set the Pump object to the BMB variable value
     * Set the Pump object to the BMB variable value.
     * @note Set the Pump object to the BMB variable value.
     */
    setPump(BMB);
    delay(10);
    /**
     * @brief Set the Resistor object to the RAQ variable value
     * Set the Resistor object to the RAQ variable value.
     * @note Set the Resistor object to the RAQ variable value.
     */
    setResistor(RAQ);
    delay(10);
    /**
     * @brief Set the Valve Water In object
     * Set the Valve Water In object to the V_IN variable value.
     * @note Set the Valve Water In object to the V_IN variable value.
     */
    setValveWaterIn(V_IN);
    delay(10);
    /**
     * @brief Set the Valve Water Out object
     * Set the Valve Water Out object to the V_OUT variable value.
     * @note Set the Valve Water Out object to the V_OUT variable value.
     */
    setValveWaterOut(!V_OUT);
    delay(10);
}