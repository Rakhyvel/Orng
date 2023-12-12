/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _278_main(void);

/* Function definitions */
int64_t _278_main(void) {
    int64_t _279_x;
    int64_t _280_i;
    int64_t _278_t3;
    uint8_t _278_t4;
    int64_t _278_t6;
    int64_t _278_$retval;
    _279_x = 0;
    _280_i = 0;
    goto BB1;
BB1:
    _278_t3 = 10;
    _278_t4 = _280_i <= _278_t3;
    if (_278_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _279_x = $add_int64_t(_279_x, _280_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _278_t6 = 1;
    _280_i = $add_int64_t(_280_i, _278_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _278_$retval = _279_x;
    return _278_$retval;
}

int main(void) {
  printf("%ld",_278_main());
  return 0;
}
