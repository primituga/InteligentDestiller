#include "AP.h"

void destiler()
{
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();

    if (DEBUGlog)
    {
        if (millis() - previousTimer > 5000)
        {
            digitalWrite(PIN_IND_ALARM, OFF);
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
        }
    }
    
    ///////////////
    if ((getWaterMax() || !getWaterMin() || !getWaterAlarm()) && getManualMode())
    {
        setIndMax(ON);
        setResistor(ON);
        setPump(OFF);
        //setValveWaterIn(ON);
        //setValveWaterOut(ON);
    }
    else
    {
        setIndMax(OFF);
    }
    ///////////////
    if (getWaterMin())
    {
        setIndMin(ON);
        setPump(ON);
        //setValveWaterIn(ON);
        //setValveWaterOut(ON);
    }
    else
    {
        setIndMin(OFF);
    }
    ///////////////
    if (getWaterAlarm())
    {
        setIndAlarm(ON);
        setResistor(OFF);
        setPump(ON);
        //setValveWaterIn(OFF);
        //setValveWaterOut(OFF);
    }
    else
    {
        setIndAlarm(OFF);
    }
    ///////////////
    if (getManualMode())
    {
        setIndMan(ON);
    }
    else
    {
        setIndMan(OFF);
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
}