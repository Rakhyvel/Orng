/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1585_main(void);

/* Function definitions */
int64_t _1585_main(void){
    int64_t _1586_x;
    int64_t* _1586_y;
    int64_t _1585_t3;
    uint8_t _1585_t5;
    int64_t _1585_t2;
    int64_t _1585_$retval;
    int64_t _1585_t7;
    uint8_t _1585_t8;
    int64_t _1585_t9;
    uint8_t _1585_t10;
    _1586_x = 3;
    _1586_y = &_1586_x;
    _1585_t3 = 5;
    _1585_t5 = *_1586_y==_1585_t3;
    if (_1585_t5) {
        goto BB1914;
    } else {
        goto BB1916;
    }
BB1914:
    _1585_t7 = 4;
    _1585_t8 = _1585_t7>*_1586_y;
    if (_1585_t8) {
        goto BB1916;
    } else {
        goto BB1921;
    }
BB1916:
    _1585_t9 = 3;
    _1585_t10 = *_1586_y>=_1585_t9;
    if (_1585_t10) {
        goto BB1917;
    } else {
        goto BB1921;
    }
BB1921:
    _1585_t2 = 10;
    goto BB1920;
BB1917:
    _1585_t2 = 33;
    goto BB1920;
BB1920:
    _1585_$retval = _1585_t2;
    return _1585_$retval;
}

int main(void) {
  printf("%ld",_1585_main());
  return 0;
}
