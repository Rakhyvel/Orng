/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1766_main(void);


/* Function definitions */
int64_t _1766_main(void){
    int64_t _1767_x;
    int64_t* _1767_y;
    int64_t _1766_t3;
    uint8_t _1766_t5;
    int64_t _1766_t2;
    int64_t _1766_$retval;
    int64_t _1766_t7;
    uint8_t _1766_t8;
    int64_t _1766_t9;
    uint8_t _1766_t10;
    _1767_x = 3;
    _1767_y = &_1767_x;
    _1766_t3 = 5;
    _1766_t5 = *_1767_y==_1766_t3;
    if (_1766_t5) {
        goto BB2032;
    } else {
        goto BB2034;
    }
BB2032:
    _1766_t7 = 4;
    _1766_t8 = _1766_t7>*_1767_y;
    if (_1766_t8) {
        goto BB2034;
    } else {
        goto BB2039;
    }
BB2034:
    _1766_t9 = 3;
    _1766_t10 = *_1767_y>=_1766_t9;
    if (_1766_t10) {
        goto BB2035;
    } else {
        goto BB2039;
    }
BB2039:
    _1766_t2 = 10;
    goto BB2038;
BB2035:
    _1766_t2 = 33;
    goto BB2038;
BB2038:
    _1766_$retval = _1766_t2;
    return _1766_$retval;
}


int main(void) {
  printf("%ld",_1766_main());
  return 0;
}
