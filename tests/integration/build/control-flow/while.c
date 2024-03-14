/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _517_main(void);


/* Function definitions */
int64_t _517_main(void){
    int64_t _518_x;
    int64_t _519_i;
    int64_t _517_t5;
    uint8_t _517_t6;
    int64_t _517_t8;
    int64_t _517_$retval;
    _518_x = 0;
    _519_i = 0;
    goto BB591;
BB591:
    _517_t5 = 10;
    _517_t6 = _519_i<=_517_t5;
    if (_517_t6) {
        goto BB592;
    } else {
        goto BB597;
    }
BB592:
    _518_x = $add_int64_t(_518_x, _519_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _517_t8 = 1;
    _519_i = $add_int64_t(_519_i, _517_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB591;
BB597:
    _517_$retval = _518_x;
    return _517_$retval;
}


int main(void) {
  printf("%ld",_517_main());
  return 0;
}
