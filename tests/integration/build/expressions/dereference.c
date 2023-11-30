/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _564_main(void);

/* Function definitions */
int64_t _564_main(void) {
    int64_t _565_x;
    int64_t* _565_y;
    int64_t _564_$retval;
    _565_x = 29;
    _565_y = &_565_x;
    _564_$retval = *_565_y;
    return _564_$retval;
}

int main(void) {
  printf("%ld",_564_main());
  return 0;
}
