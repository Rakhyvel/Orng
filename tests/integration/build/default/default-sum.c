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
int64_t _424_main(void);

/* Function definitions */
int64_t _424_main(void) {
    int64_t _424_t0;
    struct0 _425_x;
    int64_t _424_t3;
    uint8_t _424_t5;
    int64_t _424_t2;
    int64_t _424_$retval;
    _424_t0 = 0;
    _425_x = (struct0) {.tag=0, ._0=_424_t0};
    _424_t3 = 0;
    _424_t5 = _425_x._0 == _424_t3;
    if (_424_t5) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _424_t2 = 133;
    goto BB6;
BB7:
    _424_t2 = 0;
    goto BB6;
BB6:
    _424_$retval = _424_t2;
    return _424_$retval;
}

int main(void) {
  printf("%ld",_424_main());
  return 0;
}
