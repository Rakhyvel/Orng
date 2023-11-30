/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _91_main(void);

/* Function definitions */
int64_t _91_main(void) {
    int64_t _92_x;
    int64_t* _92_y;
    int64_t _91_$retval;
    _92_x = 242;
    _92_y = &_92_x;
    _91_$retval = *_92_y;
    return _91_$retval;
}

int main(void) {
  printf("%ld",_91_main());
  return 0;
}
