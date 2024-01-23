/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _656_main(void);


/* Function definitions */
int64_t _656_main(void){
    int64_t _657_x;
    int64_t* _656_t2;
    int64_t* _656_t3;
    int64_t _656_$retval;
    _657_x = 5;
    _656_t2 = &_657_x;
    *_656_t2 = 74;
    _656_t3 = &_657_x;
    _656_$retval = *_656_t3;
    return _656_$retval;
}


int main(void) {
  printf("%ld",_656_main());
  return 0;
}
