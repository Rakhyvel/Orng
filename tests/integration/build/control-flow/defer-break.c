/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _295_main(void);

/* Function definitions */
int64_t _295_main(void) {
    int64_t _296_x;
    int64_t _295_t2;
    uint8_t _295_t3;
    int64_t _295_t5;
    uint8_t _295_t6;
    int64_t _295_$retval;
    int64_t _295_t9;
    int64_t _295_t7;
    int64_t _295_t13;
    _296_x = 0;
    goto BB1;
BB1:
    _295_t2 = 100;
    _295_t3 = _296_x < _295_t2;
    if (_295_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _295_t5 = 36;
    _295_t6 = _296_x >= _295_t5;
    if (_295_t6) {
        goto BB4;
    } else {
        goto BB9;
    }
BB6:
    _295_$retval = _296_x;
    return _295_$retval;
BB4:
    _295_t9 = 2;
    _296_x = $add_int64_t(_296_x, _295_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB6;
BB9:
    _295_t7 = 2;
    _296_x = $add_int64_t(_296_x, _295_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _295_t13 = 1;
    _296_x = $add_int64_t(_296_x, _295_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_295_main());
  return 0;
}
