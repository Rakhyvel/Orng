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
int64_t _32_main(void);

/* Function definitions */
int64_t _32_main(void) {
    int64_t _32_t0;
    struct0 _33_x;
    int64_t _32_$retval;
    _32_t0 = 101;
    _33_x = (struct0) {.tag=0, ._0=_32_t0};
    _32_$retval = _33_x._0;
    return _32_$retval;
}

int main(void) {
  printf("%ld",_32_main());
  return 0;
}
