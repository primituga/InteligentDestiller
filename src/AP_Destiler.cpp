/**
 * @author Sérgio Carmo
 * @file AP_Destiler.cpp
 * @brief Application file for the MD project.
 * @version 1.0
 */

#include "AP.h"

/**
 * @brief Destiler function to operate the machine.
 *
 * This function controls the operation of the distillation machine by
 * managing water levels, indicators, and modes. It includes debugging
 * information and handles both automatic and manual modes of operation.
 */
void destiler()
{
    static bool IDDLE_FLAG = OFF;

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
            sPrintStr("getAutoMode ");
            sPrintLnNbr(getAutoMode());
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

    indicatorsManagement(); /**< Call to manage indicators */
    //modeManagement();       /**< Call to manage operation modes */
    if (getAutoMode() || getAutoModeWeb())
    {
        toggleAutoMode();
    }

    ////////////////////////////////////////////////////////////////////////////////////////
    /// WORKING BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////

    if (getAutoMode()) /**< Automatic mode operations */
    {
        waterManagementAuto(); /**< Call to manage water levels */

        if (getAutoMode() && getTimerStatus())
        {
            if (getWaterMax())
            {
                workingMax(); /**< Working when water level is max */
                IDDLE_FLAG = OFF;
            }
            else if (!getWaterMax() && !getAlarm())
            {
                workingMaxMin(); /**< Working within max and min water level */
                if (getWaterMin())
                {
                    workingMin(); /**< Working when water level is min */
                    IDDLE_FLAG = OFF;
                }
            }
            else if (getWaterMin())
            {
                workingMin(); /**< Working when water level is min */
                IDDLE_FLAG = OFF;
            }
            else if (getAlarm())
            {
                workingAlarm(); /**< Working when there is an alarm */
                IDDLE_FLAG = OFF;
            }
            else if (!IDDLE_FLAG)
            {
                workingIdle(); /**< Working in idle state */
                IDDLE_FLAG = ON;
            }
        }
        else if (!IDDLE_FLAG)
        {
            workingIdle(); /**< Working in idle state */
            IDDLE_FLAG = ON;
        }
    }
    else if (getManualMode()) /**< Manual mode operations */
    {
        waterManagementManual(); /**< Call to manage water levels */
        setTimer(OFF); /**< Stop Timer if AutoMode is OFF */

        if (getWaterMax())
        {
            setPump(OFF);
        }
        else if (!getWaterMax() && getAlarm())
        {
           setResistor(OFF);
        }
    }
    else
    {
        setTimer(OFF); /**< Stop Timer if AutoMode is OFF */
        workingOFF(); 
    }
}
