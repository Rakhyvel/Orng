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
    };
} struct0;

/* Function forward definitions */
int64_t _236_main(void);

/* Function definitions */
int64_t _236_main(void) {
    int64_t _236_t0;
    struct0 _237_x;
    int64_t _236_t3;
    uint8_t _236_t5;
    uint8_t _236_t4;
    int64_t _236_t2;
    int64_t _236_$retval;
    _236_t0 = 0;
    _237_x = (struct0) {.tag=0, ._0=_236_t0};
    _236_t3 = 0;
    _236_t5 = _237_x._0 == _236_t3;
    if (_236_t5) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _236_t4 = 1;
    goto BB2;
BB9:
    _236_t4 = 0;
    goto BB2;
BB2:
    if (_236_t4) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _236_t2 = 133;
    goto BB6;
BB7:
    _236_t2 = 0;
    goto BB6;
BB6:
    _236_$retval = _236_t2;
    return _236_$retval;
}

int main(void) {
  printf("%ld",_236_main());
  return 0;
}
