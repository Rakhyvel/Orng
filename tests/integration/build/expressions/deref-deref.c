/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _578_main(void);

/* Function definitions */
int64_t _578_main(void) {
    int64_t _579_x;
    int64_t* _579_y;
    int64_t** _579_z;
    int64_t _578_$retval;
    _579_x = 75;
    _579_y = &_579_x;
    _579_z = &_579_y;
    **_579_z = 75;
    _578_$retval = **_579_z;
    return _578_$retval;
}

int main(void) {
  printf("%ld",_578_main());
  return 0;
}
