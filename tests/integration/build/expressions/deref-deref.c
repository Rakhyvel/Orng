/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _677_main(void);


/* Function definitions */
int64_t _677_main(void){
    int64_t _678_x;
    int64_t* _678_y;
    int64_t** _678_z;
    int64_t _677_$retval;
    _678_x = 75;
    _678_y = &_678_x;
    _678_z = &_678_y;
    **_678_z = 75;
    _677_$retval = **_678_z;
    return _677_$retval;
}


int main(void) {
  printf("%ld",_677_main());
  return 0;
}
