/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _679_main(void);


/* Function definitions */
int64_t _679_main(void){
    int64_t _680_x;
    int64_t* _680_y;
    int64_t** _680_z;
    int64_t _679_$retval;
    _680_x = 75;
    _680_y = &_680_x;
    _680_z = &_680_y;
    **_680_z = 75;
    _679_$retval = **_680_z;
    return _679_$retval;
}


int main(void) {
  printf("%ld",_679_main());
  return 0;
}
