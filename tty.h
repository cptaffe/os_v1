
// Copyright (c) 2015 Connor Taffe <cpaynetaffe@gmail.com>

#ifndef TTY_H_
#define TTY_H_

// text mode color constants
enum vga_color {
	COLOR_BLACK = 0,
	COLOR_BLUE = 1,
	COLOR_GREEN = 2,
	COLOR_CYAN = 3,
	COLOR_RED = 4,
	COLOR_MAGENTA = 5,
	COLOR_BROWN = 6,
	COLOR_LIGHT_GREY = 7,
	COLOR_DARK_GREY = 8,
	COLOR_LIGHT_BLUE = 9,
	COLOR_LIGHT_GREEN = 10,
	COLOR_LIGHT_CYAN = 11,
	COLOR_LIGHT_RED = 12,
	COLOR_LIGHT_MAGENTA = 13,
	COLOR_LIGHT_BROWN = 14,
	COLOR_WHITE = 15,
};

// tty construct
typedef struct {
	size_t row;
	size_t column;
	uint8_t color;
	uint16_t *buffer;
} tty;

void make_tty(tty *t);

void tty_color_set(tty *t, uint8_t c);
void tty_put_pt(tty *t, char c, uint8_t color, size_t x, size_t y);
void tty_put(tty *t, char c);
void tty_putstr(tty *t, const char *str);

static inline uint8_t make_color(enum vga_color fg, enum vga_color bg) {
	return fg | bg << 4;
}

static inline uint16_t make_vgaentry(char c, uint8_t color) {
	uint16_t c16 = c;
	uint16_t color16 = color;
	return c16 | color16 << 8;
}

#endif // TTY_H_
