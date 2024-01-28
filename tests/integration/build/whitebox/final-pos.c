/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1737_main(void);


/* Function definitions */
int64_t _1737_main(void){
    int64_t _1738_x;
    int64_t _1737_t2;
    uint8_t _1737_t3;
    int64_t _1737_t5;
    uint8_t _1737_t7;
    int64_t _1737_t10;
    int64_t _1737_$retval;
    int64_t _1737_t8;
    _1738_x = 0;
    goto BB1988;
BB1988:
    _1737_t2 = 100;
    _1737_t3 = _1738_x<_1737_t2;
    if (_1737_t3) {
        goto BB1989;
    } else {
        goto BB1994;
    }
BB1989:
    _1737_t5 = 40;
    _1737_t7 = _1738_x==_1737_t5;
    if (_1737_t7) {
        goto BB1992;
    } else {
        goto BB1998;
    }
BB1994:
    _1737_$retval = _1738_x;
    return _1737_$retval;
BB1992:
    _1737_t8 = 1;
    _1738_x = $add_int64_t(_1738_x, _1737_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1994;
BB1998:
    _1737_t10 = 1;
    _1738_x = $add_int64_t(_1738_x, _1737_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1988;
}


int main(void) {
  printf("%ld",_1737_main());
  return 0;
}
