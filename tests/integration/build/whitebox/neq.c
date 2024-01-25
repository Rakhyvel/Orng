/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1722_main(void);


/* Function definitions */
int64_t _1722_main(void){
    int64_t _1723_x;
    int64_t* _1723_y;
    int64_t _1722_t3;
    uint8_t _1722_t5;
    int64_t _1722_t2;
    int64_t _1722_$retval;
    int64_t _1722_t7;
    uint8_t _1722_t8;
    int64_t _1722_t9;
    uint8_t _1722_t10;
    _1723_x = 3;
    _1723_y = &_1723_x;
    _1722_t3 = 5;
    _1722_t5 = *_1723_y==_1722_t3;
    if (_1722_t5) {
        goto BB1992;
    } else {
        goto BB1994;
    }
BB1992:
    _1722_t7 = 4;
    _1722_t8 = _1722_t7>*_1723_y;
    if (_1722_t8) {
        goto BB1994;
    } else {
        goto BB1999;
    }
BB1994:
    _1722_t9 = 3;
    _1722_t10 = *_1723_y>=_1722_t9;
    if (_1722_t10) {
        goto BB1995;
    } else {
        goto BB1999;
    }
BB1999:
    _1722_t2 = 10;
    goto BB1998;
BB1995:
    _1722_t2 = 33;
    goto BB1998;
BB1998:
    _1722_$retval = _1722_t2;
    return _1722_$retval;
}


int main(void) {
  printf("%ld",_1722_main());
  return 0;
}
