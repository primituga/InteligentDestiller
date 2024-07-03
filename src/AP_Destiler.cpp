#include "AP.h"

void destiler()
{
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (DEBUGlog)   // Print debug information
    {
        if (millis() - previousTimer > 5000)
        {
            //digitalWrite(PIN_IND_ALARM, OFF);
            previousTimer = millis();
            sPrintLnStr("  ");
            sPrintStr("getWaterMax ");
            sPrintLnNbr(getWaterMax());
            sPrintStr("getWaterMin ");
            sPrintLnNbr(getWaterMin());
            sPrintStr("getWaterAlarm ");
            sPrintLnNbr(getWaterAlarm());
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
            wifiQuality(WiFi.RSSI());
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
    
    ///////////////

    if (timerStatus() && getAutoMode() && !getWaterAlarm())
    {
        workingMax();
    }
    else if (!timerStatus())
    {
        workingIdle();
    }
    
    else if (!getWaterMin() && !getWaterAlarm() && getManualMode())
    {
        workingMax();
    }
    else if (getWaterMin())
    {
        workingMin();
    }
    else if (getWaterAlarm()){
        workingAlarm();
    }

    ///////////////
    if (!getManualMode())
    {
        toggleAutoMode();
    }
    else
    {
        setAutoMode(OFF);
    }

/************************************************************************/
/* INDICATORS BLOCK                                                     */
/************************************************************************/
    if (getWaterMax()){
        setIndMax(ON);
    } else {
        setIndMax(OFF);
    }

    if (getWaterMin()){
        setIndMin(ON);
    } else {
        setIndMin(OFF);
    }


    if (getWaterAlarm()){
        setIndAlarm(ON);
    } else {
        setIndAlarm(OFF);
    }


    if (getManualMode()){
        setIndMan(ON);
    } else {
        setIndMan(OFF);
    }
}