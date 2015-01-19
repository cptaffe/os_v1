
#include "tty.h"

// global output tty
tty io_out;

void open(tty *t) {
	make_tty(t);
}

void print(const char *str) {
	tty_putstr(&io_out, str);
}

int strcmp(const char *str, const char *ostr) {
	for (int i = 0; str[i] != 0 && ostr[i] != 0; i++) {
		if (str[i] != ostr[i]) {
			return 0;
		}
	}
	return 1;
}

void set_color(enum vga_color fg, enum vga_color bg) {
	tty_color_set(&io_out, make_color(fg, bg));
}

void reset_color() {
	set_color(COLOR_LIGHT_GREY, COLOR_BLACK);
}
