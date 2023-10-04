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
    int64_t _2_x;
    int64_t* _2_y;
    int64_t _1_$retval;
    int64_t _1_t2;
    _2_x = 3;
    _2_y = &_2_x;
    if (*_2_y != 5) {
        goto BB3;
    } else {
        goto BB12;
    }
BB3:
    if (*_2_y >= 3) {
        goto BB5;
    } else {
        goto BB9;
    }
BB12:
    if (4 > *_2_y) {
        goto BB3;
    } else {
        goto BB9;
    }
BB5:
    _1_t2 = 33;
    goto BB8;
BB9:
    _1_t2 = 10;
BB8:
    _1_$retval = _1_t2;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
