#include <stdint.h>
#include <stddef.h>
#include "typedefs.h"
extern size_t terminal_row;
extern size_t terminal_column;
extern uint8_t terminal_color;
int draw_gui(char *elements[], uint8_t selection){
    terminal_color = vga_entry_color(VGA_COLOR_RED, VGA_COLOR_RED);
    terminal_row = 0; 
    terminal_column = 0;

    for(uint8_t i = 0; i < VGA_WIDTH; i++){
        terminal_putchar(" ");
    }
}