/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _33_main(void);

/* Function definitions */
int64_t _33_main(void) {
    int64_t _34_x;
    int64_t* _33_t2;
    int64_t* _33_t3;
    int64_t _33_$retval;
    _34_x = 5;
    _33_t2 = &_34_x;
    *_33_t2 = 74;
    _33_t3 = &_34_x;
    _33_$retval = *_33_t3;
    return _33_$retval;
}

int main(void) {
  printf("%ld",_33_main());
  return 0;
}
