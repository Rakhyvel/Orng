/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _402_main(void);

/* Function definitions */
int64_t _402_main(void) {
    int64_t _403_x;
    int64_t* _402_t2;
    int64_t* _402_t3;
    int64_t _402_$retval;
    _403_x = 5;
    _402_t2 = &_403_x;
    *_402_t2 = 74;
    _402_t3 = &_403_x;
    _402_$retval = *_402_t3;
    return _402_$retval;
}

int main(void) {
  printf("%ld",_402_main());
  return 0;
}
