
#include "string.h"

size_t strlen(const char* str) {
	size_t ret = 0;
	while (str[ret] != 0) { ret++; }
	return ret;
}

int strcmp(const char *str, const char *ostr) {
	for (int i = 0; str[i] != 0 && ostr[i] != 0; i++) {
		if (str[i] != ostr[i]) {
			return 0;
		}
	}
	return 1;
}
