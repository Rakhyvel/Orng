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
        double _1;
    };
} struct0;

/* Function forward definitions */
int64_t _303_main(void);

/* Function definitions */
int64_t _303_main(void) {
    int64_t _303_t0;
    struct0 _304_x;
    int64_t _303_$retval;
    _303_t0 = 139;
    _304_x = (struct0) {.tag=0, ._0=_303_t0};
    _303_$retval = _304_x._0;
    return _303_$retval;
}

int main(void) {
  printf("%ld",_303_main());
  return 0;
}
