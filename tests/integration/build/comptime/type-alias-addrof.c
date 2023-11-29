/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _68_main(void);

/* Function definitions */
int64_t _68_main(void) {
    int64_t _69_x;
    int64_t* _69_y;
    int64_t _68_$retval;
    _69_x = 242;
    _69_y = &_69_x;
    _68_$retval = *_69_y;
    return _68_$retval;
}

int main(void) {
  printf("%ld",_68_main());
  return 0;
}
