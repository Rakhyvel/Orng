/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _587_main(void);

/* Function definitions */
int64_t _587_main(void) {
    int64_t _588_x;
    int64_t* _588_y;
    int64_t _587_$retval;
    _588_x = 29;
    _588_y = &_588_x;
    _587_$retval = *_588_y;
    return _587_$retval;
}

int main(void) {
  printf("%ld",_587_main());
  return 0;
}
