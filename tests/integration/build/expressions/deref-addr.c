/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _763_main(void);

/* Function definitions */
int64_t _763_main(void){
    int64_t _764_x;
    int64_t* _763_t2;
    int64_t* _763_t3;
    int64_t _763_$retval;
    _764_x = 5;
    _763_t2 = &_764_x;
    *_763_t2 = 74;
    _763_t3 = &_764_x;
    _763_$retval = *_763_t3;
    return _763_$retval;
}

int main(void) {
  printf("%ld",_763_main());
  return 0;
}
