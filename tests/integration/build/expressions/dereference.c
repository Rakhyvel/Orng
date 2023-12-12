/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _443_main(void);

/* Function definitions */
int64_t _443_main(void) {
    int64_t _444_x;
    int64_t* _444_y;
    int64_t _443_$retval;
    _444_x = 29;
    _444_y = &_444_x;
    _443_$retval = *_444_y;
    return _443_$retval;
}

int main(void) {
  printf("%ld",_443_main());
  return 0;
}
