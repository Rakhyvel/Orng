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
int64_t _28_main(void);

/* Function definitions */
int64_t _28_main(void) {
    int64_t _28_t0;
    struct0 _29_x;
    int64_t _28_$retval;
    _28_t0 = 104;
    _29_x = (struct0) {.tag=0, ._0=_28_t0};
    _28_$retval = _29_x._0;
    return _28_$retval;
}

int main(void) {
  printf("%ld",_28_main());
  return 0;
}
