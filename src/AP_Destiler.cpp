#include "AP.h"

void destiler()
{
    static unsigned long previousTimer = 0;
    unsigned long currentTimer = millis();
    static bool IDDLE_FLAG = OFF;

    if (DEBUGlog) // Print debug information
    {
        if (millis() - previousTimer > 5000)
        {
            // digitalWrite(PIN_IND_ALARM, OFF);
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

    /************************************************************************/
    /* WORKING BLOCK                                                        */
    /************************************************************************/
    if (!getManualMode()) // If manual mode is off
    {
        if (getAutoMode() && timerStatus()) // If auto mode is on
        {
            if (getWaterMax()) // If water level is max
            {
                workingMax(); // Working when water level is max
                IDDLE_FLAG = OFF;
            }
            else if (!getWaterMax() && !getWaterAlarm()) // If water level is min
            {
                workingMaxMin(); // Working within max and min water level
                if (getWaterMin())
                {
                    workingMin(); // Working when water level is min
                    IDDLE_FLAG = OFF;
                }
            }
            else if (getWaterMin()) // If water level is min
            {
                workingMin();
                IDDLE_FLAG = OFF;
            }
            else if (getWaterAlarm()) // If water level is alarm
            {
                workingAlarm();
                IDDLE_FLAG = OFF;
            }
            else if (!IDDLE_FLAG)
            {
                workingIdle();
                IDDLE_FLAG = ON;
            }
        }
        else if (!IDDLE_FLAG)
        {
            workingIdle();
            IDDLE_FLAG = ON;
        }
    }
    else // If manual mode is on
    {
        if (getManualMode())
        {
            if (getWaterMax())
            {
                workingMax();
                IDDLE_FLAG = OFF;
            }
            else if (!getWaterMax() && !getWaterAlarm()) // If water level is min
            {
                workingMaxMin();
                if (getWaterMin())
                {
                    workingMin();
                    IDDLE_FLAG = OFF;
                }
            }
            else if (getWaterMin())
            {
                workingMin();
                IDDLE_FLAG = OFF;
            }
            else if (getWaterAlarm())
            {
                workingAlarm();
                IDDLE_FLAG = OFF;
            }
            else if (!IDDLE_FLAG)
            {
                workingIdle();
                IDDLE_FLAG = ON;
            }
        }
    }

    if (!getAutoMode())
        setTimer(OFF); // Stop Timer if AutoMode is OFF

    ////////////////////////////////////////////////////////////////////////
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
    if (getWaterMax())
    {
        setIndMax(ON);
    }
    else
    {
        setIndMax(OFF);
    }

    if (getWaterMin())
    {
        setIndMin(ON);
    }
    else
    {
        setIndMin(OFF);
    }

    if (getWaterAlarm())
    {
        setIndAlarm(ON);
    }
    else
    {
        setIndAlarm(OFF);
    }

    if (getManualMode())
    {
        setIndMan(ON);
    }
    else
    {
        setIndMan(OFF);
    }
}