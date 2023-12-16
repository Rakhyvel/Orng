/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _419_main(void);

/* Function definitions */
int64_t _419_main(void){
    int64_t _420_x;
    int64_t _421_i;
    int64_t _419_t3;
    uint8_t _419_t4;
    int64_t _419_t6;
    int64_t _419_$retval;
    _420_x = 0;
    _421_i = 0;
    goto BB1;
BB1:
    _419_t3 = 10;
    _419_t4 = _421_i <= _419_t3;
    if (_419_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _420_x = $add_int64_t(_420_x, _421_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _419_t6 = 1;
    _421_i = $add_int64_t(_421_i, _419_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _419_$retval = _420_x;
    return _419_$retval;
}

int main(void) {
  printf("%ld",_419_main());
  return 0;
}
