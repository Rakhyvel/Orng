/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _2_x;
    int64_t _1_$retval;
    _2_x = 0;
BB1:
    if (_2_x < 100) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    if (_2_x >= 36) {
        goto BB4;
    } else {
        goto BB9;
    }
BB6:
    _1_$retval = _2_x;
    return _1_$retval;
BB4:
    _2_x = $add_int64_t(_2_x, 2, "tests/integration/control-flow/defer-break.orng:5:16:\n        defer x += 2\n              ^");
    goto BB6;
BB9:
    _2_x = $add_int64_t(_2_x, 2, "tests/integration/control-flow/defer-break.orng:5:16:\n        defer x += 2\n              ^");
    _2_x = $add_int64_t(_2_x, 1, "tests/integration/control-flow/defer-break.orng:4:21:\n    while x < 100; x += 1 {\n                   ^");
    goto BB1;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
