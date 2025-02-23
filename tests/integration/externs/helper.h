#ifndef EXTERNS_HELPER_H
#define EXTERNS_HELPER_H

#include <stdarg.h>
#include <stdint.h>

// Needed until we get the ffi module in the std library
inline static char *printf_wrapper(uint8_t *fmt, ...)
{
    va_list args;
    va_start(args, (char *)fmt);
    vprintf((char *)fmt, args);
    va_end(args);
}

#endif