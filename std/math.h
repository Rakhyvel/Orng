#ifndef ORNG_STD_MATH
#define ORNG_STD_MATH

#include <stdlib.h>
#include <stdbool.h>

inline int64_t truncate_float(double x)
{
    return (int64_t)x;
}

inline double as_float_helper(int64_t x)
{
    return (double)x;
}

#endif
