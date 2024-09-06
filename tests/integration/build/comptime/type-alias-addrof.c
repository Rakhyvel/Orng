/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _379_main(void);


/* Function definitions */
int64_t _379_main(void){
    int64_t _380_x;
    int64_t* _380_y;
    int64_t _379_$retval;
    _380_x = 242;
    _380_y = &_380_x;
    _379_$retval = *_380_y;
    return _379_$retval;
}


int main(void) {
  printf("%ld",_379_main());
  return 0;
}
