/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _554_main(void);

/* Function definitions */
int64_t _554_main(void){
    int64_t _556_x;
    int64_t _554_t2;
    uint8_t _554_t3;
    int64_t _554_t4;
    int64_t _554_t7;
    int64_t _554_$retval;
    _556_x = 0;
    goto BB1;
BB1:
    _554_t2 = 10;
    _554_t3 = _556_x < _554_t2;
    if (_554_t3) {
        goto BB2;
    } else {
        goto BB6;
    }
BB2:
    _554_t4 = 1;
    _556_x = $add_int64_t(_556_x, _554_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _554_t7 = 1;
    _556_x = $add_int64_t(_556_x, _554_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB1;
BB6:
    _554_$retval = _556_x;
    return _554_$retval;
}

int main(void) {
  printf("%ld",_554_main());
  return 0;
}
