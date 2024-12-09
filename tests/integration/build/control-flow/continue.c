/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _427_main(void);


/* Function definitions */
int64_t _427_main(void){
    int64_t _428_x;
    int64_t _429_i;
    int64_t _427_t5;
    uint8_t _427_t6;
    int64_t _427_t8;
    int64_t _427_t9;
    int64_t _427_t10;
    uint8_t _427_t12;
    int64_t _427_$retval;
    int64_t _427_t13;
    int64_t _427_t15;
    _428_x = 0;
    _429_i = 0;
    goto BB469;
BB469:
    _427_t5 = 70;
    _427_t6 = _429_i<_427_t5;
    if (_427_t6) {
        goto BB470;
    } else {
        goto BB481;
    }
BB470:
    _427_t8 = 2;
    _427_t9 = $mod_int64_t(_429_i, _427_t8, "tests/integration/control-flow/continue.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _427_t10 = 0;
    _427_t12 = _427_t9==_427_t10;
    if (_427_t12) {
        goto BB474;
    } else {
        goto BB476;
    }
BB481:
    _427_$retval = _428_x;
    return _427_$retval;
BB474:
    _427_t15 = 1;
    _429_i = $add_int64_t(_429_i, _427_t15, "tests/integration/control-flow/continue.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB469;
BB476:
    _427_t13 = 1;
    _428_x = $add_int64_t(_428_x, _427_t13, "tests/integration/control-flow/continue.orng:8:13:\n        x += 1\n           ^");
    goto BB474;
}


int main(void) {
  printf("%ld",_427_main());
  return 0;
}
