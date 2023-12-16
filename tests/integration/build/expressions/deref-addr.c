/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _600_main(void);

/* Function definitions */
int64_t _600_main(void){
    int64_t _601_x;
    int64_t* _600_t2;
    int64_t* _600_t3;
    int64_t _600_$retval;
    _601_x = 5;
    _600_t2 = &_601_x;
    *_600_t2 = 74;
    _600_t3 = &_601_x;
    _600_$retval = *_600_t3;
    return _600_$retval;
}

int main(void) {
  printf("%ld",_600_main());
  return 0;
}
