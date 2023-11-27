/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _383_main(void);

/* Function definitions */
int64_t _383_main(void) {
    int64_t _384_x;
    int64_t* _384_y;
    int64_t _383_$retval;
    _384_x = 29;
    _384_y = &_384_x;
    _383_$retval = *_384_y;
    return _383_$retval;
}

int main(void) {
  printf("%ld",_383_main());
  return 0;
}
