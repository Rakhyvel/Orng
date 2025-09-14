#ifndef EXTERNS_HELPER_H
#define EXTERNS_HELPER_H

#include <stdarg.h>
#include <stdint.h>

typedef struct Some_Type
{
    int64_t x;
    int64_t y;
} Some_Type;

// Needed until we get the ffi module in the std library
inline static int
printf_wrapper(uint8_t *fmt, ...)
{
    va_list args;
    va_start(args, (char *)fmt);
    int retval = vprintf((char *)fmt, args);
    va_end(args);
    return retval;
}

inline static Some_Type construct_some_type(int64_t x, int64_t y)
{
    Some_Type retval = {x, y};
    return retval;
}

inline static int64_t sum(Some_Type st)
{
    return st.x + st.y;
}

#endif