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
    int64_t _1_t3;
    int64_t _1_$retval;
    if (0.0e+00) {
        goto BB7;
    } else {
        goto BB3;
    }
BB7:
    _1_t3 = 0;
    goto BB6;
BB3:
    _1_t3 = 135;
BB6:
    _1_$retval = _1_t3;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
