/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _625_main(void);

/* Function definitions */
int64_t _625_main(void){
    int64_t _626_x;
    int64_t* _626_y;
    int64_t _625_$retval;
    _626_x = 4;
    _626_y = &_626_x;
    *_626_y = 28;
    _625_$retval = *_626_y;
    return _625_$retval;
}

int main(void) {
  printf("%ld",_625_main());
  return 0;
}
