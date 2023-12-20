/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _652_main(void);

/* Function definitions */
int64_t _652_main(void){
    int64_t _653_x;
    int64_t* _653_y;
    int64_t** _653_z;
    int64_t _652_$retval;
    _653_x = 75;
    _653_y = &_653_x;
    _653_z = &_653_y;
    **_653_z = 75;
    _652_$retval = **_653_z;
    return _652_$retval;
}

int main(void) {
  printf("%ld",_652_main());
  return 0;
}
