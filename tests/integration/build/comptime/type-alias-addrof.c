/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _145_main(void);

/* Function definitions */
int64_t _145_main(void) {
    int64_t _146_x;
    int64_t* _146_y;
    int64_t _145_$retval;
    _146_x = 242;
    _146_y = &_146_x;
    _145_$retval = *_146_y;
    return _145_$retval;
}

int main(void) {
  printf("%ld",_145_main());
  return 0;
}
