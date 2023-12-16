/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _611_main(void);

/* Function definitions */
int64_t _611_main(void){
    int64_t _612_x;
    int64_t* _612_y;
    int64_t** _612_z;
    int64_t _611_$retval;
    _612_x = 75;
    _612_y = &_612_x;
    _612_z = &_612_y;
    **_612_z = 75;
    _611_$retval = **_612_z;
    return _611_$retval;
}

int main(void) {
  printf("%ld",_611_main());
  return 0;
}
