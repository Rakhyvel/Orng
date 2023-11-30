/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _543_main(void);

/* Function definitions */
int64_t _543_main(void) {
    int64_t _544_x;
    int64_t* _543_t2;
    int64_t* _543_t3;
    int64_t _543_$retval;
    _544_x = 5;
    _543_t2 = &_544_x;
    *_543_t2 = 74;
    _543_t3 = &_544_x;
    _543_$retval = *_543_t3;
    return _543_$retval;
}

int main(void) {
  printf("%ld",_543_main());
  return 0;
}
