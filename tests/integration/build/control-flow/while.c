/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _192_main(void);

/* Function definitions */
int64_t _192_main(void) {
    int64_t _193_x;
    int64_t _194_i;
    int64_t _192_t3;
    uint8_t _192_t4;
    int64_t _192_t6;
    int64_t _192_$retval;
    _193_x = 0;
    _194_i = 0;
    goto BB1;
BB1:
    _192_t3 = 10;
    _192_t4 = _194_i <= _192_t3;
    if (_192_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _193_x = $add_int64_t(_193_x, _194_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _192_t6 = 1;
    _194_i = $add_int64_t(_194_i, _192_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _192_$retval = _193_x;
    return _192_$retval;
}

int main(void) {
  printf("%ld",_192_main());
  return 0;
}
