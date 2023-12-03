/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _251_main(void);

/* Function definitions */
int64_t _251_main(void) {
    int64_t _252_x;
    int64_t _253_i;
    int64_t _251_t3;
    uint8_t _251_t4;
    int64_t _251_t6;
    int64_t _251_$retval;
    _252_x = 0;
    _253_i = 0;
    goto BB1;
BB1:
    _251_t3 = 10;
    _251_t4 = _253_i <= _251_t3;
    if (_251_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _252_x = $add_int64_t(_252_x, _253_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _251_t6 = 1;
    _253_i = $add_int64_t(_253_i, _251_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _251_$retval = _252_x;
    return _251_$retval;
}

int main(void) {
  printf("%ld",_251_main());
  return 0;
}
