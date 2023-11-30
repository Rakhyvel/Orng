/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _555_main(void);

/* Function definitions */
int64_t _555_main(void) {
    int64_t _556_x;
    int64_t* _556_y;
    int64_t** _556_z;
    int64_t _555_$retval;
    _556_x = 75;
    _556_y = &_556_x;
    _556_z = &_556_y;
    **_556_z = 75;
    _555_$retval = **_556_z;
    return _555_$retval;
}

int main(void) {
  printf("%ld",_555_main());
  return 0;
}
