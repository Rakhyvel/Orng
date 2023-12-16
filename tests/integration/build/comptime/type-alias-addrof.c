/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _281_main(void);

/* Function definitions */
int64_t _281_main(void){
    int64_t _282_x;
    int64_t* _282_y;
    int64_t _281_$retval;
    _282_x = 242;
    _282_y = &_282_x;
    _281_$retval = *_282_y;
    return _281_$retval;
}

int main(void) {
  printf("%ld",_281_main());
  return 0;
}
