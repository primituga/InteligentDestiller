/**
 * @file MD_Test_IOs.cpp
 * @brief Test I/Os for the MD project
 * @version 1.0
 */
#include "MD.h"
#define delayT 500

void test_IO()
{
	bool isDEBUGON = false;
	Serial.println("Test I/Os ...");
	if (DEBUG)
	{
		DEBUG = false;
		isDEBUGON = true;
	}

	// Test I/O Indicador Maximo
	Serial.print("Indicador Maximo ... ");
	setIndMax(ON);//
	delay(delayT);
	writeOutputs();
	setIndMax(OFF);//
	delay(delayT);
	writeOutputs();
	Serial.print("OK");

	setIndMin(ON);//
	delay(delayT);
	writeOutputs();
	setIndMin(OFF);//
	delay(delayT);
	writeOutputs();
	setIndAlarm(ON);//
	delay(1000);
	writeOutputs();
	setIndAlarm(OFF);//
	delay(1000);
	writeOutputs();
	//setIndMan(ON);//
	//delay(delayT);
	//writeOutputs();
	//setIndMan(OFF);//
	delay(delayT);
	writeOutputs();
	setAutoMode(ON);//
	delay(delayT);
	writeOutputs();
	setAutoMode(OFF);//
	delay(delayT);
	writeOutputs();
	setValveWaterIn(ON);//
	delay(delayT);
	writeOutputs();
	setValveWaterIn(OFF);//
	delay(delayT);
	writeOutputs();
	setValveWaterOut(ON);//
	delay(delayT);
	writeOutputs();
	setValveWaterOut(OFF);//
	delay(delayT);
	writeOutputs();
	setResistor(ON);//
	delay(delayT);
	writeOutputs();
	setResistor(OFF);//
	delay(delayT);
	writeOutputs();
	
	//setPump(ON);
	//delay(delayT);
	//setPump(OFF);
	//delay(delayT);

	if (isDEBUGON)
	{
		DEBUG = true;
	}
}