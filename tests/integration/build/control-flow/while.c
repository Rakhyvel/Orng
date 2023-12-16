/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _400_main(void);

/* Function definitions */
int64_t _400_main(void) {
    int64_t _401_x;
    int64_t _402_i;
    int64_t _400_t3;
    uint8_t _400_t4;
    int64_t _400_t6;
    int64_t _400_$retval;
    _401_x = 0;
    _402_i = 0;
    goto BB1;
BB1:
    _400_t3 = 10;
    _400_t4 = _402_i <= _400_t3;
    if (_400_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _401_x = $add_int64_t(_401_x, _402_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _400_t6 = 1;
    _402_i = $add_int64_t(_402_i, _400_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _400_$retval = _401_x;
    return _400_$retval;
}

int main(void) {
  printf("%ld",_400_main());
  return 0;
}
