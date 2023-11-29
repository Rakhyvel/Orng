/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _452_main(void);

/* Function definitions */
int64_t _452_main(void) {
    int64_t _453_x;
    int64_t* _453_y;
    int64_t _452_$retval;
    _453_x = 4;
    _453_y = &_453_x;
    *_453_y = 28;
    _452_$retval = *_453_y;
    return _452_$retval;
}

int main(void) {
  printf("%ld",_452_main());
  return 0;
}
