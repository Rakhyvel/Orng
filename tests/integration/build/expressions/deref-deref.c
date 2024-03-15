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
    int64_t* _658_y;
    int64_t** _658_z;
    int64_t _657_$retval;
    _658_x = 75;
    _658_y = &_658_x;
    _658_z = &_658_y;
    **_658_z = 75;
    _657_$retval = **_658_z;
    return _657_$retval;
}


int main(void) {
  printf("%ld",_657_main());
  return 0;
}
