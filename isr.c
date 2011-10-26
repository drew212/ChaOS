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
