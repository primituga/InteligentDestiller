#include "MD.h"

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Functions
////////////////////////////////////////////////////////////////////////////////////////

bool flagTimerStatus = OFF; /// flag to timer status
static unsigned long previousTimer = 0;
static unsigned long lastUpdateSent = 0;
const unsigned long updateInterval = 1000; // Send updates every second

/**
 * @brief Send timer to web
 *
 * This function sends the timer to the web interface to update the timer display in the web interface.
 *
 * @note This function is called by the webTimer function in MD_Timer.cpp
 */
void sendTimer()
{
  static int old_minute, old_hour, old_second, old_timerStat; /// Old values to compare with the new values to send updates only when the timer changes

  /// Only send updates if the timer has changed
  if (old_minute == getTimerMinute() && old_hour == getTimerHour() && old_second == getTimerSecound() && old_timerStat == getTimerStatus())
  {
    return;
  }

  /// Send the timer to the web interface
  String message = "{\"type\": \"timer\", \"hour\": " + String(getTimerHour()) +
                   ", \"minute\": " + String(getTimerMinute()) +
                   ", \"second\": " + String(getTimerSecound()) +
                   ", \"timerStat\": " + String(getTimerStatus()) + "}"; /// Create the message to send to the web interface as a JSON object
  /// Send the message to the web interface
  ws.textAll(message);

  /// Update the old values
  old_minute = getTimerMinute();
  old_hour = getTimerHour();
  old_second = getTimerSecound();
  old_timerStat = getTimerStatus();
}

/**
 * @brief Web timer function to manage the timer operations in the web interface
 *
 * This function is responsible for managing the timer operations.
 *
 * @param op
 * @param amount
 * @return unsigned long
 */
long webTimer(String op, int16_t amount)
{
  unsigned long currentTimer = millis();
  static long tot = 0;

  /// Timer operations to add, remove or reset the timer value in miliseconds
  if (op == "+") /// Add time to the timer
  {
    switch (amount)
    {
    case 1: /// Add 1 second
      tot += 1000;
      break;
    case 5: /// Add 5 seconds
      tot += 5000;
      break;
    case 10: /// Add 10 seconds
      tot += 10000;
      break;
    case 60: /// Add 1 minute
      tot += 60000;
      break;
    case 300: /// Add 5 minutes
      tot += 300000;
      break;
    case 600: /// Add 10 minutes
      tot += 600000;
      break;
    default:
      break;
    }
  }
  else if (op == "-") /// Remove time from the timer
  {
    switch (amount)
    {
    case 1: /// Remove 1 second
      tot -= 1000;
      break;
    case 5: /// Remove 5 seconds
      tot -= 5000;
      break;
    case 10: /// Remove 10 seconds
      tot -= 10000;
      break;
    case 60: /// Remove 1 minute
      tot -= 60000;
      break;
    case 300: /// Remove 5 minutes
      tot -= 300000;
      break;
    case 600: /// Remove 10 minutes
      tot -= 600000;
      break;
    default:
      break;
    }
  }
  else if (op == "=") /// Reset the timer to 0
  {
    tot = 0;
  }

  /// Timer management to decrease the timer every second and turn it off when it reaches 0 seconds left
  if (currentTimer - previousTimer >= 1000)
  {
    previousTimer = currentTimer;
    /// Decrease the timer every second if the timer is ON
    if (flagTimerStatus == ON)
    {
      tot -= 1000;
    }
    if (tot <= 0) /// Turn off the timer when it reaches 0 seconds left 
    {
      setTimer(OFF);
      tot = 0;
    }
  }

  /// Only send updates at the defined interval
  if (currentTimer - lastUpdateSent >= updateInterval)
  {
    lastUpdateSent = currentTimer;  
    sendTimer();  /// Send the timer to the web interface
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
  return flagTimerStatus; /// Return the timer status (ON/OFF)
}

/**
 * @brief Get the Timer Secound object to get the timer secound
 *
 * @return int
 */
int getTimerSecound()
{
  return (webTimer("*", 0) / 1000) % 60;  /// Return the timer seconds left in the timer  
}

/**
 * @brief Get the Timer Minute object to get the timer minute
 *
 * @return int
 */
int getTimerMinute()
{
  return ((webTimer("*", 0) / 1000) / 60) % 60; /// Return the timer minutes left in the timer
}

/**
 * @brief Get the Timer Hour object to get the timer hour
 *
 * @return int
 */
int getTimerHour()
{
  return ((webTimer("*", 0) / 1000) / 60) / 60; /// Return the timer hours left in the timer
}

/**
 * @brief Set the Timer object to set the timer status (ON/OFF)
 *
 * @param stat
 */
void setTimer(bool stat)
{ /// Set the timer status (ON/OFF)
  if (stat == ON)
  {
    flagTimerStatus = ON;
  }
  else if (stat == OFF)
  {
    flagTimerStatus = OFF;
  }
  sendTimer();
}

/**
 * @brief Add 1 secound to timer
 */
void add1s() { webTimer("+", 1); }
/**
 * @brief Add 5 secounds to timer
 */
void add5s() { webTimer("+", 5); }
/**
 * @brief Add 10 secounds to timer
 */
void add10s() { webTimer("+", 10); }
/**
 * @brief Add 1 minute to timer
 */
void add1m() { webTimer("+", 60); }
/**
 * @brief Add 5 minutes to timer
 */
void add5m() { webTimer("+", 300); }
/**
 * @brief Add 10 minutes to timer
 */
void add10m() { webTimer("+", 600); }
/**
 * @brief Remove 1 secound from timer
 */
void rem1s() { webTimer("-", 1); }
/**
 * @brief Remove 5 secounds from timer
 */
void rem5s() { webTimer("-", 5); }
/**
 * @brief Remove 10 secounds from timer
 */
void rem10s() { webTimer("-", 10); }
/**
 * @brief Remove 1 minute from timer
 */
void rem1m() { webTimer("-", 60); }
/**
 * @brief Remove 5 minutes from timer
 */
void rem5m() { webTimer("-", 300); }
/**
 * @brief Remove 10 minutes from timer
 */
void rem10m() { webTimer("-", 600); }
/**
 * @brief Reset timer
 */
void resetTimer() { webTimer("=", 0); }
