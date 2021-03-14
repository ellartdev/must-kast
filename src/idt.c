#include <system.h>

struct idt_entry {
    uint16 base_low;
    uint16 sel;
    uint8 always0;
    uint8 flags;
    uint16 base_high;
} __attribute__((packed));

struct idt_pointer
{
    uint16 limit;
    uint32 base;
} __attribute__((packed));

/* Declare an IDT of 256 entries. Although we will only use the
*  first 32 entries in this tutorial, the rest exists as a bit
*  of a trap. If any undefined IDT entry is hit, it normally
*  will cause an "Unhandled Interrupt" exception. Any descriptor
*  for which the 'presence' bit is cleared (0) will generate an
*  "Unhandled Interrupt" exception */
struct idt_entry idt[256];
struct idt_pointer idtp;

/* This exists in 'start.asm', and is used to load our IDT */
extern void idt_load();

/* Use this function to set an entry in the IDT. Alot simpler
*  than twiddling with the GDT ;) */
void idt_set_gate(uint8 num, uint64 base, uint16 sel, uint8 flags) {
    /* We'll leave you to try and code this function: take the
    *  argument 'base' and split it up into a high and low 16-bits,
    *  storing them in idt[num].base_hi and base_lo. The rest of the
    *  fields that you must set in idt[num] are fairly self-
    *  explanatory when it comes to setup */
    idt[num].base_high = (base & 0xFFFF);
    idt[num].base_low = (base >> 16) & 0xFFFF;
    idt[num].sel = sel;
    idt[num].flags = flags;
    idt[num].always0 = 0;

}

/* Installs the IDT */
void idt_install() {
    /* Sets the special IDT pointer up, just like in 'gdt.c' */
    idtp.limit = (sizeof (struct idt_entry) * 256) - 1;
    idtp.base = &idt;

    /* Clear out the entire IDT, initializing it to zeros */
    memset(&idt, 0, sizeof(struct idt_entry) * 256);

    /* Add any new ISRs to the IDT here using idt_set_gate */

    /* Points the processor's internal register to the new IDT */
    idt_load();
}
