/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _328_main(void);

/* Function definitions */
int64_t _328_main(void){
    int64_t _329_x;
    int64_t _330_i;
    int64_t _328_t3;
    uint8_t _328_t4;
    int64_t _328_t6;
    int64_t _328_t7;
    int64_t _328_t8;
    uint8_t _328_t10;
    int64_t _328_t11;
    int64_t _328_t13;
    int64_t _328_$retval;
    _329_x = 36;
    _330_i = 0;
    goto BB1;
BB1:
    _328_t3 = 70;
    _328_t4 = _330_i < _328_t3;
    if (_328_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _328_t6 = 2;
    _328_t7 = $mod_int64_t(_330_i, _328_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _328_t8 = 0;
    _328_t10 = _328_t7 == _328_t8;
    if (_328_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _329_x = 10;
    goto BB7;
BB7:
    _328_$retval = _329_x;
    return _328_$retval;
BB9:
    _328_t11 = 1;
    _329_x = $add_int64_t(_329_x, _328_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _328_t13 = 1;
    _330_i = $add_int64_t(_330_i, _328_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_328_main());
  return 0;
}
