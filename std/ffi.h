#ifndef ORNG_STD_FFI
#define ORNG_STD_FFI

#include <stdlib.h>
#include <stdbool.h>

inline bool ptr_is_null(void *ptr)
{
    return ptr == NULL;
}

inline void *ref_from_ptr_helper(void *ptr)
{
    return ptr;
}

#endif