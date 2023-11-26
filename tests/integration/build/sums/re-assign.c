/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef struct {
    uint64_t tag;
    union {
        int64_t _0;
        uint8_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _31_main(void);

/* Function definitions */
int64_t _31_main(void) {
    int64_t _31_t0;
    struct0 _32_x;
    int64_t _31_$retval;
    _31_t0 = 4;
    _32_x = (struct0) {.tag=0, ._0=_31_t0};
    _32_x._0 = 103;
    _31_$retval = _32_x._0;
    return _31_$retval;
}

int main(void) {
  printf("%ld",_31_main());
  return 0;
}
