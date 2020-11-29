#include <stdio.h>

#include <kernel/tty.h>


void kernel_main(void) {
	terminal_initialize();
	printf("haha no %x aaaa\naaaaaaa\rbbb\nabcdabcd\b1", 12);

}
