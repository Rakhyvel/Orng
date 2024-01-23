/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1695_main(void);


/* Function definitions */
int64_t _1695_main(void){
    int64_t _1696_x;
    int64_t* _1696_y;
    int64_t _1695_t3;
    uint8_t _1695_t5;
    int64_t _1695_t2;
    int64_t _1695_$retval;
    int64_t _1695_t7;
    uint8_t _1695_t8;
    int64_t _1695_t9;
    uint8_t _1695_t10;
    _1696_x = 3;
    _1696_y = &_1696_x;
    _1695_t3 = 5;
    _1695_t5 = *_1696_y==_1695_t3;
    if (_1695_t5) {
        goto BB1970;
    } else {
        goto BB1972;
    }
BB1970:
    _1695_t7 = 4;
    _1695_t8 = _1695_t7>*_1696_y;
    if (_1695_t8) {
        goto BB1972;
    } else {
        goto BB1977;
    }
BB1972:
    _1695_t9 = 3;
    _1695_t10 = *_1696_y>=_1695_t9;
    if (_1695_t10) {
        goto BB1973;
    } else {
        goto BB1977;
    }
BB1977:
    _1695_t2 = 10;
    goto BB1976;
BB1973:
    _1695_t2 = 33;
    goto BB1976;
BB1976:
    _1695_$retval = _1695_t2;
    return _1695_$retval;
}


int main(void) {
  printf("%ld",_1695_main());
  return 0;
}
