int draw_gui(char *elements[], uint8_t selection){
    vga_entry_color(VGA_COLOR_RED, VGA_COLOR_RED)
    terminal_row = 0; terminal_column = 0;

    for(uint8_t i = 0; i < VGA_WIDTH; i++){
        terminal_putchar(" ");
    }
}