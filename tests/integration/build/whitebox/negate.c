/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1856_main(void);


/* Function definitions */
int64_t _1856_main(void){
    int64_t _1857_x;
    int64_t* _1857_y;
    int64_t _1856_t5;
    int64_t _1856_t7;
    uint8_t _1856_t9;
    int64_t _1856_t4;
    int64_t _1856_$retval;
    _1857_x = 1;
    _1857_y = &_1857_x;
    _1856_t5 = $negate_int64_t(*_1857_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1856_t7 = -1;
    _1856_t9 = _1856_t5==_1856_t7;
    if (_1856_t9) {
        goto BB2066;
    } else {
        goto BB2070;
    }
BB2066:
    _1856_t4 = 32;
    goto BB2069;
BB2070:
    _1856_t4 = 10;
    goto BB2069;
BB2069:
    _1856_$retval = _1856_t4;
    return _1856_$retval;
}


int main(void) {
  printf("%ld",_1856_main());
  return 0;
}
