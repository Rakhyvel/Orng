/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _669_main(void);


/* Function definitions */
int64_t _669_main(void){
    int64_t _670_x;
    int64_t* _669_t3;
    int64_t* _669_t4;
    int64_t _669_$retval;
    _670_x = 5;
    _669_t3 = &_670_x;
    *_669_t3 = 74;
    _669_t4 = &_670_x;
    _669_$retval = *_669_t4;
    return _669_$retval;
}


int main(void) {
  printf("%ld",_669_main());
  return 0;
}
