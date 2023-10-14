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
        goto BB7;
    }
BB2:
    if (_2_x == 40) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1_$retval = _2_x;
    return _1_$retval;
BB5:
    _2_x = $add_int64_t(_2_x, 1, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _2_x = $add_int64_t(_2_x, 1, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
