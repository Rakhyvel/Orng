/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t _1_$retval;
    _2_x = 17;
BB1:
    if (_2_x < 36) {
        goto BB2;
    } else {
        goto BB11;
    }
BB2:
    if (_2_x % 2) {
        goto BB8;
    } else {
        goto BB4;
    }
BB11:
    _1_$retval = _2_x;
    return _1_$retval;
BB8:
    _2_x = _2_x + 1;
BB4:
    _2_x = _2_x + 9;
    goto BB1;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
