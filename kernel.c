
// Copyright (c) 2015 Connor Taffe <cpaynetaffe@gmail.com>

#if defined(__linux__)
#error "Cross compiler, bro."
#endif

#if !defined(__i386__)
#error "32 bit, bro."
#endif

#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "io/io.h"

// first tty, defined on the stack

void main() {
	open(&io_out);
	/* Since there is no support for newlines in terminal_putchar yet, \n will
	produce some VGA specific character instead. This is normal. */
	print("Hello, ");
	set_color(COLOR_RED, COLOR_BLACK);
	print("kernel");
	reset_color();
	print(" World!\n");
	print("Here is a new line.\n");
}
