/* Copyright (C) 2011 Drew Cross *
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


/* isr.c -- High level interrupt service routines and interrupt request handlers
 *
 * ChaOS Kernel
 * Author - Drew Cross
 */

#include "common.h"
#include "isr.h"
#include "screen.h"

//This gets called from the ASM interrupt handler
void isr_handler(registers_t regs)
{
    screen_write("Recieved interrupt: ");
    screen_write_dec(regs.int_no);
    screen_put('\n');
}
