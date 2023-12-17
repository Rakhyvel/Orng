/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _767_main(void);

/* Function definitions */
int64_t _767_main(void){
    int64_t _768_x;
    int64_t* _768_y;
    int64_t** _768_z;
    int64_t _767_$retval;
    _768_x = 75;
    _768_y = &_768_x;
    _768_z = &_768_y;
    **_768_z = 75;
    _767_$retval = **_768_z;
    return _767_$retval;
}

int main(void) {
  printf("%ld",_767_main());
  return 0;
}
