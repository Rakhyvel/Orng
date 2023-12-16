/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _181_main(void);

/* Function definitions */
int64_t _181_main(void){
    int64_t _182_x;
    int64_t* _182_y;
    int64_t _181_$retval;
    _182_x = 242;
    _182_y = &_182_x;
    _181_$retval = *_182_y;
    return _181_$retval;
}

int main(void) {
  printf("%ld",_181_main());
  return 0;
}
