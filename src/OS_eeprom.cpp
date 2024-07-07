#include "OS.h"

//================================================================
//====================== EEPROM necessary functions ==============
//================================================================

void writeEEPROM(int startAdr, int length, char *writeString)
{
    EEPROM.begin(eepromBufferSize);
    yield();
    for (int i = 0; i < length; i++)
        EEPROM.write(startAdr + i, writeString[i]);
    EEPROM.commit();
    EEPROM.end();
}

//========================================== readEEPROM 
void readEEPROM(int startAdr, int maxLength, char *dest)
{
    EEPROM.begin(eepromBufferSize);
    delay(10);
    for (int i = 0; i < maxLength; i++)
        dest[i] = char(EEPROM.read(startAdr + i));
    dest[maxLength - 1] = 0;
    EEPROM.end();
}

//========================================== writeDefaultSettingsToEEPPROM
void saveSettingsToEEPPROM(char *ssid_, char *pass_)
{
    if (DEBUG)
        Serial.println("\n============ saveSettingsToEEPPROM");
    writeEEPROM(1 * eepromTextVariableSize, eepromTextVariableSize, ssid_);
    writeEEPROM(2 * eepromTextVariableSize, eepromTextVariableSize, pass_);
}
//========================================== readSettingsFromEeprom
void readSettingsFromEEPROM(char *ssid_, char *pass_)
{
    readEEPROM(1 * eepromTextVariableSize, eepromTextVariableSize, ssid_);
    readEEPROM((2 * eepromTextVariableSize), eepromTextVariableSize, pass_);

    if (DEBUG){
        Serial.println("\n============ readSettingsFromEEPROM");
        Serial.print("\n============ ssid=");
        Serial.println(ssid_);
        Serial.print("============ password=");
        Serial.println(pass_);
    }
}

//================================================================ writeEepromSsid
void saveStatusToEeprom(byte value)
{
    EEPROM.begin(eepromBufferSize);
    EEPROM.write(0, value);
    EEPROM.commit();
    EEPROM.end();
}
//================================================================ getStatusFromEeprom
byte getStatusFromEeprom()
{
    EEPROM.begin(eepromBufferSize);
    byte value = 0;
    value = EEPROM.read(0);
    EEPROM.end();
    return value;
}