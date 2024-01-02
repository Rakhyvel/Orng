/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _387_main(void);

/* Function definitions */
int64_t _387_main(void){
    int64_t _388_x;
    int64_t _389_i;
    int64_t _387_t3;
    uint8_t _387_t4;
    int64_t _387_t6;
    int64_t _387_t7;
    int64_t _387_t8;
    uint8_t _387_t10;
    int64_t _387_t11;
    int64_t _387_t13;
    int64_t _387_$retval;
    _388_x = 36;
    _389_i = 0;
    goto BB439;
BB439:
    _387_t3 = 70;
    _387_t4 = _389_i<_387_t3;
    if (_387_t4) {
        goto BB440;
    } else {
        goto BB451;
    }
BB440:
    _387_t6 = 2;
    _387_t7 = $mod_int64_t(_389_i, _387_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _387_t8 = 0;
    _387_t10 = _387_t7==_387_t8;
    if (_387_t10) {
        goto BB445;
    } else {
        goto BB447;
    }
BB451:
    _388_x = 10;
    goto BB445;
BB445:
    _387_$retval = _388_x;
    return _387_$retval;
BB447:
    _387_t11 = 1;
    _388_x = $add_int64_t(_388_x, _387_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _387_t13 = 1;
    _389_i = $add_int64_t(_389_i, _387_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB439;
}

int main(void) {
  printf("%ld",_387_main());
  return 0;
}
