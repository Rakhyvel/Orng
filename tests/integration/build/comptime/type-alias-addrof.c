/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _62_main(void);

/* Function definitions */
int64_t _62_main(void) {
    int64_t _63_x;
    int64_t* _63_y;
    int64_t _62_$retval;
    _63_x = 242;
    _63_y = &_63_x;
    _62_$retval = *_63_y;
    return _62_$retval;
}

int main(void) {
  printf("%ld",_62_main());
  return 0;
}
