/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1618_main(void);

/* Function definitions */
int64_t _1618_main(void){
    int64_t _1619_x;
    int64_t* _1619_y;
    int64_t _1618_t3;
    uint8_t _1618_t5;
    int64_t _1618_t2;
    int64_t _1618_$retval;
    int64_t _1618_t7;
    uint8_t _1618_t8;
    int64_t _1618_t9;
    uint8_t _1618_t10;
    _1619_x = 3;
    _1619_y = &_1619_x;
    _1618_t3 = 5;
    _1618_t5 = *_1619_y==_1618_t3;
    if (_1618_t5) {
        goto BB1907;
    } else {
        goto BB1909;
    }
BB1907:
    _1618_t7 = 4;
    _1618_t8 = _1618_t7>*_1619_y;
    if (_1618_t8) {
        goto BB1909;
    } else {
        goto BB1914;
    }
BB1909:
    _1618_t9 = 3;
    _1618_t10 = *_1619_y>=_1618_t9;
    if (_1618_t10) {
        goto BB1910;
    } else {
        goto BB1914;
    }
BB1914:
    _1618_t2 = 10;
    goto BB1913;
BB1910:
    _1618_t2 = 33;
    goto BB1913;
BB1913:
    _1618_$retval = _1618_t2;
    return _1618_$retval;
}

int main(void) {
  printf("%ld",_1618_main());
  return 0;
}
