/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _644_main(void);

/* Function definitions */
int64_t _644_main(void){
    int64_t _645_x;
    int64_t* _644_t2;
    int64_t* _644_t3;
    int64_t _644_$retval;
    _645_x = 5;
    _644_t2 = &_645_x;
    *_644_t2 = 74;
    _644_t3 = &_645_x;
    _644_$retval = *_644_t3;
    return _644_$retval;
}

int main(void) {
  printf("%ld",_644_main());
  return 0;
}
