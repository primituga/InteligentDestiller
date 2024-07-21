
// /************************************************************************/
// /* Initialize Serial Terminal                                           */
// /************************************************************************/

#include "OS.h"

void initFS()
{
  // Initialize SPIFFS
  if (!SPIFFS.begin(true))
  {
    sPrintLnStr("An Error has occurred while mounting SPIFFS");
    return;
  }
}
