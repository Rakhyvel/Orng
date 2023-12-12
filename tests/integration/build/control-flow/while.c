/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _259_main(void);

/* Function definitions */
int64_t _259_main(void) {
    int64_t _260_x;
    int64_t _261_i;
    int64_t _259_t3;
    uint8_t _259_t4;
    int64_t _259_t6;
    int64_t _259_$retval;
    _260_x = 0;
    _261_i = 0;
    goto BB1;
BB1:
    _259_t3 = 10;
    _259_t4 = _261_i <= _259_t3;
    if (_259_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _260_x = $add_int64_t(_260_x, _261_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _259_t6 = 1;
    _261_i = $add_int64_t(_261_i, _259_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _259_$retval = _260_x;
    return _259_$retval;
}

int main(void) {
  printf("%ld",_259_main());
  return 0;
}
