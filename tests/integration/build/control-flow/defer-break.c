/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _112_main(void);

/* Function definitions */
int64_t _112_main(void) {
    int64_t _113_x;
    int64_t _112_t2;
    uint8_t _112_t3;
    int64_t _112_t5;
    uint8_t _112_t6;
    int64_t _112_$retval;
    int64_t _112_t9;
    int64_t _112_t7;
    int64_t _112_t13;
    _113_x = 0;
    goto BB1;
BB1:
    _112_t2 = 100;
    _112_t3 = _113_x < _112_t2;
    if (_112_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _112_t5 = 36;
    _112_t6 = _113_x >= _112_t5;
    if (_112_t6) {
        goto BB4;
    } else {
        goto BB9;
    }
BB6:
    _112_$retval = _113_x;
    return _112_$retval;
BB4:
    _112_t9 = 2;
    _113_x = $add_int64_t(_113_x, _112_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB6;
BB9:
    _112_t7 = 2;
    _113_x = $add_int64_t(_113_x, _112_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _112_t13 = 1;
    _113_x = $add_int64_t(_113_x, _112_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_112_main());
  return 0;
}
