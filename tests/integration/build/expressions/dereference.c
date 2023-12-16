/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _629_main(void);

/* Function definitions */
int64_t _629_main(void){
    int64_t _630_x;
    int64_t* _630_y;
    int64_t _629_$retval;
    _630_x = 29;
    _630_y = &_630_x;
    _629_$retval = *_630_y;
    return _629_$retval;
}

int main(void) {
  printf("%ld",_629_main());
  return 0;
}
