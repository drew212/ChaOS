/* tables.c -- Global Descriptor Table
 *
 * ChaOS Kernel
 *
 * Written By:
 * Drew Cross <mstngdrew212@gmail.com>
 *
 */
#include "common.h"

extern void set_gdt(u32int_t);

struct gdt_entry {

} __attribute__((packed));

struct gdt_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));

struct gdt_entry gdt[5];
struct gdt_ptr;

void gdt_flush();

// Initializes the descriptor tables
void init_descriptor_tables()
{
    init_gdt();
}

// Initializes the global descriptor table
void init_gdt()
{


}
