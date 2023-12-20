/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _655_main(void);

/* Function definitions */
int64_t _655_main(void){
    int64_t _656_x;
    int64_t* _656_y;
    int64_t _655_$retval;
    _656_x = 4;
    _656_y = &_656_x;
    *_656_y = 28;
    _655_$retval = *_656_y;
    return _655_$retval;
}

int main(void) {
  printf("%ld",_655_main());
  return 0;
}
