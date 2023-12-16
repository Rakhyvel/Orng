/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _610_main(void);

/* Function definitions */
int64_t _610_main(void) {
    int64_t _611_x;
    int64_t* _611_y;
    int64_t _610_$retval;
    _611_x = 29;
    _611_y = &_611_x;
    _610_$retval = *_611_y;
    return _610_$retval;
}

int main(void) {
  printf("%ld",_610_main());
  return 0;
}
