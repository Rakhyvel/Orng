/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _2_x;
    int64_t* _2_y;
    int64_t** _2_z;
    int64_t* _1_t5;
    int64_t _1_$retval;
    _2_x = 75;
    _2_y = &_2_x;
    _2_z = &_2_y;
    **_2_z = 75;
    _1_t5 = *_2_z;
    _1_$retval = *_1_t5;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
