/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _479_main(void);

/* Function definitions */
int64_t _479_main(void){
    int64_t _480_x;
    int64_t _481_i;
    int64_t _479_t3;
    uint8_t _479_t4;
    int64_t _479_t6;
    int64_t _479_$retval;
    _480_x = 0;
    _481_i = 0;
    goto BB1;
BB1:
    _479_t3 = 10;
    _479_t4 = _481_i <= _479_t3;
    if (_479_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _480_x = $add_int64_t(_480_x, _481_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _479_t6 = 1;
    _481_i = $add_int64_t(_481_i, _479_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _479_$retval = _480_x;
    return _479_$retval;
}

int main(void) {
  printf("%ld",_479_main());
  return 0;
}
