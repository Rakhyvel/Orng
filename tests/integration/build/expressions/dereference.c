/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _689_main(void);

/* Function definitions */
int64_t _689_main(void){
    int64_t _690_x;
    int64_t* _690_y;
    int64_t _689_$retval;
    _690_x = 29;
    _690_y = &_690_x;
    _689_$retval = *_690_y;
    return _689_$retval;
}

int main(void) {
  printf("%ld",_689_main());
  return 0;
}
