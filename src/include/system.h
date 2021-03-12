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

#endif
