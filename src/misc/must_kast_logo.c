#include <system.h>
/**
 * KERNEL LOGO
 * Before launching must_kast_logo(), console / video must be initalized with init_video()
*/
void must_kast_logo() {
    /**
     * output:
     * ================================================================================ (BRIGHT_RED, BLACK)
     * |                                                                              | (BRIGHT_RED, BLACK)
     * |       8b    d8 88   88 .dP"Y8 888888     88  dP    db    .dP"Y8 888888       | (BRIGHT_RED, BLACK)
     * |       88b  d88 88   88 `Ybo."   88       88odP    dPYb   `Ybo."   88         | (BRIGHT_MAGENTA, BLACK)
     * |      88YbdP88 Y8   8P o.`Y8b   88       88"Yb   dP__Yb  o.`Y8b   88          | (BRIGHT_BLUE, BLACK)
     * |      88 YY 88 `YbodP' 8bodP'   88       88  Yb dP""""Yb 8bodP'   88          | (BLUE, BLACK)
     * |                                                                              | (BLUE, BLACK)
     * ====== made by ellartdev ======================================================= (BLUE, BLACK)
    */
    set_color(BRIGHT_RED, BLACK); print_string("================================================================================");
    print_string("|                                                                              |");
    print_string("|       8b    d8 88   88 .dP\"Y8 888888     88  dP    db    .dP\"Y8 888888       |");
    set_color(BRIGHT_MAGENTA, BLACK); print_string("|       88b  d88 88   88 `Ybo.\"   88       88odP    dPYb   `Ybo.\"   88         |");
    set_color(BRIGHT_BLUE, BLACK); print_string("|      88YbdP88 Y8   8P o.`Y8b   88       88\"Yb   dP__Yb  o.`Y8b   88          |");
    set_color(BLUE, BLACK); print_string("|      88 YY 88 `YbodP' 8bodP'   88       88  Yb dP\"\"\"\"Yb 8bodP'   88          |");
    print_string("|                                                                              |");
    print_string("====== made by ellartdev =======================================================\n\n"); set_color(WHITE, BLACK);
}
