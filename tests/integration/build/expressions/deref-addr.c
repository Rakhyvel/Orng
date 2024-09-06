/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _657_main(void);


/* Function definitions */
int64_t _657_main(void){
    int64_t _658_x;
    int64_t* _657_t3;
    int64_t* _657_t4;
    int64_t _657_$retval;
    _658_x = 5;
    _657_t3 = &_658_x;
    *_657_t3 = 74;
    _657_t4 = &_658_x;
    _657_$retval = *_657_t4;
    return _657_$retval;
}


int main(void) {
  printf("%ld",_657_main());
  return 0;
}
