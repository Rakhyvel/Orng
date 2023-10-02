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
    int64_t _3_x;
    int64_t _1_$retval;
    _3_x = 0;
BB1:
    if (_3_x < 10) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _3_x = _3_x + 1;
    _3_x = _3_x + 1;
    goto BB1;
BB6:
    _1_$retval = _3_x;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
