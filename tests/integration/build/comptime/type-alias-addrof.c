/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _352_main(void);

/* Function definitions */
int64_t _352_main(void){
    int64_t _353_x;
    int64_t* _353_y;
    int64_t _352_$retval;
    _353_x = 242;
    _353_y = &_353_x;
    _352_$retval = *_353_y;
    return _352_$retval;
}

int main(void) {
  printf("%ld",_352_main());
  return 0;
}
