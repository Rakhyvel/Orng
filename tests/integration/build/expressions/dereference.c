/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _424_main(void);

/* Function definitions */
int64_t _424_main(void) {
    int64_t _425_x;
    int64_t* _425_y;
    int64_t _424_$retval;
    _425_x = 29;
    _425_y = &_425_x;
    _424_$retval = *_425_y;
    return _424_$retval;
}

int main(void) {
  printf("%ld",_424_main());
  return 0;
}
