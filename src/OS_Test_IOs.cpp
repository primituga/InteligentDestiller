
#include "OS.h"
#define delayT 500

void test_IO()
{
	setIndMax(ON);//
	delay(delayT);
	writeOutputs();
	setIndMax(OFF);//
	delay(delayT);
	writeOutputs();
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
}