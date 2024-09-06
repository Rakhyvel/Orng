/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _671_main(void);


/* Function definitions */
int64_t _671_main(void){
    int64_t _672_x;
    int64_t* _672_y;
    int64_t _671_$retval;
    _672_x = 29;
    _672_y = &_672_x;
    _671_$retval = *_672_y;
    return _671_$retval;
}


int main(void) {
  printf("%ld",_671_main());
  return 0;
}
