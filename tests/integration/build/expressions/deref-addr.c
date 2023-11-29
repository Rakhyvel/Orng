/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _564_main(void);

/* Function definitions */
int64_t _564_main(void) {
    int64_t _565_x;
    int64_t* _564_t2;
    int64_t* _564_t3;
    int64_t _564_$retval;
    _565_x = 5;
    _564_t2 = &_565_x;
    *_564_t2 = 74;
    _564_t3 = &_565_x;
    _564_$retval = *_564_t3;
    return _564_$retval;
}

int main(void) {
  printf("%ld",_564_main());
  return 0;
}
