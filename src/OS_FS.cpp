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
 * @brief Initialize File System (SPIFFS)
 * 
 * This function is responsible for initializing the File System (SPIFFS).
 * 
 * @note Initialize SPIFFS
 * 
 * @return void
 * 
 * @code 
 * initFS();
 * @endcode
 * 
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