/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _781_main(void);

/* Function definitions */
int64_t _781_main(void){
    int64_t _782_x;
    int64_t* _782_y;
    int64_t _781_$retval;
    _782_x = 29;
    _782_y = &_782_x;
    _781_$retval = *_782_y;
    return _781_$retval;
}

int main(void) {
  printf("%ld",_781_main());
  return 0;
}
