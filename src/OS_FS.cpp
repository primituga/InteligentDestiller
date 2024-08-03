/**
 * @file OS_FS.cpp
 * @author Sérgio Carmo (19749@ipportalegre.pt)
 * @brief  File System functions
 * @version 0.1
 *
 */

#include "OS.h"

////////////////////////////////////////////////////////////////////////////////////////
/// Initialize Serial Terminal
////////////////////////////////////////////////////////////////////////////////////////

/**
 * @brief Function to initiate the Serial Terminal
 * 
 * @return void
 */
void initFS()
{
  /// Initialize SPIFFS
  if (!SPIFFS.begin(true))
  {
    sPrintLnStr("An Error has occurred while mounting SPIFFS");
    return;
  }
}