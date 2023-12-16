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
    int64_t* _611_t2;
    int64_t* _611_t3;
    int64_t _611_$retval;
    _612_x = 5;
    _611_t2 = &_612_x;
    *_611_t2 = 74;
    _611_t3 = &_612_x;
    _611_$retval = *_611_t3;
    return _611_$retval;
}

int main(void) {
  printf("%ld",_611_main());
  return 0;
}
