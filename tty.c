
#include <stdbool.h>
#include <stddef.h>
#include <stdint.h>

#include "tty.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;

size_t strlen(const char* str) {
	size_t ret = 0;
	while (str[ret] != 0) { ret++; }
	return ret;
}

void make_tty(tty *t) {
	t->row = 0;
	t->column = 0;
	t->color = make_color(COLOR_LIGHT_GREY, COLOR_BLACK);
	t->buffer = (uint16_t*) 0xB8000;
	for (size_t y = 0; y < VGA_HEIGHT; y++) {
		for (size_t x = 0; x < VGA_WIDTH; x++) {
			const size_t index = y * VGA_WIDTH + x;
			t->buffer[index] = make_vgaentry(' ', t->color);
		}
	}
}

void tty_color_set(tty *t, uint8_t color) {
	t->color = color;
}

void tty_putpt(tty *t, char c, uint8_t color, size_t x, size_t y) {
	const size_t index = y * VGA_WIDTH + x;
	t->buffer[index] = make_vgaentry(c, color);
}

void tty_put(tty *t, char c) {
	if (c == '\n') {
		t->row++;
		t->column = 0;
	} else {
		tty_putpt(t, c, t->color, t->column, t->row);
		if (++t->column == VGA_WIDTH) {
			t->column = 0;
			if (++t->row == VGA_HEIGHT) {
				t->row = 0;
			}
		}
	}
}

void tty_putstr(tty *t, const char* data) {
	size_t datalen = strlen(data);
	for ( size_t i = 0; i < datalen; i++ ) {
		tty_put(t, data[i]);
	}
}
