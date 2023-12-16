/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _317_main(void);

/* Function definitions */
int64_t _317_main(void){
    int64_t _318_x;
    int64_t _319_i;
    int64_t _317_t3;
    uint8_t _317_t4;
    int64_t _317_t6;
    int64_t _317_t7;
    int64_t _317_t8;
    uint8_t _317_t10;
    int64_t _317_t11;
    int64_t _317_t13;
    int64_t _317_$retval;
    _318_x = 36;
    _319_i = 0;
    goto BB1;
BB1:
    _317_t3 = 70;
    _317_t4 = _319_i < _317_t3;
    if (_317_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _317_t6 = 2;
    _317_t7 = $mod_int64_t(_319_i, _317_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _317_t8 = 0;
    _317_t10 = _317_t7 == _317_t8;
    if (_317_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _318_x = 10;
    goto BB7;
BB7:
    _317_$retval = _318_x;
    return _317_$retval;
BB9:
    _317_t11 = 1;
    _318_x = $add_int64_t(_318_x, _317_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _317_t13 = 1;
    _319_i = $add_int64_t(_319_i, _317_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_317_main());
  return 0;
}
