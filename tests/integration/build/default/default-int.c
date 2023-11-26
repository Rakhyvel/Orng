/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _17_main(void);

/* Function definitions */
int64_t _17_main(void) {
    uint8_t _17_t4;
    uint8_t _17_t3;
    int64_t _17_t1;
    int64_t _17_$retval;
    _17_t4 = 1;
    if (_17_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _17_t3 = 1;
    goto BB2;
BB9:
    _17_t3 = 0;
    goto BB2;
BB2:
    if (_17_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _17_t1 = 131;
    goto BB6;
BB7:
    _17_t1 = 4;
    goto BB6;
BB6:
    _17_$retval = _17_t1;
    return _17_$retval;
}

int main(void) {
  printf("%ld",_17_main());
  return 0;
}
