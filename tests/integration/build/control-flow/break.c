/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _388_main(void);

/* Function definitions */
int64_t _388_main(void){
    int64_t _389_x;
    int64_t _390_i;
    int64_t _388_t3;
    uint8_t _388_t4;
    int64_t _388_t6;
    int64_t _388_t7;
    int64_t _388_t8;
    uint8_t _388_t10;
    int64_t _388_t11;
    int64_t _388_t13;
    int64_t _388_$retval;
    _389_x = 36;
    _390_i = 0;
    goto BB1;
BB1:
    _388_t3 = 70;
    _388_t4 = _390_i < _388_t3;
    if (_388_t4) {
        goto BB2;
    } else {
        goto BB13;
    }
BB2:
    _388_t6 = 2;
    _388_t7 = $mod_int64_t(_390_i, _388_t6, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _388_t8 = 0;
    _388_t10 = _388_t7 == _388_t8;
    if (_388_t10) {
        goto BB7;
    } else {
        goto BB9;
    }
BB13:
    _389_x = 10;
    goto BB7;
BB7:
    _388_$retval = _389_x;
    return _388_$retval;
BB9:
    _388_t11 = 1;
    _389_x = $add_int64_t(_389_x, _388_t11, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _388_t13 = 1;
    _390_i = $add_int64_t(_390_i, _388_t13, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_388_main());
  return 0;
}
