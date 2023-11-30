/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _356_main(void);

/* Function definitions */
int64_t _356_main(void) {
    int64_t _357_x;
    int64_t _359_i;
    int64_t _356_t3;
    uint8_t _356_t4;
    int64_t _356_t6;
    int64_t _356_$retval;
    _357_x = 0;
    _359_i = 0;
    goto BB1;
BB1:
    _356_t3 = 10;
    _356_t4 = _359_i <= _356_t3;
    if (_356_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _357_x = $add_int64_t(_357_x, _359_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _356_t6 = 1;
    _359_i = $add_int64_t(_359_i, _356_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _356_$retval = _357_x;
    return _356_$retval;
}

int main(void) {
  printf("%ld",_356_main());
  return 0;
}
