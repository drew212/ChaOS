/* descriptor_talbes.h - GDT descriptor table header file
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
// The packed attribute tells GCC not to change an
// of the alignment in the structure

struct gdt_ptr_struct
{
    u16int limit;
    u32int base;
} __attribute__((packed));
typedef struct gdt_ptr_struct gdt_ptr_t;

void init_descriptor_tables();
