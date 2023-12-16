/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _408_main(void);

/* Function definitions */
int64_t _408_main(void){
    int64_t _409_x;
    int64_t _410_i;
    int64_t _408_t3;
    uint8_t _408_t4;
    int64_t _408_t6;
    int64_t _408_$retval;
    _409_x = 0;
    _410_i = 0;
    goto BB1;
BB1:
    _408_t3 = 10;
    _408_t4 = _410_i <= _408_t3;
    if (_408_t4) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _409_x = $add_int64_t(_409_x, _410_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _408_t6 = 1;
    _410_i = $add_int64_t(_410_i, _408_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB1;
BB7:
    _408_$retval = _409_x;
    return _408_$retval;
}

int main(void) {
  printf("%ld",_408_main());
  return 0;
}
