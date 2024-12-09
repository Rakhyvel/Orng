/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _668_main(void);


/* Function definitions */
int64_t _668_main(void){
    int64_t _669_x;
    int64_t* _669_y;
    int64_t _668_$retval;
    _669_x = 29;
    _669_y = &_669_x;
    _668_$retval = *_669_y;
    return _668_$retval;
}


int main(void) {
  printf("%ld",_668_main());
  return 0;
}
