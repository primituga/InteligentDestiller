/**
 * @file MD_Web_IO_Mngmnt.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief
 * @version 0.1
 */
#include "MD.h"

uint8_t outputVarsImageWeb[9]; /// Output variables image

////////////////////////////////////////////////////////////////////////////////////////
/// SETS BLOCK
////////////////////////////////////////////////////////////////////////////////////////

void setAutoModeWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_IND_AUTO] = ON;
        if (DEBUG)
            sPrintLnStr("setAutoMode ON Web");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_IND_AUTO] = OFF;
        if (DEBUG)
            sPrintLnStr("setAutoMode OFF Web");
        OLDSTATE = state;
    }
}

void setPumpWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_BMB] = ON;
        if (DEBUG)
            sPrintLnStr("setPump ON Web");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_BMB] = OFF;
        if (DEBUG)
            sPrintLnStr("setPump OFF Web");
        OLDSTATE = state;
    }
}

void setValveWaterInWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn ON Web");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_IN] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterIn OFF Web");
        OLDSTATE = state;
    }
}

void setValveWaterOutWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = ON;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut ON Web");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_VALV_WATER_OUT] = OFF;
        if (DEBUG)
            sPrintLnStr("setValveWaterOut OFF Web");
        OLDSTATE = state;
    }
}

void setResistorWeb(bool state)
{
    static bool OLDSTATE;
    if (state == ON && OLDSTATE == OFF)
    {
        outputVarsImageWeb[POS_RAQ] = ON;
        if (DEBUG)
            sPrintLnStr("setResistor ON Web");
        OLDSTATE = state;
    }
    else if (state == OFF && OLDSTATE == ON)
    {
        outputVarsImageWeb[POS_RAQ] = OFF;
        if (DEBUG)
            sPrintLnStr("setResistor OFF Web");
        OLDSTATE = state;
    }
}
