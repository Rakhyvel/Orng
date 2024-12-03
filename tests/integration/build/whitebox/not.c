/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(uint8_t);

/* Function forward definitions */
int64_t _1973_main(void);
int64_t _1975_f(uint8_t _1975_b);


/* Function definitions */
int64_t _1973_main(void){
    int64_t _1974_x;
    int64_t* _1974_y;
    function0 _1973_t4;
    int64_t _1973_t6;
    uint8_t _1973_t8;
    uint8_t _1973_t7;
    uint8_t _1973_t9;
    int64_t _1973_t5;
    int64_t _1973_$retval;
    _1974_x = 0;
    _1974_y = &_1974_x;
    _1973_t4 = (function0) _1975_f;
    _1973_t6 = 1;
    _1973_t8 = *_1974_y==_1973_t6;
    if (_1973_t8) {
        goto BB2175;
    } else {
        goto BB2178;
    }
BB2175:
    _1973_t7 = 1;
    goto BB2176;
BB2178:
    _1973_t7 = 0;
    goto BB2176;
BB2176:
    _1973_t9 = !_1973_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1973_t5 = _1973_t4(_1973_t9);
    $line_idx--;
    _1973_$retval = _1973_t5;
    return _1973_$retval;
}

int64_t _1975_f(uint8_t _1975_b){
    uint8_t _1975_t0;
    uint8_t _1975_t1;
    int64_t _1975_t2;
    int64_t _1975_$retval;
    _1975_t0 = !_1975_b;
    _1975_b = _1975_t0;
    _1975_t1 = !_1975_t0;
    _1975_b = _1975_t1;
    if (_1975_t0) {
        goto BB2172;
    } else {
        goto BB2168;
    }
BB2172:
    _1975_t2 = 10;
    goto BB2171;
BB2168:
    _1975_t2 = 31;
    goto BB2171;
BB2171:
    _1975_$retval = _1975_t2;
    return _1975_$retval;
}


int main(void) {
  printf("%ld",_1973_main());
  return 0;
}
