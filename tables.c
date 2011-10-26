/* tables.c -- Global Descriptor Table
 *
 * ChaOS Kernel
 *
 * Written By:
 * Drew Cross <mstngdrew212@gmail.com>
 *
 */


struct gdt_entry {

} __attribute__((packed));

struct gdt_table_ptr {
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));
