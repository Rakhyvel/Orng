/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _297_main(void);


/* Function definitions */
int64_t _297_main(void){
    int64_t _298_x;
    int64_t* _298_y;
    int64_t _297_$retval;
    _298_x = 242;
    _298_y = &_298_x;
    _297_$retval = *_298_y;
    return _297_$retval;
}


int main(void) {
  printf("%ld",_297_main());
  return 0;
}
