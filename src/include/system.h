#ifndef __SYSTEM_H
#define __SYSTEM_H

// types
typedef unsigned char uint8;
typedef unsigned short uint16;
typedef unsigned int uint32;
typedef unsigned long uint64;

/* MAIN.C */
extern void *memcpy(void *dest, const void *src, int count);
extern void *memset(void *dest, char val, int count);
extern uint16 *memsetw(uint16 *dest, uint16 val, int count);
extern int strlen(const char *str);
extern uint8 inportb(uint16 _port);
extern void outportb(uint16 _port, uint8 _data);

// SCREEN.C
extern void scroll_screen(void);
extern void move_cursor(void);
extern void cls();
extern void print_ch(uint8 c);
extern void print_string(uint8 *str);
extern void set_color(uint8 fg, uint8 bg);
extern void init_video(void);

// colors
enum vga_color {
    BLACK,
    BLUE,
    GREEN,
    CYAN,
    RED,
    MAGENTA,
    BROWN,
    GREY,
    DARK_GREY,
    BRIGHT_BLUE,
    BRIGHT_GREEN,
    BRIGHT_CYAN,
    BRIGHT_RED,
    BRIGHT_MAGENTA,
    YELLOW,
    WHITE,
};

// Global Descriptor Table
extern void gdt_set_gate(int num, uint64 base, uint64 limit, uint8 access, uint8 gran);
extern void gdt_install();

// Interrupt Descriptor Table
extern void idt_set_gate(uint8 num, uint64 base, uint16 sel, uint8 flags);
extern void idt_install();

// Interrupt Service Routines
/* This defines what the stack looks like after an ISR was running */
struct regs {
    uint32 gs, fs, es, ds;      /* pushed the segs last */
    uint32 edi, esi, ebp, esp, ebx, edx, ecx, eax;  /* pushed by 'pusha' */
    uint32 int_no, err_code;    /* our 'push byte #' and ecodes do this */
    uint32 eip, cs, eflags, useresp, ss;   /* pushed by the processor automatically */ 
};

extern void isrs_install();
extern void fault_handler(struct regs *r);

// Interrupt Requests
extern void irq_install();
extern void irq_install_handler(int irq, void (*handler)(struct regs *r));
extern void irq_uninstall_handler(int irq);

// System Clock
extern void timer_install();
extern void timer_wait(int ticks);

// kernel logo
extern void must_kast_logo();

#endif
