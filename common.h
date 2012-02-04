/* common.h -- Typedefs and global functions
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

#ifndef COMMON_H
#define COMMON_H

typedef unsigned int    u32int;
typedef          int    s32int;
typedef unsigned short  u16int;
typedef          short  s16int;
typedef unsigned char   u8int;
typedef          char   s8int;


void outb(u16int port, u8int value);
u8int inb(u16int port);
u16int inw(u16int port);

#endif

