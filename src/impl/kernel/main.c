#include "print.h"
#include "types.h"

void kernel_main() 
{
    // get cpu verdor
    char vendor_str[13];
    CPUID_vendor_string(vendor_str);

    print_clear();
    print_set_color(PRINT_COLOR_GREEN, PRINT_COLOR_BLACK);
    printf("                ************DeathOS 64 bit kernel************");
    print_set_color(PRINT_COLOR_WHITE, PRINT_COLOR_BLACK);
    printf("\n KERNEL V0.01");
    printf("\n CPU ");
    printf(vendor_str);
}