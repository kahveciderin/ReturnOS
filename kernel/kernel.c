#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>
#include <stdarg.h>
#include "gui.h"
#include "vga.h"
char *menu_elements[3] = {"Terminal", "Calculator", "Web Browser"};

void kernel_main(void) 
{
	
	/* Initialize terminal interface */
	terminal_initialize();
 
	/* Newline support is left as an exercise. */
	//terminal_writestring("haha no\nno");
	draw_gui(menu_elements, 1);
}