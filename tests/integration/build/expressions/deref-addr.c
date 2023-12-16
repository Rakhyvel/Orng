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
    int64_t* _671_t2;
    int64_t* _671_t3;
    int64_t _671_$retval;
    _672_x = 5;
    _671_t2 = &_672_x;
    *_671_t2 = 74;
    _671_t3 = &_672_x;
    _671_$retval = *_671_t3;
    return _671_$retval;
}

int main(void) {
  printf("%ld",_671_main());
  return 0;
}
