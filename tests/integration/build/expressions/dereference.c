/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _683_main(void);


/* Function definitions */
int64_t _683_main(void){
    int64_t _684_x;
    int64_t* _684_y;
    int64_t _683_$retval;
    _684_x = 29;
    _684_y = &_684_x;
    _683_$retval = *_684_y;
    return _683_$retval;
}


int main(void) {
  printf("%ld",_683_main());
  return 0;
}
