/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_t1;
    int64_t _1_$retval;
    if (0.0e+00) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1_t1 = 0;
    goto BB4;
BB1:
    _1_t1 = 132;
BB4:
    _1_$retval = _1_t1;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
