/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _416_main(void);

/* Function definitions */
int64_t _416_main(void) {
    int64_t _417_x;
    int64_t* _417_y;
    int64_t _416_$retval;
    _417_x = 29;
    _417_y = &_417_x;
    _416_$retval = *_417_y;
    return _416_$retval;
}

int main(void) {
  printf("%ld",_416_main());
  return 0;
}
