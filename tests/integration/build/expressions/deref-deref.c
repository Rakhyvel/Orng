/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _41_main(void);

/* Function definitions */
int64_t _41_main(void) {
    int64_t _42_x;
    int64_t* _42_y;
    int64_t** _42_z;
    int64_t _41_$retval;
    _42_x = 75;
    _42_y = &_42_x;
    _42_z = &_42_y;
    **_42_z = 75;
    _41_$retval = **_42_z;
    return _41_$retval;
}

int main(void) {
  printf("%ld",_41_main());
  return 0;
}
