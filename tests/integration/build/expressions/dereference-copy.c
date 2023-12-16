/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _606_main(void);

/* Function definitions */
int64_t _606_main(void) {
    int64_t _607_x;
    int64_t* _607_y;
    int64_t _606_$retval;
    _607_x = 4;
    _607_y = &_607_x;
    *_607_y = 28;
    _606_$retval = *_607_y;
    return _606_$retval;
}

int main(void) {
  printf("%ld",_606_main());
  return 0;
}
