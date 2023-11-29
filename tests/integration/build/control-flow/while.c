/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _377_main(void);

/* Function definitions */
int64_t _377_main(void) {
    int64_t _378_x;
    int64_t _380_i;
    int64_t _377_t3;
    uint8_t _377_t4;
    int64_t _377_t6;
    int64_t _377_$retval;
    _378_x = 0;
    _380_i = 0;
    goto BB1;
BB1:
    _377_t3 = 10;
    _377_t4 = _380_i <= _377_t3;
    if (_377_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _378_x = $add_int64_t(_378_x, _380_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _377_t6 = 1;
    _380_i = $add_int64_t(_380_i, _377_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _377_$retval = _378_x;
    return _377_$retval;
}

int main(void) {
  printf("%ld",_377_main());
  return 0;
}
