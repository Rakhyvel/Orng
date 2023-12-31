/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1586_main(void);

/* Function definitions */
int64_t _1586_main(void){
    int64_t _1587_x;
    int64_t _1586_t2;
    uint8_t _1586_t3;
    int64_t _1586_t5;
    uint8_t _1586_t7;
    int64_t _1586_$retval;
    int64_t _1586_t10;
    int64_t _1586_t8;
    _1587_x = 0;
    goto BB1871;
BB1871:
    _1586_t2 = 100;
    _1586_t3 = _1587_x<_1586_t2;
    if (_1586_t3) {
        goto BB1872;
    } else {
        goto BB1877;
    }
BB1872:
    _1586_t5 = 40;
    _1586_t7 = _1587_x==_1586_t5;
    if (_1586_t7) {
        goto BB1875;
    } else {
        goto BB1881;
    }
BB1877:
    _1586_$retval = _1587_x;
    return _1586_$retval;
BB1875:
    _1586_t8 = 1;
    _1587_x = $add_int64_t(_1587_x, _1586_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1877;
BB1881:
    _1586_t10 = 1;
    _1587_x = $add_int64_t(_1587_x, _1586_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1871;
}

int main(void) {
  printf("%ld",_1586_main());
  return 0;
}
