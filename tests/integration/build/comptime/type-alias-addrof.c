/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _351_main(void);

/* Function definitions */
int64_t _351_main(void){
    int64_t _352_x;
    int64_t* _352_y;
    int64_t _351_$retval;
    _352_x = 242;
    _352_y = &_352_x;
    _351_$retval = *_352_y;
    return _351_$retval;
}

int main(void) {
  printf("%ld",_351_main());
  return 0;
}
