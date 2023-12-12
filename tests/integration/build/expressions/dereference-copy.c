/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _421_main(void);

/* Function definitions */
int64_t _421_main(void) {
    int64_t _422_x;
    int64_t* _422_y;
    int64_t _421_$retval;
    _422_x = 4;
    _422_y = &_422_x;
    *_422_y = 28;
    _421_$retval = *_422_y;
    return _421_$retval;
}

int main(void) {
  printf("%ld",_421_main());
  return 0;
}
