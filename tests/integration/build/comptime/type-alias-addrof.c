/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _399_main(void);


/* Function definitions */
int64_t _399_main(void){
    int64_t _400_x;
    int64_t* _400_y;
    int64_t _399_$retval;
    _400_x = 242;
    _400_y = &_400_x;
    _399_$retval = *_400_y;
    return _399_$retval;
}


int main(void) {
  printf("%ld",_399_main());
  return 0;
}
