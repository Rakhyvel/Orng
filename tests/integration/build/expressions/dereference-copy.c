/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _580_main(void);

/* Function definitions */
int64_t _580_main(void) {
    int64_t _581_x;
    int64_t* _581_y;
    int64_t _580_$retval;
    _581_x = 4;
    _581_y = &_581_x;
    *_581_y = 28;
    _580_$retval = *_581_y;
    return _580_$retval;
}

int main(void) {
  printf("%ld",_580_main());
  return 0;
}
