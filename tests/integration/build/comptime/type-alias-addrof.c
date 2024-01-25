/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _380_main(void);


/* Function definitions */
int64_t _380_main(void){
    int64_t _381_x;
    int64_t* _381_y;
    int64_t _380_$retval;
    _381_x = 242;
    _381_y = &_381_x;
    _380_$retval = *_381_y;
    return _380_$retval;
}


int main(void) {
  printf("%ld",_380_main());
  return 0;
}
