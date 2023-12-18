/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _774_main(void);

/* Function definitions */
int64_t _774_main(void){
    int64_t _775_x;
    int64_t* _775_y;
    int64_t** _775_z;
    int64_t _774_$retval;
    _775_x = 75;
    _775_y = &_775_x;
    _775_z = &_775_y;
    **_775_z = 75;
    _774_$retval = **_775_z;
    return _774_$retval;
}

int main(void) {
  printf("%ld",_774_main());
  return 0;
}
