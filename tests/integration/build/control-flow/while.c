/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _481_main(void);

/* Function definitions */
int64_t _481_main(void){
    int64_t _482_x;
    int64_t _483_i;
    int64_t _481_t3;
    uint8_t _481_t4;
    int64_t _481_t6;
    int64_t _481_$retval;
    _482_x = 0;
    _483_i = 0;
    goto BB1;
BB1:
    _481_t3 = 10;
    _481_t4 = _483_i <= _481_t3;
    if (_481_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _482_x = $add_int64_t(_482_x, _483_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _481_t6 = 1;
    _483_i = $add_int64_t(_483_i, _481_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _481_$retval = _482_x;
    return _481_$retval;
}

int main(void) {
  printf("%ld",_481_main());
  return 0;
}
