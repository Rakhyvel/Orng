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
    int64_t _3_i;
    int64_t _1_$retval;
    _2_x = 36;
    _3_i = 0;
BB1:
    if (_3_i < 70) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    if ($mod_int64_t(_3_i, 2, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^")) {
        goto BB9;
    } else {
        goto BB7;
    }
BB13:
    _2_x = 10;
    goto BB7;
BB9:
    _2_x = $add_int64_t(_2_x, 1, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _3_i = $add_int64_t(_3_i, 1, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
BB7:
    _1_$retval = _2_x;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
