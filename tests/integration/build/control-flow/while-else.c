/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _478_main(void);

/* Function definitions */
int64_t _478_main(void){
    int64_t _480_x;
    int64_t _478_t2;
    uint8_t _478_t3;
    int64_t _478_t4;
    int64_t _478_t7;
    int64_t _478_$retval;
    _480_x = 0;
    goto BB572;
BB572:
    _478_t2 = 10;
    _478_t3 = _480_x<_478_t2;
    if (_478_t3) {
        goto BB573;
    } else {
        goto BB577;
    }
BB573:
    _478_t4 = 1;
    _480_x = $add_int64_t(_480_x, _478_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _478_t7 = 1;
    _480_x = $add_int64_t(_480_x, _478_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB572;
BB577:
    _478_$retval = _480_x;
    return _478_$retval;
}

int main(void) {
  printf("%ld",_478_main());
  return 0;
}
