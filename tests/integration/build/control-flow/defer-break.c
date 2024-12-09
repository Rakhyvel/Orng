/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _435_main(void);


/* Function definitions */
int64_t _435_main(void){
    int64_t _436_x;
    int64_t _435_t3;
    uint8_t _435_t4;
    int64_t _435_t7;
    uint8_t _435_t8;
    int64_t _435_$retval;
    int64_t _435_t11;
    int64_t _435_t9;
    int64_t _435_t15;
    _436_x = 0;
    goto BB483;
BB483:
    _435_t3 = 100;
    _435_t4 = _436_x<_435_t3;
    if (_435_t4) {
        goto BB484;
    } else {
        goto BB488;
    }
BB484:
    _435_t7 = 36;
    _435_t8 = _436_x>=_435_t7;
    if (_435_t8) {
        goto BB486;
    } else {
        goto BB491;
    }
BB488:
    _435_$retval = _436_x;
    return _435_$retval;
BB486:
    _435_t11 = 2;
    _436_x = $add_int64_t(_436_x, _435_t11, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB488;
BB491:
    _435_t9 = 2;
    _436_x = $add_int64_t(_436_x, _435_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _435_t15 = 1;
    _436_x = $add_int64_t(_436_x, _435_t15, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB483;
}


int main(void) {
  printf("%ld",_435_main());
  return 0;
}
