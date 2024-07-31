/**
 * @author Sérgio Carmo
 * @file MD_Timer.cpp
 * @brief Timer functions for the MD project
 * @version 1.0
 */
#include "MD.h"

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Functions
////////////////////////////////////////////////////////////////////////////////////////

bool flagTimerStatus = OFF; /// flag to timer status
static unsigned long previousTimer = 0;

/**
 * @brief Web Timer function to add, remove or reset the timer
 * 
 * @param op 
 * @param amount 
 * 
 * @note This function is called by the processor function in MD_Web_Handlers.cpp
 * @return long 
 */
long webTimer(String op, int16_t amount)
{
	unsigned long currentTimer = millis();
	static long tot = 0;
	/**
	 * @brief Construct a new if object to add, remove or reset the timer
	 * 
	 */
	if (op == "+")
	{
		switch (amount) /// case to add time
		{
		case 1: /// add 1 secound
			tot += 1000;
			break;

		case 5: /// add 5 secound
			tot += 5 * 1000;
			break;

		case 10: /// add 10 secound
			tot += 10 * 1000;
			break;

		case 60: /// add 1 minute
			tot += 60 * 1000;
			break;

		case 300: /// add 5 minutes
			tot += 5 * 60 * 1000;
			break;

		case 600: /// add 10 minutes
			tot += 10 * 60 * 1000;
			break;
		default:
			break;
		}
	}
	else if (op == "-")
	{
		switch (amount) /// case to remove time
		{
		case 1: /// remove 1 secound
			tot -= 1000;
			break;

		case 5: /// remove 5 secound
			tot -= 5 * 1000;
			break;

		case 10: /// remove 10 secound
			tot -= 10 * 1000;
			break;

		case 60: /// remove 1 minute
			tot -= 60 * 1000;
			break;

		case 300: /// remove 5 minutes
			tot -= 5 * 60 * 1000;
			break;

		case 600: /// remove 10 minutes
			tot -= 10 * 60 * 1000;
			break;
		default:
			break;
		}
	}
	else if (op == "=") //	case to reset timer
	{
		tot = 0; /// reset timer
	}

	///	running timer, every 1 secound, remove 1 secound
	if (currentTimer - previousTimer >= 1000)
	{
		previousTimer = currentTimer;
		if (flagTimerStatus == ON)
		{
			rem1s();
		}
		if (tot <= 0) /// stop timer when timer = 0s
		{
			setTimer(OFF);
			tot = 0;
		}
	}

	return tot;
}

/**
 * @brief Get the Timer Status object to get the timer status (ON/OFF)
 * @note This function is called by the processor function in AP_Destiller.cpp
 * @return true 
 * @return false 
 */
bool getTimerStatus()
{
	if (flagTimerStatus == ON)
		return ON;
	else
		return OFF;
}

/**
 * @brief Get the Timer Secound object to get the timer secound
 * 
 * @return int 
 */
int getTimerSecound()
{
	return (webTimer("*", 0) / 1000) % 60;
}

/**
 * @brief Get the Timer Minute object to get the timer minute
 * 
 * @return int 
 */
int getTimerMinute()
{
	return ((webTimer("*", 0) / 1000) / 60) % 60;
}

/**
 * @brief Get the Timer Hour object to get the timer hour
 * 
 * @return int 
 */
int getTimerHour()
{
	return ((webTimer("*", 0) / 1000) / 60) / 60;
}

/**
 * @brief Set the Timer object to set the timer status (ON/OFF)
 * 
 * @param stat 
 */
void setTimer(bool stat)
{
	if (stat == ON)
		flagTimerStatus = ON;
	else
		flagTimerStatus = OFF;
}

/**
 * @brief Add 1 secound to timer object to add 1 secound to timer
 * 
 */
void add1s()
{
	webTimer("+", 1);
}

/**
 * @brief Add 5 secounds to timer object to add 5 secounds to timer
 * 
 */
void add5s()
{
	webTimer("+", 5);
}

/**
 * @brief Add 10 secounds to timer object to add 10 secounds to timer
 * 
 */
void add10s()
{
	webTimer("+", 10);
}

/**
 * @brief Add 1 minute to timer object to add 1 minute to timer
 * 
 */
void add1m()
{
	webTimer("+", 60);
}

/**
 * @brief Add 5 minutes to timer object to add 5 minutes to timer
 * 
 */
void add5m()
{
	webTimer("+", 300);
}

/**
 * @brief Add 10 minutes to timer object to add 10 minutes to timer
 * 
 */
void add10m()
{
	webTimer("+", 600);
}

/**
 * @brief Remove 1 secound to timer object to remove 1 secound to timer
 * 
 */
void rem1s()
{
	webTimer("-", 1);
}

/**
 * @brief Remove 5 secounds to timer object to remove 5 secounds to timer
 * 
 */
void rem5s()
{
	webTimer("-", 5);
}

/**
 * @brief Remove 10 secounds to timer object to remove 10 secounds to timer
 * 
 */
void rem10s()
{
	webTimer("-", 10);
}

/**
 * @brief Remove 1 minute to timer object to remove 1 minute to timer
 * 
 */
void rem1m()
{
	webTimer("-", 60);
}

/**
 * @brief Remove 5 minutes to timer object to remove 5 minutes to timer
 * 
 */
void rem5m()
{
	webTimer("-", 300);
}

/**
 * @brief Remove 10 minutes to timer object to remove 10 minutes to timer
 * 
 */
void rem10m()
{
	webTimer("-", 600);
}

/**
 * @brief Reset Timer object to reset timer
 * 
 */
void resetTimer()
{
	webTimer("=", 0);
}