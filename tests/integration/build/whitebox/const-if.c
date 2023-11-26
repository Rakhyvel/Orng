/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1114_main(void);

/* Function definitions */
int64_t _1114_main(void) {
    uint8_t _1114_t4;
    uint8_t _1114_t3;
    int64_t _1114_t0;
    int64_t _1114_$retval;
    _1114_t4 = 1;
    if (_1114_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1114_t3 = 1;
    goto BB2;
BB9:
    _1114_t3 = 0;
    goto BB2;
BB2:
    if (_1114_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1114_t0 = 107;
    goto BB6;
BB7:
    _1114_t0 = 4;
    goto BB6;
BB6:
    _1114_$retval = _1114_t0;
    return _1114_$retval;
}

int main(void) {
  printf("%ld",_1114_main());
  return 0;
}
