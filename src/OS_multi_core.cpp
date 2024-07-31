/**
 * @file OS_multi_core.cpp
 * @brief Operating System MultiCore functions
 * @version 1.0
 */
#include "OS.h"

void initMultiCore()    // Function to initiate the 2nd core
{
    // Implements the 2nd core option to run 'loop2' function
    xTaskCreatePinnedToCore(
        loop2,   // Function to implement the task
        "loop2", // Name of the task
        10000,   // Stack size in words
        NULL,    // Task input parameter
        0,       // Priority of the task
        NULL,    // Task handle.
        0        // Core where the task should run
    );
}