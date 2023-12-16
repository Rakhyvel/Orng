/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _292_main(void);

/* Function definitions */
int64_t _292_main(void){
    int64_t _293_x;
    int64_t* _293_y;
    int64_t _292_$retval;
    _293_x = 242;
    _293_y = &_293_x;
    _292_$retval = *_293_y;
    return _292_$retval;
}

int main(void) {
  printf("%ld",_292_main());
  return 0;
}
