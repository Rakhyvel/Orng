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
    _2_x = 17;
BB1:
    if (_2_x < 36) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    if ($mod_int64_t(_2_x, 2, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^")) {
        goto BB10;
    } else {
        goto BB6;
    }
BB14:
    _1_$retval = _2_x;
    return _1_$retval;
BB10:
    _2_x = $add_int64_t(_2_x, 1, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
BB6:
    _2_x = $add_int64_t(_2_x, 9, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB1;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
