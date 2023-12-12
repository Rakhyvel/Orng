/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _410_main(void);

/* Function definitions */
int64_t _410_main(void) {
    int64_t _411_x;
    int64_t* _410_t2;
    int64_t* _410_t3;
    int64_t _410_$retval;
    _411_x = 5;
    _410_t2 = &_411_x;
    *_410_t2 = 74;
    _410_t3 = &_411_x;
    _410_$retval = *_410_t3;
    return _410_$retval;
}

int main(void) {
  printf("%ld",_410_main());
  return 0;
}
