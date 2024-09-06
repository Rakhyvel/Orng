/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _438_main(void);


/* Function definitions */
int64_t _438_main(void){
    int64_t _439_x;
    int64_t _438_t3;
    uint8_t _438_t4;
    int64_t _438_t7;
    uint8_t _438_t8;
    int64_t _438_$retval;
    int64_t _438_t11;
    int64_t _438_t9;
    int64_t _438_t15;
    _439_x = 0;
    goto BB486;
BB486:
    _438_t3 = 100;
    _438_t4 = _439_x<_438_t3;
    if (_438_t4) {
        goto BB487;
    } else {
        goto BB491;
    }
BB487:
    _438_t7 = 36;
    _438_t8 = _439_x>=_438_t7;
    if (_438_t8) {
        goto BB489;
    } else {
        goto BB494;
    }
BB491:
    _438_$retval = _439_x;
    return _438_$retval;
BB489:
    _438_t11 = 2;
    _439_x = $add_int64_t(_439_x, _438_t11, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB491;
BB494:
    _438_t9 = 2;
    _439_x = $add_int64_t(_439_x, _438_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _438_t15 = 1;
    _439_x = $add_int64_t(_439_x, _438_t15, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB486;
}


int main(void) {
  printf("%ld",_438_main());
  return 0;
}
