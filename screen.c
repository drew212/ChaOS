/* screen.h -- Utilities for writing characters to the screen
 *
 * ChaOS Kernel
 * Author - Drew Cross <mstngdrew212@gmail.com>
 */

#include "screen.h"

// VGA framebuffer starts at 0xB8000;
u16int *video_memory = (u16int *)0xB8000;

//Stores cursor position
u8int cursor_x = 0;
u8int cursor_y = 0;


static void scroll()
{
    // Get a space character with the default color atributes.
    u8int attributeByte = (0 << 4) | (15 & 0x0F); //(Black) | (White)
    u16int blank = 0x20 | (attributeByte << 8); // Space |

    // Row 25 is the end, this means we need to scroll up

    if(cursor_y >= 25)
    {
        // Move the current text chunk tha tmakes up the screen
        // back in the buffer by a line
        int i;
        for (i = 0*80; i < 24*80; i++)
        {
            video_memory[i] = video_memory[i+80];
        }
        for(i = 24*80; i < 25*80; i++)
        {
            video_memory[i] = blank;
        }
        // The cursor should now be on the last line.
        cursor_y = 24;
    }
}

static void move_cursor()
{
    //Screen is 80x25 -
    u16int cursorLocation = cursor_y * 80 + cursor_x;
    outb(0x3D4, 14);                    // Tell the VGA board we are setting the high cursor byte.
    outb(0x3D5, cursorLocation >> 8);   // Send the high cursor byte.
    outb(0x3D4, 15);                    // Tell the VGA board we are setting the low cursor byte.
    outb(0x3D5, cursorLocation);        // Send the low cursor byte.
}

void screen_clear()
{
    // Set attrByte
    u8int attributeByte = (0 << 4) | (15 & 0x0F);
    u16int blank = 0x20 | (attributeByte << 8);

    int i;
    for(i =0; i < 80*25; i++)
    {
        video_memory[i] = blank;
    }

    // Move hardware cursor to beginning
    cursor_x = 0;
    cursor_y = 0;
    move_cursor();
}

void screen_put(char c)
{
    u8int backColor = 0; //Black
    u8int foreColor = 15; //White

    //The lower of this is the foreground and the upper nyble is the background
    u8int attributeByte = (backColor << 4) | (foreColor & 0x0f); // This is the byte we send to the VGA board

    u16int attribute = attributeByte << 8;
    u16int *location;

    // Backspace handling
    if(c  == 0x08 && cursor_x) {
        cursor_x --;
    }
    // Tab handling
    else if(c == 0x09)
    {
        cursor_x = (cursor_x+8) & ~(8-1);
    }
    // Carriage return handling
    else if (c == '\r')
    {
        cursor_x = 0;
    }
    // Newline handling
    else if(c == '\n')
    {
        cursor_x = 0;
        cursor_y++;
    }
    // Other characters => output
    else if(c >= ' ')//TODO: Do i need a <= 'Z'
    {
        location = video_memory + (cursor_y*80 + cursor_x);
        *location = c | attribute;// Attribute was shifted left 8 bits, so we're setting the characeter 'c' to attribute
        cursor_x++;               // and we're setting that to location
    }


    // Check end of the screen
    if(cursor_x >= 80)
    {
        cursor_x = 0;
        cursor_y++;
    }
    // Scroll if necessary
    scroll();
    // Move hardware cursor
    move_cursor();
}

void screen_write(char * c)
{
    int i = 0;
    while(c[i])
    {
        screen_put(c[i++]);
    }
}
