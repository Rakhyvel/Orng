/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _665_main(void);


/* Function definitions */
int64_t _665_main(void){
    int64_t _666_x;
    int64_t* _666_y;
    int64_t _665_$retval;
    _666_x = 4;
    _666_y = &_666_x;
    *_666_y = 28;
    _665_$retval = *_666_y;
    return _665_$retval;
}


int main(void) {
  printf("%ld",_665_main());
  return 0;
}
