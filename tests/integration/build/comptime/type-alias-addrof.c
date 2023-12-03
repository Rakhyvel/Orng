/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _137_main(void);

/* Function definitions */
int64_t _137_main(void) {
    int64_t _138_x;
    int64_t* _138_y;
    int64_t _137_$retval;
    _138_x = 242;
    _138_y = &_138_x;
    _137_$retval = *_138_y;
    return _137_$retval;
}

int main(void) {
  printf("%ld",_137_main());
  return 0;
}
