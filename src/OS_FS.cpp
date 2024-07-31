/**
 * @author Sérgio Carmo
 * @brief Operating System File System functions
 * @version 1.0
 * @file OS_FS.cpp
 */

#include "OS.h"

////////////////////////////////////////////////////////////////////////////////////////
/// Initialize Serial Terminal
////////////////////////////////////////////////////////////////////////////////////////

void initFS()
{
  /// Initialize SPIFFS
  if (!SPIFFS.begin(true))
  {
    sPrintLnStr("An Error has occurred while mounting SPIFFS");
    return;
  }
}
