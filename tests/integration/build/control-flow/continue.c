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
    goto BB454;
BB454:
    _396_t3 = 70;
    _396_t4 = _398_i<_396_t3;
    if (_396_t4) {
        goto BB455;
    } else {
        goto BB466;
    }
BB455:
    _396_t6 = 2;
    _396_t7 = $mod_int64_t(_398_i, _396_t6, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _396_t8 = 0;
    _396_t10 = _396_t7==_396_t8;
    if (_396_t10) {
        goto BB459;
    } else {
        goto BB461;
    }
BB466:
    _396_$retval = _397_x;
    return _396_$retval;
BB459:
    _396_t13 = 1;
    _398_i = $add_int64_t(_398_i, _396_t13, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB454;
BB461:
    _396_t11 = 1;
    _397_x = $add_int64_t(_397_x, _396_t11, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB459;
}


int main(void) {
  printf("%ld",_396_main());
  return 0;
}
