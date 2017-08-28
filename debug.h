#pragma once

#ifdef _DEBUG
#define DEBUG(...) debug_print ( __FILE__, __LINE__, __VA_ARGS__)
extern void debug_print(const char *fn, const int line, const char *str, ...);
#else
#define DEBUG(...)
#endif