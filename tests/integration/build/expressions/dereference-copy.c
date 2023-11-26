/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _349_main(void);

/* Function definitions */
int64_t _349_main(void) {
    int64_t _350_x;
    int64_t* _350_y;
    int64_t _349_$retval;
    _350_x = 4;
    _350_y = &_350_x;
    *_350_y = 28;
    _349_$retval = *_350_y;
    return _349_$retval;
}

int main(void) {
  printf("%ld",_349_main());
  return 0;
}
