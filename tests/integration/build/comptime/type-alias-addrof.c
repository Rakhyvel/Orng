/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _401_main(void);


/* Function definitions */
int64_t _401_main(void){
    int64_t _402_x;
    int64_t* _402_y;
    int64_t _401_$retval;
    _402_x = 242;
    _402_y = &_402_x;
    _401_$retval = *_402_y;
    return _401_$retval;
}


int main(void) {
  printf("%ld",_401_main());
  return 0;
}
