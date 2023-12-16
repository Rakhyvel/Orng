/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _603_main(void);

/* Function definitions */
int64_t _603_main(void) {
    int64_t _604_x;
    int64_t* _604_y;
    int64_t** _604_z;
    int64_t _603_$retval;
    _604_x = 75;
    _604_y = &_604_x;
    _604_z = &_604_y;
    **_604_z = 75;
    _603_$retval = **_604_z;
    return _603_$retval;
}

int main(void) {
  printf("%ld",_603_main());
  return 0;
}
