/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _777_main(void);

/* Function definitions */
int64_t _777_main(void){
    int64_t _778_x;
    int64_t* _778_y;
    int64_t _777_$retval;
    _778_x = 4;
    _778_y = &_778_x;
    *_778_y = 28;
    _777_$retval = *_778_y;
    return _777_$retval;
}

int main(void) {
  printf("%ld",_777_main());
  return 0;
}
