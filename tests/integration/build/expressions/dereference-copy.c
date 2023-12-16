/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _614_main(void);

/* Function definitions */
int64_t _614_main(void){
    int64_t _615_x;
    int64_t* _615_y;
    int64_t _614_$retval;
    _615_x = 4;
    _615_y = &_615_x;
    *_615_y = 28;
    _614_$retval = *_615_y;
    return _614_$retval;
}

int main(void) {
  printf("%ld",_614_main());
  return 0;
}
