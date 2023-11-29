/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _441_main(void);

/* Function definitions */
int64_t _441_main(void) {
    int64_t _442_x;
    int64_t* _441_t2;
    int64_t* _441_t3;
    int64_t _441_$retval;
    _442_x = 5;
    _441_t2 = &_442_x;
    *_441_t2 = 74;
    _441_t3 = &_442_x;
    _441_$retval = *_441_t3;
    return _441_$retval;
}

int main(void) {
  printf("%ld",_441_main());
  return 0;
}
