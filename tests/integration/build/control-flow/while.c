/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _379_main(void);

/* Function definitions */
int64_t _379_main(void) {
    int64_t _380_x;
    int64_t _382_i;
    int64_t _379_t3;
    uint8_t _379_t4;
    int64_t _379_t6;
    int64_t _379_$retval;
    _380_x = 0;
    _382_i = 0;
    goto BB1;
BB1:
    _379_t3 = 10;
    _379_t4 = _382_i <= _379_t3;
    if (_379_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _380_x = $add_int64_t(_380_x, _382_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _379_t6 = 1;
    _382_i = $add_int64_t(_382_i, _379_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _379_$retval = _380_x;
    return _379_$retval;
}

int main(void) {
  printf("%ld",_379_main());
  return 0;
}
