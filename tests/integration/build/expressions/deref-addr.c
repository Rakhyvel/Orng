/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _592_main(void);

/* Function definitions */
int64_t _592_main(void) {
    int64_t _593_x;
    int64_t* _592_t2;
    int64_t* _592_t3;
    int64_t _592_$retval;
    _593_x = 5;
    _592_t2 = &_593_x;
    *_592_t2 = 74;
    _592_t3 = &_593_x;
    _592_$retval = *_592_t3;
    return _592_$retval;
}

int main(void) {
  printf("%ld",_592_main());
  return 0;
}
