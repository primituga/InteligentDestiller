#include "MD.h"

////////////////////////////////////////////////////////////////////////////////////////
/// Timer Functions
////////////////////////////////////////////////////////////////////////////////////////

bool flagTimerStatus = OFF; /// flag to timer status
static unsigned long previousTimer = 0;
static unsigned long lastUpdateSent = 0;
const unsigned long updateInterval = 1000; // Send updates every second

void sendTimer()
{
  static int old_minute, old_hour, old_second, old_timerStat;
  if (old_minute == getTimerMinute() && old_hour == getTimerHour() && old_second == getTimerSecound() && old_timerStat == getTimerStatus())
  {
    return;
  }
  String message = "{\"type\": \"timer\", \"hour\": " + String(getTimerHour()) +
                   ", \"minute\": " + String(getTimerMinute()) +
                   ", \"second\": " + String(getTimerSecound()) +
                   ", \"timerStat\": " + String(getTimerStatus()) + "}";
  ws.textAll(message);
  old_minute = getTimerMinute();
  old_hour = getTimerHour();
  old_second = getTimerSecound();
  old_timerStat = getTimerStatus();
}

long webTimer(String op, int16_t amount)
{
  unsigned long currentTimer = millis();
  static long tot = 0;

  if (op == "+")
  {
    switch (amount)
    {
    case 1:
      tot += 1000;
      break;
    case 5:
      tot += 5000;
      break;
    case 10:
      tot += 10000;
      break;
    case 60:
      tot += 60000;
      break;
    case 300:
      tot += 300000;
      break;
    case 600:
      tot += 600000;
      break;
    default:
      break;
    }
  }
  else if (op == "-")
  {
    switch (amount)
    {
    case 1:
      tot -= 1000;
      break;
    case 5:
      tot -= 5000;
      break;
    case 10:
      tot -= 10000;
      break;
    case 60:
      tot -= 60000;
      break;
    case 300:
      tot -= 300000;
      break;
    case 600:
      tot -= 600000;
      break;
    default:
      break;
    }
  }
  else if (op == "=")
  {
    tot = 0;
  }

  if (currentTimer - previousTimer >= 1000)
  {
    previousTimer = currentTimer;
    if (flagTimerStatus == ON)
    {
      tot -= 1000;
    }
    if (tot <= 0)
    {
      setTimer(OFF);
      tot = 0;
    }
  }

  // Only send updates at the defined interval
  if (currentTimer - lastUpdateSent >= updateInterval)
  {
    lastUpdateSent = currentTimer;
    sendTimer();
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
  return flagTimerStatus;
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
  {
    flagTimerStatus = ON;
  }
  else if (stat == OFF)
  {
    flagTimerStatus = OFF;
  }
  sendTimer();
}

void add1s() { webTimer("+", 1); }
void add5s() { webTimer("+", 5); }
void add10s() { webTimer("+", 10); }
void add1m() { webTimer("+", 60); }
void add5m() { webTimer("+", 300); }
void add10m() { webTimer("+", 600); }
void rem1s() { webTimer("-", 1); }
void rem5s() { webTimer("-", 5); }
void rem10s() { webTimer("-", 10); }
void rem1m() { webTimer("-", 60); }
void rem5m() { webTimer("-", 300); }
void rem10m() { webTimer("-", 600); }
void resetTimer() { webTimer("=", 0); }
