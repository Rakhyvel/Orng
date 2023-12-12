/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _418_main(void);

/* Function definitions */
int64_t _418_main(void) {
    int64_t _419_x;
    int64_t* _419_y;
    int64_t** _419_z;
    int64_t _418_$retval;
    _419_x = 75;
    _419_y = &_419_x;
    _419_z = &_419_y;
    **_419_z = 75;
    _418_$retval = **_419_z;
    return _418_$retval;
}

int main(void) {
  printf("%ld",_418_main());
  return 0;
}
