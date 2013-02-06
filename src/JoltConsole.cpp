/* 
 * File:   JoltConsole.cpp
 * Author: cyberkitsune
 * 
 * Created on February 4, 2013, 7:41 PM
 */

#include <stdio.h>
#include <stdarg.h>

#include "JoltConsole.h"

JoltConsole::JoltConsole() {
}

void JoltConsole::logInfo(const char* module, const char* message, ...) {
    printf("[Jolt%s] ",module);
    va_list args;
    va_start(args, message);
    vprintf(message, args);
    va_end(args);
    printf("\n");
}