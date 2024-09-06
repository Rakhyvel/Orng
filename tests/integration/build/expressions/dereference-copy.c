/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _660_main(void);


/* Function definitions */
int64_t _660_main(void){
    int64_t _661_x;
    int64_t* _661_y;
    int64_t _660_$retval;
    _661_x = 4;
    _661_y = &_661_x;
    *_661_y = 28;
    _660_$retval = *_661_y;
    return _660_$retval;
}


int main(void) {
  printf("%ld",_660_main());
  return 0;
}
