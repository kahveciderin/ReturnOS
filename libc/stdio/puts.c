#include <kernel/tty.h>

int puts(const char* string) {
	return terminal_writestring(string);
}
