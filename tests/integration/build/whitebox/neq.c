/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1651_main(void);

/* Function definitions */
int64_t _1651_main(void){
    int64_t _1652_x;
    int64_t* _1652_y;
    int64_t _1651_t3;
    uint8_t _1651_t5;
    int64_t _1651_t2;
    int64_t _1651_$retval;
    int64_t _1651_t7;
    uint8_t _1651_t8;
    int64_t _1651_t9;
    uint8_t _1651_t10;
    _1652_x = 3;
    _1652_y = &_1652_x;
    _1651_t3 = 5;
    _1651_t5 = *_1652_y==_1651_t3;
    if (_1651_t5) {
        goto BB1930;
    } else {
        goto BB1932;
    }
BB1930:
    _1651_t7 = 4;
    _1651_t8 = _1651_t7>*_1652_y;
    if (_1651_t8) {
        goto BB1932;
    } else {
        goto BB1937;
    }
BB1932:
    _1651_t9 = 3;
    _1651_t10 = *_1652_y>=_1651_t9;
    if (_1651_t10) {
        goto BB1933;
    } else {
        goto BB1937;
    }
BB1937:
    _1651_t2 = 10;
    goto BB1936;
BB1933:
    _1651_t2 = 33;
    goto BB1936;
BB1936:
    _1651_$retval = _1651_t2;
    return _1651_$retval;
}

int main(void) {
  printf("%ld",_1651_main());
  return 0;
}
