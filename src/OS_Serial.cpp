
// /************************************************************************/
// /* Initialize Serial Terminal                                           */
// /************************************************************************/

#include "OS.h"

void initSerial()
{ // Initialize Serial Communications
	Serial.begin(9600);

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

//************************************************************************
// Serial Print Functions
//************************************************************************

void sPrint(char *abc)
{
	Serial.print(abc);
}

void sPrintLn(char *abc)
{
	Serial.println(abc);
}

void sPrintStr(String abc)
{
	Serial.print(abc);
}

void sPrintLnStr(String abc)
{
	Serial.println(abc);
}

void sPrintNbr(int nbr)
{
	Serial.print(nbr);
}

void sPrintLnNbr(int nbr)
{
	Serial.println(nbr);
}
