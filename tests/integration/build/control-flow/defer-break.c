/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _324_main(void);

/* Function definitions */
int64_t _324_main(void) {
    int64_t _325_x;
    int64_t _324_t2;
    uint8_t _324_t3;
    int64_t _324_t5;
    uint8_t _324_t6;
    int64_t _324_$retval;
    int64_t _324_t9;
    int64_t _324_t7;
    int64_t _324_t13;
    _325_x = 0;
    goto BB1;
BB1:
    _324_t2 = 100;
    _324_t3 = _325_x < _324_t2;
    if (_324_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _324_t5 = 36;
    _324_t6 = _325_x >= _324_t5;
    if (_324_t6) {
        goto BB4;
    } else {
        goto BB9;
    }
BB6:
    _324_$retval = _325_x;
    return _324_$retval;
BB4:
    _324_t9 = 2;
    _325_x = $add_int64_t(_325_x, _324_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB6;
BB9:
    _324_t7 = 2;
    _325_x = $add_int64_t(_325_x, _324_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _324_t13 = 1;
    _325_x = $add_int64_t(_325_x, _324_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_324_main());
  return 0;
}
