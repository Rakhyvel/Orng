/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _473_main(void);

/* Function definitions */
int64_t _473_main(void){
    int64_t _474_x;
    int64_t _475_i;
    int64_t _473_t3;
    uint8_t _473_t4;
    int64_t _473_t6;
    int64_t _473_t7;
    int64_t _473_t8;
    uint8_t _473_t10;
    int64_t _473_t11;
    int64_t _473_t13;
    int64_t _473_$retval;
    _474_x = 36;
    _475_i = 0;
    goto BB1;
BB1:
    _473_t3 = 70;
    _473_t4 = _475_i < _473_t3;
    if (_473_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _473_t6 = 2;
    _473_t7 = $mod_int64_t(_475_i, _473_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _473_t8 = 0;
    _473_t10 = _473_t7 == _473_t8;
    if (_473_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _474_x = 10;
    goto BB7;
BB7:
    _473_$retval = _474_x;
    return _473_$retval;
BB9:
    _473_t11 = 1;
    _474_x = $add_int64_t(_474_x, _473_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _473_t13 = 1;
    _475_i = $add_int64_t(_475_i, _473_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_473_main());
  return 0;
}
