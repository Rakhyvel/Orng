/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1623_main(void);

/* Function definitions */
int64_t _1623_main(void){
    int64_t _1624_x;
    int64_t* _1624_y;
    int64_t _1623_t3;
    uint8_t _1623_t5;
    int64_t _1623_t2;
    int64_t _1623_$retval;
    int64_t _1623_t7;
    uint8_t _1623_t8;
    int64_t _1623_t9;
    uint8_t _1623_t10;
    _1624_x = 3;
    _1624_y = &_1624_x;
    _1623_t3 = 5;
    _1623_t5 = *_1624_y==_1623_t3;
    if (_1623_t5) {
        goto BB1911;
    } else {
        goto BB1913;
    }
BB1911:
    _1623_t7 = 4;
    _1623_t8 = _1623_t7>*_1624_y;
    if (_1623_t8) {
        goto BB1913;
    } else {
        goto BB1918;
    }
BB1913:
    _1623_t9 = 3;
    _1623_t10 = *_1624_y>=_1623_t9;
    if (_1623_t10) {
        goto BB1914;
    } else {
        goto BB1918;
    }
BB1918:
    _1623_t2 = 10;
    goto BB1917;
BB1914:
    _1623_t2 = 33;
    goto BB1917;
BB1917:
    _1623_$retval = _1623_t2;
    return _1623_$retval;
}

int main(void) {
  printf("%ld",_1623_main());
  return 0;
}
