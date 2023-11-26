/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _44_main(void);

/* Function definitions */
int64_t _44_main(void) {
    int64_t _45_x;
    int64_t* _45_y;
    int64_t _44_$retval;
    _45_x = 4;
    _45_y = &_45_x;
    *_45_y = 28;
    _44_$retval = *_45_y;
    return _44_$retval;
}

int main(void) {
  printf("%ld",_44_main());
  return 0;
}
