/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _396_main(void);

/* Function definitions */
int64_t _396_main(void){
    int64_t _397_x;
    int64_t _398_i;
    int64_t _396_t3;
    uint8_t _396_t4;
    int64_t _396_t6;
    int64_t _396_t7;
    int64_t _396_t8;
    uint8_t _396_t10;
    int64_t _396_$retval;
    int64_t _396_t11;
    int64_t _396_t13;
    _397_x = 0;
    _398_i = 0;
    goto BB463;
BB463:
    _396_t3 = 70;
    _396_t4 = _398_i<_396_t3;
    if (_396_t4) {
        goto BB464;
    } else {
        goto BB475;
    }
BB464:
    _396_t6 = 2;
    _396_t7 = $mod_int64_t(_398_i, _396_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _396_t8 = 0;
    _396_t10 = _396_t7==_396_t8;
    if (_396_t10) {
        goto BB468;
    } else {
        goto BB470;
    }
BB475:
    _396_$retval = _397_x;
    return _396_$retval;
BB468:
    _396_t13 = 1;
    _398_i = $add_int64_t(_398_i, _396_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB463;
BB470:
    _396_t11 = 1;
    _397_x = $add_int64_t(_397_x, _396_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB468;
}

int main(void) {
  printf("%ld",_396_main());
  return 0;
}
