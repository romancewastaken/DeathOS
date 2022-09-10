#include "print.h"

void kernel_main() 
{
    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    printf("                ************DeathOS 64 bit kernel************");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    printf("\n KERNEL V0.01");
}
