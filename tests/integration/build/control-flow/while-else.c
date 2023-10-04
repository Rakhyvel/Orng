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
    int64_t _3_x;
    int64_t _1_$retval;
    _3_x = 0;
BB1:
    if (_3_x < 10) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _3_x = $add_int64_t(_3_x, 1, "tests/integration/control-flow/while-else.orng:4:10:\n        x += 1\n        ^");
    _3_x = $add_int64_t(_3_x, 1, "tests/integration/control-flow/while-else.orng:3:40:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                      ^");
    goto BB1;
BB6:
    _1_$retval = _3_x;
    return _1_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
