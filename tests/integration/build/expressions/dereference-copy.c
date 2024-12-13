/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _682_main(void);


/* Function definitions */
int64_t _682_main(void){
    int64_t _683_x;
    int64_t* _683_y;
    int64_t _682_$retval;
    _683_x = 4;
    _683_y = &_683_x;
    *_683_y = 28;
    _682_$retval = *_683_y;
    return _682_$retval;
}


int main(void) {
  printf("%ld",_682_main());
  return 0;
}
