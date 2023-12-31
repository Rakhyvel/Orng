/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1615_main(void);

/* Function definitions */
int64_t _1615_main(void){
    int64_t _1616_x;
    int64_t* _1616_y;
    int64_t _1615_t3;
    uint8_t _1615_t5;
    int64_t _1615_t2;
    int64_t _1615_$retval;
    int64_t _1615_t7;
    uint8_t _1615_t8;
    int64_t _1615_t9;
    uint8_t _1615_t10;
    _1616_x = 3;
    _1616_y = &_1616_x;
    _1615_t3 = 5;
    _1615_t5 = *_1616_y==_1615_t3;
    if (_1615_t5) {
        goto BB1915;
    } else {
        goto BB1917;
    }
BB1915:
    _1615_t7 = 4;
    _1615_t8 = _1615_t7>*_1616_y;
    if (_1615_t8) {
        goto BB1917;
    } else {
        goto BB1922;
    }
BB1917:
    _1615_t9 = 3;
    _1615_t10 = *_1616_y>=_1615_t9;
    if (_1615_t10) {
        goto BB1918;
    } else {
        goto BB1922;
    }
BB1922:
    _1615_t2 = 10;
    goto BB1921;
BB1918:
    _1615_t2 = 33;
    goto BB1921;
BB1921:
    _1615_$retval = _1615_t2;
    return _1615_$retval;
}

int main(void) {
  printf("%ld",_1615_main());
  return 0;
}
