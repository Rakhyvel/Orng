/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _449_main(void);

/* Function definitions */
int64_t _449_main(void) {
    int64_t _450_x;
    int64_t* _450_y;
    int64_t** _450_z;
    int64_t _449_$retval;
    _450_x = 75;
    _450_y = &_450_x;
    _450_z = &_450_y;
    **_450_z = 75;
    _449_$retval = **_450_z;
    return _449_$retval;
}

int main(void) {
  printf("%ld",_449_main());
  return 0;
}
