/**
 * @author Sérgio Carmo
 * @file OS_eeprom.cpp
 * @brief Operating System EEPROM functions
 * @version 1.0
 */

#include "OS.h"

////////////////////////////////////////////////////////////////////////////////////////
/// EEPROM necessary functions
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Write to EEPROM
 *
 * @param startAdr
 * @param length
 * @param writeString
 * @return void
 */
void writeEEPROM(int startAdr, int length, char *writeString)
{
    EEPROM.begin(eepromBufferSize);                 /// Initialize EEPROM
    yield();                                        /// Yield to allow ESP32 background functions to run
    for (int i = 0; i < length; i++)                /// Write to EEPROM memory address from startAdr to startAdr + length with writeString content
        EEPROM.write(startAdr + i, writeString[i]); /// Write to EEPROM memory address from startAdr to startAdr + length with writeString content
    EEPROM.commit();                                /// Commit the write to EEPROM memory address from startAdr to startAdr + length with writeString content
    EEPROM.end();                                   /// End the EEPROM write operation and release the EEPROM memory address from startAdr to startAdr + length with writeString content
}

/**
 * @brief Read from EEPROM
 *
 * @param startAdr
 * @param maxLength
 * @param dest
 * @return void
 */
void readEEPROM(int startAdr, int maxLength, char *dest)
{
    EEPROM.begin(eepromBufferSize);                /// Initialize EEPROM memory address from startAdr to startAdr + maxLength
    delay(10);                                     /// Delay 10ms
    for (int i = 0; i < maxLength; i++)            /// Read from EEPROM memory address from startAdr to startAdr + maxLength and store in dest variable
        dest[i] = char(EEPROM.read(startAdr + i)); /// Read from EEPROM memory address from startAdr to startAdr + maxLength and store in dest variable
    dest[maxLength - 1] = 0;                       /// Set the last character of dest variable to 0
    EEPROM.end();                                  /// End the EEPROM read operation and release the EEPROM memory address from startAdr to startAdr + maxLength with dest content
}

/**
 * @brief Save settings to EEPROM
 *
 * @param ssid_
 * @param pass_
 * @return void
 */
void saveSettingsToEEPPROM(char *ssid_, char *pass_)
{
    if (DEBUG)
        Serial.println("\n============ saveSettingsToEEPPROM");
    writeEEPROM(1 * eepromTextVariableSize, eepromTextVariableSize, ssid_); /// Write to EEPROM memory address from 1 * eepromTextVariableSize to eepromTextVariableSize with ssid_ content
    writeEEPROM(2 * eepromTextVariableSize, eepromTextVariableSize, pass_); /// Write to EEPROM memory address from 2 * eepromTextVariableSize to eepromTextVariableSize with pass_ content
}

/**
 * @brief Read settings from EEPROM
 *
 * @param ssid_
 * @param pass_
 * @return void
 */
void readSettingsFromEEPROM(char *ssid_, char *pass_)
{
    readEEPROM(1 * eepromTextVariableSize, eepromTextVariableSize, ssid_);
    readEEPROM((2 * eepromTextVariableSize), eepromTextVariableSize, pass_);

    if (DEBUG)
    {
        Serial.println("\n============ readSettingsFromEEPROM");
        Serial.print("\n============ ssid= ");
        Serial.println(ssid_);
        Serial.print("============ password= ");
        Serial.println(pass_);
    }
}

/**
 * @brief Save status to EEPROM
 *
 * @param value
 * @return void
 */
void saveStatusToEeprom(byte value)
{
    EEPROM.begin(eepromBufferSize);
    EEPROM.write(0, value);
    EEPROM.commit();
    EEPROM.end();
}

/**
 * @brief Get status from EEPROM
 *
 * @return byte
 */
byte getStatusFromEeprom()
{
    EEPROM.begin(eepromBufferSize);
    byte value = 0;
    value = EEPROM.read(0);
    EEPROM.end();
    return value;
}