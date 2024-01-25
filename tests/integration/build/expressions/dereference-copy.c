/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _694_main(void);


/* Function definitions */
int64_t _694_main(void){
    int64_t _695_x;
    int64_t* _695_y;
    int64_t _694_$retval;
    _695_x = 4;
    _695_y = &_695_x;
    *_695_y = 28;
    _694_$retval = *_695_y;
    return _694_$retval;
}


int main(void) {
  printf("%ld",_694_main());
  return 0;
}
