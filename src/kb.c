#include <system.h>
#include <kb.h>

/* Handles the keyboard interrupt */
void keyboard_handler(struct regs *r) {
    uint8 scancode;

    /* Read from the keyboard's data buffer */
    scancode = inportb(0x60);

    /* If the top bit of the byte we read from the keyboard is
    *  set, that means that a key has just been released */
    if (scancode & 0x80) {
        /* You can use this one to see if the user released the
        *  shift, alt, or control keys... */
    } else {
        /* Here, a key was just pressed. Please note that if you
        *  hold a key down, you will get repeated key press
        *  interrupts. */

        uint8 key = kbdus[scancode];

        /* Just to show you how this works, we simply translate
        *  the keyboard scancode into an ASCII value, and then
        *  display it to the screen. You can get creative and
        *  use some flags to see if a shift is pressed and use a
        *  different layout, or you can add another 128 entries
        *  to the above layout to correspond to 'shift' being
        *  held. If shift is held using the larger lookup table,
        *  you would add 128 to the scancode when you look for it */
        print_ch(key);
        uint8 cur_cmd[128];

        char tmp[] = {key, '\0'};

        if (scancode != 0x1C) // Enter key
            strcat((char*)cur_cmd, tmp);

        if (key == '\n') {
            if (strcmp((const char*)cur_cmd, "help") == 0)
                print_string((uint8*)"I'm helpless like you are, human behind electronic device.\n");
            else {
                print_string("You typed: "); print_string(cur_cmd); print_string("\n");
            }
            memset(cur_cmd, 0, sizeof cur_cmd);
        }
    }
}

void kb_install() {
    irq_install_handler(1, keyboard_handler);
}
