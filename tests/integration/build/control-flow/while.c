/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _292_main(void);

/* Function definitions */
int64_t _292_main(void) {
    int64_t _293_x;
    int64_t _294_i;
    int64_t _292_t3;
    uint8_t _292_t4;
    int64_t _292_t6;
    int64_t _292_$retval;
    _293_x = 0;
    _294_i = 0;
    goto BB1;
BB1:
    _292_t3 = 10;
    _292_t4 = _294_i <= _292_t3;
    if (_292_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _293_x = $add_int64_t(_293_x, _294_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _292_t6 = 1;
    _294_i = $add_int64_t(_294_i, _292_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _292_$retval = _293_x;
    return _292_$retval;
}

int main(void) {
  printf("%ld",_292_main());
  return 0;
}
