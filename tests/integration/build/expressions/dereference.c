/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _670_main(void);

/* Function definitions */
int64_t _670_main(void){
    int64_t _671_x;
    int64_t* _671_y;
    int64_t _670_$retval;
    _671_x = 29;
    _671_y = &_671_x;
    _670_$retval = *_671_y;
    return _670_$retval;
}

int main(void) {
  printf("%ld",_670_main());
  return 0;
}
