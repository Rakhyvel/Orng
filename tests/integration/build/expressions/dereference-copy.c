/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _680_main(void);


/* Function definitions */
int64_t _680_main(void){
    int64_t _681_x;
    int64_t* _681_y;
    int64_t _680_$retval;
    _681_x = 4;
    _681_y = &_681_x;
    *_681_y = 28;
    _680_$retval = *_681_y;
    return _680_$retval;
}


int main(void) {
  printf("%ld",_680_main());
  return 0;
}
