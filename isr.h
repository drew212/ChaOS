/* isr.h -- High level interrupt service routines and interrupt request handlers
 *
 * ChaOS Kernel
 * Author - Drew Cross
 */
#include "common.h"

typedef struct registers
{
    uint32_t ds;
    uint32_t edi, esi, esp, ebx, edx, ecx, eax;
    uint32_t int_no, err_code;
    uint32_t eip, cs, eflags, useresp, ss;
} registers_t;
