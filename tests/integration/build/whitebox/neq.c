/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1987_main(void);


/* Function definitions */
int64_t _1987_main(void){
    int64_t _1988_x;
    int64_t* _1988_y;
    int64_t _1987_t5;
    uint8_t _1987_t7;
    int64_t _1987_t4;
    int64_t _1987_$retval;
    int64_t _1987_t9;
    uint8_t _1987_t10;
    int64_t _1987_t11;
    uint8_t _1987_t12;
    _1988_x = 3;
    _1988_y = &_1988_x;
    _1987_t5 = 5;
    _1987_t7 = *_1988_y==_1987_t5;
    if (_1987_t7) {
        goto BB2179;
    } else {
        goto BB2181;
    }
BB2179:
    _1987_t9 = 4;
    _1987_t10 = _1987_t9>*_1988_y;
    if (_1987_t10) {
        goto BB2181;
    } else {
        goto BB2186;
    }
BB2181:
    _1987_t11 = 3;
    _1987_t12 = *_1988_y>=_1987_t11;
    if (_1987_t12) {
        goto BB2182;
    } else {
        goto BB2186;
    }
BB2186:
    _1987_t4 = 10;
    goto BB2185;
BB2182:
    _1987_t4 = 33;
    goto BB2185;
BB2185:
    _1987_$retval = _1987_t4;
    return _1987_$retval;
}


int main(void) {
  printf("%ld",_1987_main());
  return 0;
}
