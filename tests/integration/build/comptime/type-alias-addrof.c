/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _164_main(void);

/* Function definitions */
int64_t _164_main(void) {
    int64_t _165_x;
    int64_t* _165_y;
    int64_t _164_$retval;
    _165_x = 242;
    _165_y = &_165_x;
    _164_$retval = *_165_y;
    return _164_$retval;
}

int main(void) {
  printf("%ld",_164_main());
  return 0;
}
