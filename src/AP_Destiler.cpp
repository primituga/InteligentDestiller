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
     * BMB_FLAG is used to control the operation of the machine when the water level is above the maximum level.
     * RAQ_FLAG is used to control the operation of the machine when the water level is below the minimum level.
     * @note BMB_FLAG and RAQ_FLAG are used to control the operation of the machine.
     * @note BMB_FLAG is used to control the operation of the machine when the water level is above the maximum level.
     * @note RAQ_FLAG is used to control the operation of the machine when the water level is below the minimum level.
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

    indicatorsManagement(); /**< Call to manage indicators */
    modeManagement();       /**< Call to manage operation modes */

    ////////////////////////////////////////////////////////////////////////////////////////
    /// WORKING BLOCK
    ////////////////////////////////////////////////////////////////////////////////////////
    if (getWaterMax())
    {
        BMB_FLAG = OFF;
    }
    else if (getWaterMin() || getAlarm())
    {
        BMB_FLAG = ON;
    }

    if (getWaterMax() || getWaterMin() || !getAlarm())
    {
        RAQ_FLAG = ON;
    }
    else
    {
        RAQ_FLAG = OFF;
    }

    bool BMB = (BMB_FLAG && getIndAuto() || getPumpWeb() && getManualMode());

    bool RAQ = (RAQ_FLAG && getIndAuto() && getTimerStatus() || getResistorWeb() && getManualMode() && !getAlarm());

    bool V_IN = (RAQ_FLAG && getIndAuto() && getTimerStatus() || getValv_Water_InWeb() && getManualMode() && !getAlarm());

    bool V_OUT = (RAQ_FLAG && getIndAuto() && getTimerStatus() || getValv_Water_OutWeb() && getManualMode() && !getAlarm());

    setPump(BMB);
    setResistor(RAQ);
    setValveWaterIn(V_IN);
    setValveWaterOut(V_OUT);
}
