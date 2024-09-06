/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _421_main(void);


/* Function definitions */
int64_t _421_main(void){
    int64_t _422_x;
    int64_t _423_i;
    int64_t _421_t5;
    uint8_t _421_t6;
    int64_t _421_t8;
    int64_t _421_t9;
    int64_t _421_t10;
    uint8_t _421_t12;
    int64_t _421_t13;
    int64_t _421_t15;
    int64_t _421_$retval;
    _422_x = 36;
    _423_i = 0;
    goto BB457;
BB457:
    _421_t5 = 70;
    _421_t6 = _423_i<_421_t5;
    if (_421_t6) {
        goto BB458;
    } else {
        goto BB469;
    }
BB458:
    _421_t8 = 2;
    _421_t9 = $mod_int64_t(_423_i, _421_t8, "tests/integration/control-flow/break.orng:5:15:\n        if i % 2 == 0 {\n             ^");
    _421_t10 = 0;
    _421_t12 = _421_t9==_421_t10;
    if (_421_t12) {
        goto BB463;
    } else {
        goto BB465;
    }
BB469:
    _422_x = 10;
    goto BB463;
BB463:
    _421_$retval = _422_x;
    return _421_$retval;
BB465:
    _421_t13 = 1;
    _422_x = $add_int64_t(_422_x, _421_t13, "tests/integration/control-flow/break.orng:8:13:\n        x += 1\n           ^");
    _421_t15 = 1;
    _423_i = $add_int64_t(_423_i, _421_t15, "tests/integration/control-flow/break.orng:4:38:\n    while let mut i = 0; i < 70; i += 1 {\n                                    ^");
    goto BB457;
}


int main(void) {
  printf("%ld",_421_main());
  return 0;
}
