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
int64_t _25_main(void);

/* Function definitions */
int64_t _25_main(void) {
    int64_t _25_t0;
    struct0 _26_x;
    int64_t _25_$retval;
    _25_t0 = 101;
    _26_x = (struct0) {.tag=0, ._0=_25_t0};
    _25_$retval = _26_x._0;
    return _25_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}
