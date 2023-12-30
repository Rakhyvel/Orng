/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _664_main(void);

/* Function definitions */
int64_t _664_main(void){
    int64_t _665_x;
    int64_t* _665_y;
    int64_t** _665_z;
    int64_t _664_$retval;
    _665_x = 75;
    _665_y = &_665_x;
    _665_z = &_665_y;
    **_665_z = 75;
    _664_$retval = **_665_z;
    return _664_$retval;
}

int main(void) {
  printf("%ld",_664_main());
  return 0;
}
