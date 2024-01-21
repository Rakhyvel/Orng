/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1622_main(void);

/* Function definitions */
int64_t _1622_main(void){
    int64_t _1623_x;
    int64_t _1622_t2;
    uint8_t _1622_t3;
    int64_t _1622_t5;
    uint8_t _1622_t7;
    int64_t _1622_t10;
    int64_t _1622_$retval;
    int64_t _1622_t8;
    _1623_x = 0;
    goto BB1886;
BB1886:
    _1622_t2 = 100;
    _1622_t3 = _1623_x<_1622_t2;
    if (_1622_t3) {
        goto BB1887;
    } else {
        goto BB1892;
    }
BB1887:
    _1622_t5 = 40;
    _1622_t7 = _1623_x==_1622_t5;
    if (_1622_t7) {
        goto BB1890;
    } else {
        goto BB1896;
    }
BB1892:
    _1622_$retval = _1623_x;
    return _1622_$retval;
BB1890:
    _1622_t8 = 1;
    _1623_x = $add_int64_t(_1623_x, _1622_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1892;
BB1896:
    _1622_t10 = 1;
    _1623_x = $add_int64_t(_1623_x, _1622_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1886;
}

int main(void) {
  printf("%ld",_1622_main());
  return 0;
}
