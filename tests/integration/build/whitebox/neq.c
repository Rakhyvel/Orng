/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1633_main(void);

/* Function definitions */
int64_t _1633_main(void){
    int64_t _1634_x;
    int64_t* _1634_y;
    int64_t _1633_t3;
    uint8_t _1633_t5;
    int64_t _1633_t2;
    int64_t _1633_$retval;
    int64_t _1633_t7;
    uint8_t _1633_t8;
    int64_t _1633_t9;
    uint8_t _1633_t10;
    _1634_x = 3;
    _1634_y = &_1634_x;
    _1633_t3 = 5;
    _1633_t5 = *_1634_y==_1633_t3;
    if (_1633_t5) {
        goto BB1923;
    } else {
        goto BB1925;
    }
BB1923:
    _1633_t7 = 4;
    _1633_t8 = _1633_t7>*_1634_y;
    if (_1633_t8) {
        goto BB1925;
    } else {
        goto BB1930;
    }
BB1925:
    _1633_t9 = 3;
    _1633_t10 = *_1634_y>=_1633_t9;
    if (_1633_t10) {
        goto BB1926;
    } else {
        goto BB1930;
    }
BB1930:
    _1633_t2 = 10;
    goto BB1929;
BB1926:
    _1633_t2 = 33;
    goto BB1929;
BB1929:
    _1633_$retval = _1633_t2;
    return _1633_$retval;
}

int main(void) {
  printf("%ld",_1633_main());
  return 0;
}
