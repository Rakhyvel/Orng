/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _338_main(void);

/* Function definitions */
int64_t _338_main(void) {
    int64_t _339_x;
    int64_t* _338_t2;
    int64_t* _338_t3;
    int64_t _338_$retval;
    _339_x = 5;
    _338_t2 = &_339_x;
    *_338_t2 = 74;
    _338_t3 = &_339_x;
    _338_$retval = *_338_t3;
    return _338_$retval;
}

int main(void) {
  printf("%ld",_338_main());
  return 0;
}
