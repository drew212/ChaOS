/* screen.h -- Utilities for writing characters to the screen
 *
 * ChaOS Kernel
 * Author - Drew Cross <mstngdrew212@gmail.com>
 */
#ifndef SCREEN_H
#define SCREEN_H

#include "common.h"

// Write a character to the screen
void screen_put(char c);

// Clears the screen to all black
void screen_clear();

// Outputs a string to the monitor
void screen_write(char * c);

#endif // SCREEN_H
