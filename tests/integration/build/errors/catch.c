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
        uint32_t _1;
    };
} struct0;

/* Function forward definitions */
int64_t _2_main(void);

/* Function definitions */
int64_t _2_main(void) {
    uint32_t _2_t0;
    struct0 _3_x;
    uint64_t _2_t3;
    int64_t _2_t2;
    int64_t _2_$retval;
    _2_t0 = 100;
    _3_x = (struct0) {.tag=1, ._1=_2_t0};
    _2_t3 = 1;
    if (_2_t3) {
        goto BB1;
    } else {
        goto BB4;
    }
BB1:
    _2_t2 = 118;
    goto BB3;
BB4:
    _2_t2 = _3_x._0;
    goto BB3;
BB3:
    _2_$retval = _2_t2;
    return _2_$retval;
}

int main(void) {
  printf("%ld",_2_main());
  return 0;
}
