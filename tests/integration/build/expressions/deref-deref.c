/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _662_main(void);


/* Function definitions */
int64_t _662_main(void){
    int64_t _663_x;
    int64_t* _663_y;
    int64_t** _663_z;
    int64_t _662_$retval;
    _663_x = 75;
    _663_y = &_663_x;
    _663_z = &_663_y;
    **_663_z = 75;
    _662_$retval = **_663_z;
    return _662_$retval;
}


int main(void) {
  printf("%ld",_662_main());
  return 0;
}
