#pragma once
#include <stddef.h>
#include <stdint.h>
#include "typedefs.h"
extern void terminal_writestring(const char* data); 
extern void terminal_write(const char* data, size_t size); 
extern void terminal_putchar(char c);
extern void terminal_putentryat(char c, uint8_t color, size_t x, size_t y);
extern void terminal_setcolor(uint8_t color);
extern void terminal_initialize(void);
static inline uint8_t vga_entry_color(enum vga_color fg, enum vga_color bg) 
{
	return fg | bg << 4;
}
 
static inline uint16_t vga_entry(unsigned char uc, uint8_t color) 
{
	return (uint16_t) uc | (uint16_t) color << 8;
}
#define VGA_WIDTH 80
#define VGA_HEIGHT 25