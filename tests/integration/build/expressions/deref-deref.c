/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _410_main(void);

/* Function definitions */
int64_t _410_main(void) {
    int64_t _411_x;
    int64_t* _411_y;
    int64_t** _411_z;
    int64_t _410_$retval;
    _411_x = 75;
    _411_y = &_411_x;
    _411_z = &_411_y;
    **_411_z = 75;
    _410_$retval = **_411_z;
    return _410_$retval;
}

int main(void) {
  printf("%ld",_410_main());
  return 0;
}
