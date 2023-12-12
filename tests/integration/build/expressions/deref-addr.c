/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _429_main(void);

/* Function definitions */
int64_t _429_main(void) {
    int64_t _430_x;
    int64_t* _429_t2;
    int64_t* _429_t3;
    int64_t _429_$retval;
    _430_x = 5;
    _429_t2 = &_430_x;
    *_429_t2 = 74;
    _429_t3 = &_430_x;
    _429_$retval = *_429_t3;
    return _429_$retval;
}

int main(void) {
  printf("%ld",_429_main());
  return 0;
}
