/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _437_main(void);

/* Function definitions */
int64_t _437_main(void){
    int64_t _438_x;
    int64_t* _438_y;
    int64_t _437_$retval;
    _438_x = 242;
    _438_y = &_438_x;
    _437_$retval = *_438_y;
    return _437_$retval;
}

int main(void) {
  printf("%ld",_437_main());
  return 0;
}