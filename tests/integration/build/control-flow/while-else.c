/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _469_main(void);

/* Function definitions */
int64_t _469_main(void){
    int64_t _471_x;
    int64_t _469_t2;
    uint8_t _469_t3;
    int64_t _469_t4;
    int64_t _469_t7;
    int64_t _469_$retval;
    _471_x = 0;
    goto BB562;
BB562:
    _469_t2 = 10;
    _469_t3 = _471_x<_469_t2;
    if (_469_t3) {
        goto BB563;
    } else {
        goto BB567;
    }
BB563:
    _469_t4 = 1;
    _471_x = $add_int64_t(_471_x, _469_t4, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _469_t7 = 1;
    _471_x = $add_int64_t(_471_x, _469_t7, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB562;
BB567:
    _469_$retval = _471_x;
    return _469_$retval;
}

int main(void) {
  printf("%ld",_469_main());
  return 0;
}
