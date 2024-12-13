/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _435_main(void);


/* Function definitions */
int64_t _435_main(void){
    int64_t _436_x;
    int64_t _437_i;
    int64_t _435_t5;
    uint8_t _435_t6;
    int64_t _435_t8;
    int64_t _435_t9;
    int64_t _435_t10;
    uint8_t _435_t12;
    int64_t _435_t13;
    int64_t _435_t15;
    int64_t _435_$retval;
    _436_x = 36;
    _437_i = 0;
    goto BB472;
BB472:
    _435_t5 = 70;
    _435_t6 = _437_i<_435_t5;
    if (_435_t6) {
        goto BB473;
    } else {
        goto BB484;
    }
BB473:
    _435_t8 = 2;
    _435_t9 = $mod_int64_t(_437_i, _435_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _435_t10 = 0;
    _435_t12 = _435_t9==_435_t10;
    if (_435_t12) {
        goto BB478;
    } else {
        goto BB480;
    }
BB484:
    _436_x = 10;
    goto BB478;
BB478:
    _435_$retval = _436_x;
    return _435_$retval;
BB480:
    _435_t13 = 1;
    _436_x = $add_int64_t(_436_x, _435_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _435_t15 = 1;
    _437_i = $add_int64_t(_437_i, _435_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB472;
}


int main(void) {
  printf("%ld",_435_main());
  return 0;
}
