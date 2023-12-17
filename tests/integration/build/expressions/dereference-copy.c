/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _770_main(void);

/* Function definitions */
int64_t _770_main(void){
    int64_t _771_x;
    int64_t* _771_y;
    int64_t _770_$retval;
    _771_x = 4;
    _771_y = &_771_x;
    *_771_y = 28;
    _770_$retval = *_771_y;
    return _770_$retval;
}

int main(void) {
  printf("%ld",_770_main());
  return 0;
}
