/* Copyright (C) 2011 Drew Cross
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.}
 */


/* ChaOSKernel.h -- Main kernel file
 *
 * Author - Drew Cross <mstngdrew212@gmail.com>
 */

#include "ChaOSKernel.h"


void kmain( void* mbd, unsigned int magic )
{
    if ( magic != 0x2BADB002 )
    {
        /* Something went not according to specs. Print an error */
        /* message and halt, but do *not* rely on the multiboot */
        /* data structure. */
    }

    /* (http://www.gnu.org/software/grub/manual/multiboot/multiboot.html#multiboot_002eh) */
    char * boot_loader_name =(char*) ((long*)mbd)[16];
    if(*boot_loader_name == " ")
    {
        //TODO what is boot loader name?
    }
    /* Print a letter to screen to see everything is working: */
    /* Write your kernel here. */

    char * welcome = "\tWelcome to ChaOS OS! \n123456789\0";
    screen_clear();
    int i;
    screen_write(welcome);
}
//TODO: Test functionality
void kprint(char letter, int row, int col)
{
    int lineWidth = 80;
    //TODO: Prints each letter inputted to the correct locaiton on the screen
    unsigned char *videoram = (unsigned char *) 0xb8000;
    videoram[row  * lineWidth * 2 + col * 2] = letter;
}

void kscroll()
{
    //TODO: Scrolls all the characters up one removing the first line
}


//TODO: Doesn't clear the screen.
void kScreenClear()
{
    int lineWidth = 80;
    int numLines = 25;
    int x = 0;
    int y = 0;
    while(x < lineWidth)
    {
        while(y < numLines)
        {
            kprint(' ', x, y);
            y++;
        }
        y = 0;
        x++;
    }
}
