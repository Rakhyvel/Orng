/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _67_main(void);

/* Function definitions */
int64_t _67_main(void) {
    uint8_t _67_t4;
    uint8_t _67_t3;
    int64_t _67_t2;
    int64_t _67_$retval;
    _67_t4 = 1;
    if (_67_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _67_t3 = 1;
    goto BB2;
BB9:
    _67_t3 = 0;
    goto BB2;
BB2:
    if (_67_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _67_t2 = 208;
    goto BB6;
BB7:
    _67_t2 = -4;
    goto BB6;
BB6:
    _67_$retval = _67_t2;
    return _67_$retval;
}

int main(void) {
  printf("%ld",_67_main());
  return 0;
}
