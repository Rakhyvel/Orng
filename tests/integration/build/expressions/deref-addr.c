/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t* _1_t2;
    int64_t* _1_t3;
    int64_t _1_$retval;
    _2_x = 5;
    _1_t2 = &_2_x;
    **&_1_t2 = 74;
    _1_t3 = &_2_x;
    _1_$retval = *_1_t3;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
