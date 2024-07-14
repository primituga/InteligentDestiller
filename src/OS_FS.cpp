
// /************************************************************************/
// /* Initialize Serial Terminal                                           */
// /************************************************************************/

#include "OS.h"

void initFS()
{
  // Initialize SPIFFS
  if (!SPIFFS.begin(true))
  {
    Serial.println("An Error has occurred while mounting SPIFFS");
    return;
  }
}
