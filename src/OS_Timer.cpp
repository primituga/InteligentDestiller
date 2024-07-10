
#include "OS.h"

//****************************************************************************
// Timer Functions
//****************************************************************************

bool flagTimerStatus = OFF; // flag to timer status
static unsigned long previousTimer = 0;

// function to control the timer in the web page
long webTimer(String op, int16_t amount)
{
	unsigned long currentTimer = millis();
	static long tot = 0;
	if (op == "+")
	{
		switch (amount) // case to add time
		{
		case 1: // add 1 secound
			tot += 1000;
			break;

		case 5: // add 5 secound
			tot += 5 * 1000;
			break;

		case 10: // add 10 secound
			tot += 10 * 1000;
			break;

		case 60: // add 1 minute
			tot += 60 * 1000;
			break;

		case 300: // add 5 minutes
			tot += 5 * 60 * 1000;
			break;

		case 600: // add 10 minutes
			tot += 10 * 60 * 1000;
			break;
		default:
			break;
		}
	}
	else if (op == "-")
	{
		switch (amount) // case to remove time
		{
		case 1: // remove 1 secound
			tot -= 1000;
			break;

		case 5: // remove 5 secound
			tot -= 5 * 1000;
			break;

		case 10: // remove 10 secound
			tot -= 10 * 1000;
			break;

		case 60: // remove 1 minute
			tot -= 60 * 1000;
			break;

		case 300: // remove 5 minutes
			tot -= 5 * 60 * 1000;
			break;

		case 600: // remove 10 minutes
			tot -= 10 * 60 * 1000;
			break;
		default:
			break;
		}
	}
	else if (op == "=") //	case to reset timer
	{
		tot = 0; // reset timer
	}

	//	running timer, every 1 secound, remove 1 secound
	if (currentTimer - previousTimer >= 1000)
	{
		previousTimer = currentTimer;
		if (flagTimerStatus == ON)
		{
			rem1s();
		}
		if (tot <= 0) // stop timer when timer = 0s
		{
			setTimer(OFF);
			tot = 0;
		}
	}

	return tot;
}

// function to return timer status
bool getTimerStatus()
{
	if (flagTimerStatus == ON)
		return ON;
	else
		return OFF;
}

//get timer in secounds
int getTimerSecound()
{
	return (webTimer("*", 0) / 1000) % 60;
}

//get timer in minutes
int getTimerMinute()
{
	return ((webTimer("*", 0) / 1000) / 60) % 60;
}

//get timer in Hours
int getTimerHour()
{
	return ((webTimer("*", 0) / 1000) / 60) / 60;
}

// Start or stop the timer
void setTimer(bool stat)
{
	if (stat == ON)
		flagTimerStatus = ON;
	else
		flagTimerStatus = OFF;
}

void add1s()
{
	webTimer("+", 1);
}

void add5s()
{
	webTimer("+", 5);
}

void add10s()
{
	webTimer("+", 10);
}

void add1m()
{
	webTimer("+", 60);
}

void add5m()
{
	webTimer("+", 300);
}

void add10m()
{
	webTimer("+", 600);
}

void rem1s()
{
	webTimer("-", 1);
}

void rem5s()
{
	webTimer("-", 5);
}

void rem10s()
{
	webTimer("-", 10);
}

void rem1m()
{
	webTimer("-", 60);
}

void rem5m()
{
	webTimer("-", 300);
}

void rem10m()
{
	webTimer("-", 600);
}

void resetTimer()
{
	webTimer("=", 0);
}