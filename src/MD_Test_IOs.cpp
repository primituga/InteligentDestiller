/**
 * @author Sérgio Carmo
 * @file MD_Test_IOs.cpp
 * @brief Test I/Os for the MD project
 * @version 1.0
 */
#include "MD.h"
#define delayT 500	/// Delay time for testing I/Os 

/**
 * @brief Test I/Os
 * 
 * @return void
 */
void test_IO()
{
	bool isDEBUGON = false;
	Serial.println("Test I/Os ...");
	if (DEBUG)	
	{
		DEBUG = false;
		isDEBUGON = true;
	}

	///  Test I/O Indicador Maximo
	Serial.print("Indicador Maximo ... ");
	setIndMax(ON);/// 
	delay(delayT);
	writeOutputs();
	setIndMax(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");

	///  Test I/O Indicador Minimo
	Serial.print("Indicador Minimo ... ");
	setIndMin(ON);/// 
	delay(delayT);
	writeOutputs();
	setIndMin(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");

	///  Test I/O Indicador Alarme
	Serial.print("Indicador Alarme ... ");
	setIndAlarm(ON);/// 
	delay(1000);
	writeOutputs();
	setIndAlarm(OFF);/// 
	delay(1000);
	writeOutputs();
	Serial.println("OK");
	
	///  Test I/O Indicador Manual
	Serial.print("Indicador Manual ... ");
	setIndMan(ON);/// 
	delay(delayT);
	writeOutputs();
	setIndMan(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");
	
	///  Test I/O Indicador Auto
	Serial.print("Indicador Auto ... ");
	setIndAuto(ON);/// 
	delay(delayT);
	writeOutputs();
	setIndAuto(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");

	///  Test I/O Indicador Valvula Entrada
	Serial.print("Indicador Valvula Entrada ... ");
	setValveWaterIn(ON);/// 
	delay(delayT);
	writeOutputs();
	setValveWaterIn(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");

	///  Test I/O Indicador Valvula Saida
	Serial.print("Indicador Valvula Saida ... ");
	setValveWaterOut(ON);/// 
	delay(delayT);
	writeOutputs();
	setValveWaterOut(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");

	///  Test I/O Indicador Resistor
	Serial.print("Indicador Resistor ... ");
	setResistor(ON);/// 
	delay(delayT);
	writeOutputs();
	setResistor(OFF);/// 
	delay(delayT);
	writeOutputs();
	Serial.println("OK");
	
	/*
	///  Test I/O Indicador Bomba
	Serial.print("Indicador Bomba ... ");
	setPump(ON);///
	delay(delayT);
	writeOutputs();
	setPump(OFF);///
	delay(delayT);
	writeOutputs();
	Serial.println("OK");*/

	if (isDEBUGON)
	{
		DEBUG = true;
	}
}