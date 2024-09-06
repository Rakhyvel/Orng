/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _649_main(void);


/* Function definitions */
int64_t _649_main(void){
    int64_t _650_x;
    int64_t* _649_t3;
    int64_t* _649_t4;
    int64_t _649_$retval;
    _650_x = 5;
    _649_t3 = &_650_x;
    *_649_t3 = 74;
    _649_t4 = &_650_x;
    _649_$retval = *_649_t4;
    return _649_$retval;
}


int main(void) {
  printf("%ld",_649_main());
  return 0;
}
