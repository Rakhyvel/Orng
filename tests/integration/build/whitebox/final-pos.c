/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1693_main(void);


/* Function definitions */
int64_t _1693_main(void){
    int64_t _1694_x;
    int64_t _1693_t2;
    uint8_t _1693_t3;
    int64_t _1693_t5;
    uint8_t _1693_t7;
    int64_t _1693_t10;
    int64_t _1693_$retval;
    int64_t _1693_t8;
    _1694_x = 0;
    goto BB1948;
BB1948:
    _1693_t2 = 100;
    _1693_t3 = _1694_x<_1693_t2;
    if (_1693_t3) {
        goto BB1949;
    } else {
        goto BB1954;
    }
BB1949:
    _1693_t5 = 40;
    _1693_t7 = _1694_x==_1693_t5;
    if (_1693_t7) {
        goto BB1952;
    } else {
        goto BB1958;
    }
BB1954:
    _1693_$retval = _1694_x;
    return _1693_$retval;
BB1952:
    _1693_t8 = 1;
    _1694_x = $add_int64_t(_1694_x, _1693_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB1954;
BB1958:
    _1693_t10 = 1;
    _1694_x = $add_int64_t(_1694_x, _1693_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1948;
}


int main(void) {
  printf("%ld",_1693_main());
  return 0;
}
