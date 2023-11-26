/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _346_main(void);

/* Function definitions */
int64_t _346_main(void) {
    int64_t _347_x;
    int64_t* _347_y;
    int64_t** _347_z;
    int64_t _346_$retval;
    _347_x = 75;
    _347_y = &_347_x;
    _347_z = &_347_y;
    **_347_z = 75;
    _346_$retval = **_347_z;
    return _346_$retval;
}

int main(void) {
  printf("%ld",_346_main());
  return 0;
}
