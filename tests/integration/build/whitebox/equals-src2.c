/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1120_main(void);

/* Function definitions */
int64_t _1120_main(void) {
    uint8_t _1120_t4;
    uint8_t _1120_t3;
    int64_t _1120_t2;
    int64_t _1120_$retval;
    _1120_t4 = 1;
    if (_1120_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1120_t3 = 1;
    goto BB2;
BB9:
    _1120_t3 = 0;
    goto BB2;
BB2:
    if (_1120_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1120_t2 = 42;
    goto BB6;
BB7:
    _1120_t2 = 10434;
    goto BB6;
BB6:
    _1120_$retval = _1120_t2;
    return _1120_$retval;
}

int main(void) {
  printf("%ld",_1120_main());
  return 0;
}
