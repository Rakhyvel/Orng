/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _223_main(void);

/* Function definitions */
int64_t _223_main(void) {
    int64_t _224_x;
    int64_t _225_i;
    int64_t _223_t3;
    uint8_t _223_t4;
    int64_t _223_t6;
    int64_t _223_$retval;
    _224_x = 0;
    _225_i = 0;
    goto BB1;
BB1:
    _223_t3 = 10;
    _223_t4 = _225_i <= _223_t3;
    if (_223_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _224_x = $add_int64_t(_224_x, _225_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _223_t6 = 1;
    _225_i = $add_int64_t(_225_i, _223_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _223_$retval = _224_x;
    return _223_$retval;
}

int main(void) {
  printf("%ld",_223_main());
  return 0;
}
