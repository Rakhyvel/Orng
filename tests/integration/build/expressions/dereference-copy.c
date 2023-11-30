/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _582_main(void);

/* Function definitions */
int64_t _582_main(void) {
    int64_t _583_x;
    int64_t* _583_y;
    int64_t _582_$retval;
    _583_x = 4;
    _583_y = &_583_x;
    *_583_y = 28;
    _582_$retval = *_583_y;
    return _582_$retval;
}

int main(void) {
  printf("%ld",_582_main());
  return 0;
}
