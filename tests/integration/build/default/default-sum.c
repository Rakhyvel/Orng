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
int64_t _339_main(void);

/* Function definitions */
int64_t _339_main(void) {
    int64_t _339_t0;
    struct0 _340_x;
    int64_t _339_t3;
    uint8_t _339_t5;
    int64_t _339_t2;
    int64_t _339_$retval;
    _339_t0 = 0;
    _340_x = (struct0) {.tag=0, ._0=_339_t0};
    _339_t3 = 0;
    _339_t5 = _340_x._0 == _339_t3;
    if (_339_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _339_t2 = 133;
    goto BB6;
BB7:
    _339_t2 = 0;
    goto BB6;
BB6:
    _339_$retval = _339_t2;
    return _339_$retval;
}

int main(void) {
  printf("%ld",_339_main());
  return 0;
}
