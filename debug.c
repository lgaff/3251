#include "debug.h"

#include <stdio.h>
#include <stdarg.h>

void debug_print(const char *fn, const int line, const char *str, ...) {
	printf("%s [%d]: ", fn, line);
	va_list args;
	va_start (args, str);
	vprintf(str, args);
	va_end(args);
	printf("\n");
}