/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _559_main(void);

/* Function definitions */
int64_t _559_main(void) {
    int64_t _560_x;
    int64_t* _560_y;
    int64_t _559_$retval;
    _560_x = 4;
    _560_y = &_560_x;
    *_560_y = 28;
    _559_$retval = *_560_y;
    return _559_$retval;
}

int main(void) {
  printf("%ld",_559_main());
  return 0;
}
