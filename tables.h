#ifndef __TABLES_H__
#define __TABLES_H__

#include "common.h"

struct gdt_entry
{
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t granularity;
    uint8_t base_high;
} __attribute__((packed));
typedef struct gdt_entry gdt_entry_t;

struct gdt_ptr
{
    unsigned short limit;
    unsigned int base;
} __attribute__((packed));
typedef struct gdt_ptr gdt_ptr_t;

static void init_gdt();
static void init_descriptor_tables();
static void gdt_set_entry(int32_t num, uint32_t base, uint32_t limit, uint8_t access, uint8_t granularity);
extern void setgdt(uint32_t);

//////////////////IDT ENTRIES/////////////////////

struct idt_entry
{
    uint16_t base_low;
    uint16_t select;
    uint8_t zero;
    uint8_t flags;
    uint16_t base_high;
} __attribute__((packed));
typedef struct idt_entry idt_entry_t;


struct idt_ptr
{
    uint16_t limit;
    uint32_t base;
} __attribute__((packed));
typedef struct idt_ptr idt_ptr_t;

extern void isr0();
extern void isr31();

extern void set_idt(uint32_t);

static void init_idt();
static void idt_set_entry(uint8_t num, uint32_t base, uint16_t select, uint8_t flags);
#endif //__TABLES_H__
