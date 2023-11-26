/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _180_main(void);

/* Function definitions */
int64_t _180_main(void) {
    int64_t _182_x;
    int64_t _180_t2;
    uint8_t _180_t3;
    int64_t _180_t4;
    int64_t _180_t7;
    int64_t _180_$retval;
    _182_x = 0;
    goto BB1;
BB1:
    _180_t2 = 10;
    _180_t3 = _182_x < _180_t2;
    if (_180_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _180_t4 = 1;
    _182_x = $add_int64_t(_182_x, _180_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _180_t7 = 1;
    _182_x = $add_int64_t(_182_x, _180_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB1;
BB6:
    _180_$retval = _182_x;
    return _180_$retval;
}

int main(void) {
  printf("%ld",_180_main());
  return 0;
}
