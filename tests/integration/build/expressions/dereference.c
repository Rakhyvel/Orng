/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _618_main(void);

/* Function definitions */
int64_t _618_main(void){
    int64_t _619_x;
    int64_t* _619_y;
    int64_t _618_$retval;
    _619_x = 29;
    _619_y = &_619_x;
    _618_$retval = *_619_y;
    return _618_$retval;
}

int main(void) {
  printf("%ld",_618_main());
  return 0;
}
