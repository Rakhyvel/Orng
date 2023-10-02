/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t _3_i;
    int64_t _1_$retval;
    _2_x = 0;
    _3_i = 0;
BB1:
    if (_3_i <= 10) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _2_x = $add_int64_t(_2_x, _3_i, "tests/integration/control-flow/while.orng:5:10:\n        x = x + i\n        ^");
    _3_i = $add_int64_t(_3_i, 1, "tests/integration/control-flow/while.orng:4:41:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                       ^");
    goto BB1;
BB7:
    _1_$retval = _2_x;
    return _1_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
