
// Copyright (c) 2015 Connor Taffe <cpaynetaffe@gmail.com>

#ifndef IO_H_
#define IO_H_

#include "io/tty.h"
#include "string.h"

// global output tty
tty io_out;

void open(tty *t) {
	make_tty(t);
}

void print(const char *str) {
	tty_putstr(&io_out, str);
}

void set_color(enum vga_color fg, enum vga_color bg) {
	tty_color_set(&io_out, make_color(fg, bg));
}

void reset_color() {
	set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}

#endif // IO_H_
