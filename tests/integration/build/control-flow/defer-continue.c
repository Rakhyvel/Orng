/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _219_main(void);

/* Function definitions */
int64_t _219_main(void) {
    int64_t _220_x;
    int64_t _219_t2;
    uint8_t _219_t3;
    int64_t _219_t5;
    int64_t _219_t6;
    int64_t _219_t7;
    uint8_t _219_t9;
    int64_t _219_t10;
    int64_t _219_$retval;
    int64_t _219_t12;
    _220_x = 17;
    goto BB1;
BB1:
    _219_t2 = 36;
    _219_t3 = _220_x < _219_t2;
    if (_219_t3) {
        goto BB2;
    } else {
        goto BB14;
    }
BB2:
    _219_t5 = 2;
    _219_t6 = $mod_int64_t(_220_x, _219_t5, "tests/integration/control-flow/defer-continue.orng:6:15:\n        if x % 2 == 0 {continue}\n             ^");
    _219_t7 = 0;
    _219_t9 = _219_t6 == _219_t7;
    if (_219_t9) {
        goto BB6;
    } else {
        goto BB10;
    }
BB14:
    _219_$retval = _220_x;
    return _219_$retval;
BB6:
    _219_t12 = 9;
    _220_x = $add_int64_t(_220_x, _219_t12, "tests/integration/control-flow/defer-continue.orng:5:19:\n        defer x += 9\n                 ^");
    goto BB1;
BB10:
    _219_t10 = 1;
    _220_x = $add_int64_t(_220_x, _219_t10, "tests/integration/control-flow/defer-continue.orng:7:13:\n        x += 1\n           ^");
    goto BB6;
}

int main(void) {
  printf("%ld",_219_main());
  return 0;
}
