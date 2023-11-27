/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _3_main(void);

/* Function definitions */
int64_t _3_main(void) {
    int64_t _4_x;
    int64_t* _4_y;
    int64_t _3_$retval;
    _4_x = 242;
    _4_y = &_4_x;
    _3_$retval = *_4_y;
    return _3_$retval;
}

int main(void) {
  printf("%ld",_3_main());
  return 0;
}
