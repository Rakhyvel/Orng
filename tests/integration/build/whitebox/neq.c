/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1912_main(void);


/* Function definitions */
int64_t _1912_main(void){
    int64_t _1913_x;
    int64_t* _1913_y;
    int64_t _1912_t5;
    uint8_t _1912_t7;
    int64_t _1912_t4;
    int64_t _1912_$retval;
    int64_t _1912_t9;
    uint8_t _1912_t10;
    int64_t _1912_t11;
    uint8_t _1912_t12;
    _1913_x = 3;
    _1913_y = &_1913_x;
    _1912_t5 = 5;
    _1912_t7 = *_1913_y==_1912_t5;
    if (_1912_t7) {
        goto BB2134;
    } else {
        goto BB2136;
    }
BB2134:
    _1912_t9 = 4;
    _1912_t10 = _1912_t9>*_1913_y;
    if (_1912_t10) {
        goto BB2136;
    } else {
        goto BB2141;
    }
BB2136:
    _1912_t11 = 3;
    _1912_t12 = *_1913_y>=_1912_t11;
    if (_1912_t12) {
        goto BB2137;
    } else {
        goto BB2141;
    }
BB2141:
    _1912_t4 = 10;
    goto BB2140;
BB2137:
    _1912_t4 = 33;
    goto BB2140;
BB2140:
    _1912_$retval = _1912_t4;
    return _1912_$retval;
}


int main(void) {
  printf("%ld",_1912_main());
  return 0;
}
