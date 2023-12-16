/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _622_main(void);

/* Function definitions */
int64_t _622_main(void){
    int64_t _623_x;
    int64_t* _623_y;
    int64_t** _623_z;
    int64_t _622_$retval;
    _623_x = 75;
    _623_y = &_623_x;
    _623_z = &_623_y;
    **_623_z = 75;
    _622_$retval = **_623_z;
    return _622_$retval;
}

int main(void) {
  printf("%ld",_622_main());
  return 0;
}
