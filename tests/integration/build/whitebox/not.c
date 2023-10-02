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
    int64_t* _2_y;
    int64_t _1_t8;
    int64_t _1_$retval;
    _2_x = 0;
    _2_y = &_2_x;
    if (*_2_y == 1) {
        goto BB5;
    } else {
        goto BB1;
    }
BB5:
    _1_t8 = 10;
    goto BB4;
BB1:
    _1_t8 = 31;
BB4:
    _1_$retval = _1_t8;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
