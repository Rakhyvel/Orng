/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _564_main(void);

/* Function definitions */
int64_t _564_main(void){
    int64_t _565_x;
    int64_t _566_i;
    int64_t _564_t3;
    uint8_t _564_t4;
    int64_t _564_t6;
    int64_t _564_$retval;
    _565_x = 0;
    _566_i = 0;
    goto BB1;
BB1:
    _564_t3 = 10;
    _564_t4 = _566_i <= _564_t3;
    if (_564_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _565_x = $add_int64_t(_565_x, _566_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _564_t6 = 1;
    _566_i = $add_int64_t(_566_i, _564_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _564_$retval = _565_x;
    return _564_$retval;
}

int main(void) {
  printf("%ld",_564_main());
  return 0;
}
