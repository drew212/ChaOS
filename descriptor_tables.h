/* GDT descriptor table
 * The packed attribute tells GCC not to change an of the alignment in the structure
 *
 * ChaOS Kernel
 * Author - Drew Cross <mstngdrew212@gmail.com>
 */

#ifndef __DESCRIPTOR_TABLES_H__
#define __DESCRIPTOR_TABLES_H__
struct gdt_entry_struct
{
    u16int limit_low;
    u16int base_low;
    u8int base_middle;
    u8int access;
    u8int granularity;
    u8int base_high;
} __attribute__((packed));
typedef struct gdt_entry_struct gdt_entry_t;

struct gdt_ptr_struct
{
    u16int limit;
    u32int base;
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

void init_descriptor_tables();

#endif //__DESCRIPTOR_TABLES_H__
