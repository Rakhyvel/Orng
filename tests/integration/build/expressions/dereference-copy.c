/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _667_main(void);


/* Function definitions */
int64_t _667_main(void){
    int64_t _668_x;
    int64_t* _668_y;
    int64_t _667_$retval;
    _668_x = 4;
    _668_y = &_668_x;
    *_668_y = 28;
    _667_$retval = *_668_y;
    return _667_$retval;
}


int main(void) {
  printf("%ld",_667_main());
  return 0;
}
