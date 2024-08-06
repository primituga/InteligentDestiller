/**
 * @author Sérgio Carmo
 * @file MD_Serial.cpp
 * @brief Serial functions for the MD project
 * @version 1.0
 */

////////////////////////////////////////////////////////////////////////////////////////
/// Initialize Serial Terminal
////////////////////////////////////////////////////////////////////////////////////////

#include "MD.h"

/**
 * @brief Initialize Serial Communications with the default baud rate of 9600 bps
 * 
 * @note This function is used to initialize the Serial Communications with the default baud rate of 9600 bps
 * @note This function is called in the setup() function of the main program
 * @note This function is used to print the initial message to the Serial Terminal
 */
void initSerial()
{
	Serial.begin(9600);	/// Initialize Serial Communications with the default baud rate of 9600 bps

	sPrintLnStr(" 			   ░▒▓██▓▒░");
	sPrintLnStr(" ");
	sPrintLnStr("	╔════════════════════════════╗");
	sPrintLnStr("	║                            ║");
	sPrintLnStr("	║      ESTG-Portalegre       ║");
	sPrintLnStr("	║                            ║");
	sPrintLnStr("	║     Distiller Machine      ║");
	sPrintLnStr("	║                            ║");
	sPrintLnStr("	║    Sergio Carmo N.19749    ║");
	sPrintLnStr("	║                            ║");
	sPrintLnStr("	╚════════════════════════════╝");
	sPrintLnStr(" ");
}

////////////////////////////////////////////////////////////////////////////////////////
/// Serial Print Functions
////////////////////////////////////////////////////////////////////////////////////////
/**
 * @brief Print a string to the Serial Terminal
 * @param abc 
 * @note This function is used to print a string to the Serial Terminal with no line break
 */
void sPrint(char *abc)
{
	Serial.print(abc);
}

/**
 * @brief Print a string to the Serial Terminal with a line break
 * @param abc 
 * @note This function is used to print a string to the Serial Terminal with a line break
 */
void sPrintLn(char *abc)
{
	Serial.println(abc);
}

/**
 * @brief Print a string to the Serial Terminal
 * @param abc 
 * @note This function is used to print a string to the Serial Terminal with no line break
 */
void sPrintStr(String abc)
{
	Serial.print(abc);
}

/**
 * @brief Print a string to the Serial Terminal with a line break
 * @param abc 
 * @note This function is used to print a string to the Serial Terminal with a line break
 */
void sPrintLnStr(String abc)
{
	Serial.println(abc);
}

/**
 * @brief Print a number to the Serial Terminal
 * @param nbr 
 * @note This function is used to print a number to the Serial Terminal with no line break
 */
void sPrintNbr(int nbr)
{
	Serial.print(nbr);
}

/**
 * @brief Print a number to the Serial Terminal with a line break
 * @param nbr 
 * @note This function is used to print a number to the Serial Terminal with a line break
 */
void sPrintLnNbr(int nbr)
{
	Serial.println(nbr);
}
