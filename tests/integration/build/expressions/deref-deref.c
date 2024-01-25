/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _691_main(void);


/* Function definitions */
int64_t _691_main(void){
    int64_t _692_x;
    int64_t* _692_y;
    int64_t** _692_z;
    int64_t _691_$retval;
    _692_x = 75;
    _692_y = &_692_x;
    _692_z = &_692_y;
    **_692_z = 75;
    _691_$retval = **_692_z;
    return _691_$retval;
}


int main(void) {
  printf("%ld",_691_main());
  return 0;
}
