#include <stdio.h>


#include <kernel/tty.h>

int putchar(int ic) {
	char c = (char) ic;
	terminal_write(&c, sizeof(c));
	//terminal_putchar(c);
	// TODO: Implement stdio and the write system call.
	return ic;
}
