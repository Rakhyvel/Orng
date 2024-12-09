/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _654_main(void);


/* Function definitions */
int64_t _654_main(void){
    int64_t _655_x;
    int64_t* _654_t3;
    int64_t* _654_t4;
    int64_t _654_$retval;
    _655_x = 5;
    _654_t3 = &_655_x;
    *_654_t3 = 74;
    _654_t4 = &_655_x;
    _654_$retval = *_654_t4;
    return _654_$retval;
}


int main(void) {
  printf("%ld",_654_main());
  return 0;
}
