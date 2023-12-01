/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _54_main(void);

/* Function definitions */
int64_t _54_main(void) {
    int64_t _55_x;
    int64_t* _55_y;
    int64_t _54_$retval;
    _55_x = 242;
    _55_y = &_55_x;
    _54_$retval = *_55_y;
    return _54_$retval;
}

int main(void) {
  printf("%ld",_54_main());
  return 0;
}
