/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _372_main(void);

/* Function definitions */
int64_t _372_main(void) {
    uint8_t _372_t4;
    uint8_t _372_t3;
    int64_t _372_t2;
    int64_t _372_$retval;
    _372_t4 = 1;
    if (_372_t4) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _372_t3 = 1;
    goto BB2;
BB9:
    _372_t3 = 0;
    goto BB2;
BB2:
    if (_372_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _372_t2 = 208;
    goto BB6;
BB7:
    _372_t2 = -4;
    goto BB6;
BB6:
    _372_$retval = _372_t2;
    return _372_$retval;
}

int main(void) {
  printf("%ld",_372_main());
  return 0;
}
