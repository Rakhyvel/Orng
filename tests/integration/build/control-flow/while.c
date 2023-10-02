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
    int64_t _3_i;
    int64_t _1_$retval;
    _2_x = 0;
    _3_i = 0;
BB1:
    if (_3_i <= 10) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _2_x = _2_x + _3_i;
    _3_i = _3_i + 1;
    goto BB1;
BB7:
    _1_$retval = _2_x;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
