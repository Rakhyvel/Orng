/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _440_main(void);

/* Function definitions */
int64_t _440_main(void) {
    int64_t _441_x;
    int64_t* _441_y;
    int64_t _440_$retval;
    _441_x = 4;
    _441_y = &_441_x;
    *_441_y = 28;
    _440_$retval = *_441_y;
    return _440_$retval;
}

int main(void) {
  printf("%ld",_440_main());
  return 0;
}
