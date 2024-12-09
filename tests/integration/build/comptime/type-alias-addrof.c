/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _384_main(void);


/* Function definitions */
int64_t _384_main(void){
    int64_t _385_x;
    int64_t* _385_y;
    int64_t _384_$retval;
    _385_x = 242;
    _385_y = &_385_x;
    _384_$retval = *_385_y;
    return _384_$retval;
}


int main(void) {
  printf("%ld",_384_main());
  return 0;
}
