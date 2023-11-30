/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _566_main(void);

/* Function definitions */
int64_t _566_main(void) {
    int64_t _567_x;
    int64_t* _566_t2;
    int64_t* _566_t3;
    int64_t _566_$retval;
    _567_x = 5;
    _566_t2 = &_567_x;
    *_566_t2 = 74;
    _566_t3 = &_567_x;
    _566_$retval = *_566_t3;
    return _566_$retval;
}

int main(void) {
  printf("%ld",_566_main());
  return 0;
}
