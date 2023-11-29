/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _576_main(void);

/* Function definitions */
int64_t _576_main(void) {
    int64_t _577_x;
    int64_t* _577_y;
    int64_t** _577_z;
    int64_t _576_$retval;
    _577_x = 75;
    _577_y = &_577_x;
    _577_z = &_577_y;
    **_577_z = 75;
    _576_$retval = **_577_z;
    return _576_$retval;
}

int main(void) {
  printf("%ld",_576_main());
  return 0;
}
