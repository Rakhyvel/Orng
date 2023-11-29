/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _455_main(void);

/* Function definitions */
int64_t _455_main(void) {
    int64_t _456_x;
    int64_t* _456_y;
    int64_t _455_$retval;
    _456_x = 29;
    _456_y = &_456_x;
    _455_$retval = *_456_y;
    return _455_$retval;
}

int main(void) {
  printf("%ld",_455_main());
  return 0;
}
