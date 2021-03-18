#include <system.h>

int timer_ticks = 0;

/**
 * Timer handler
 * It increments timer_ticks variable every time the timer
 * fires. By default, timer fires 18.222 times per second.
*/
void timer_handler(struct regs *r) {
    timer_ticks++;

    /**
     * display message on screen every 18 clocks (approx. 1 sec)
    */
    if (timer_ticks % 18 == 0) {
        print_string("1 sec has passed.\n");
    }
}

// Setting up system clock by installing timer handler to IRQ0
void timer_install() {
    irq_install_handler(0, timer_handler);
}

// basically a delay function
void timer_wait(int ticks) {
    uint64 eticks;
    eticks = timer_ticks + ticks;
    while (timer_ticks < eticks);
}
