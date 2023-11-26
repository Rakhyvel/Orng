/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _34_main(void);

/* Function definitions */
int64_t _34_main(void) {
    int64_t _35_x;
    uint8_t _34_t4;
    uint8_t _34_t3;
    int64_t _34_$retval;
    _35_x = 2;
    _34_t4 = 1;
    if (_34_t4) {
        goto BB1;
    } else {
        goto BB11;
    }
BB1:
    _34_t3 = 1;
    goto BB2;
BB11:
    _34_t3 = 0;
    goto BB2;
BB2:
    if (_34_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _35_x = 4;
    _35_x = 14;
    _35_x = 24;
    _35_x = 34;
    goto BB9;
BB9:
    _34_$retval = _35_x;
    return _34_$retval;
}

int main(void) {
  printf("%ld",_34_main());
  return 0;
}
