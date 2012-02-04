/* screen.h Screen I/O functions header file
 *
 * This work is licensed under the Creative Commons Attribution-NonCommercial-
 * ShareAlike 3.0 Unported License. To view a copy of this license, visit
 * http://creativecommons.org/licenses/by-nc-sa/3.0/ or send a letter to:
 * Creative Commons
 * 444 Castro Street, Suite 900
 * Mountain View, California, 94041, USA.
 *
 * Author(s): Drew Cross <drew@ddcross.com>
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
