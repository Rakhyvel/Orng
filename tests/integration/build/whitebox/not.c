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
int64_t _1979_main(void);
int64_t _1981_f(uint8_t _1981_b);


/* Function definitions */
int64_t _1979_main(void){
    int64_t _1980_x;
    int64_t* _1980_y;
    function0 _1979_t4;
    int64_t _1979_t6;
    uint8_t _1979_t8;
    uint8_t _1979_t7;
    uint8_t _1979_t9;
    int64_t _1979_t5;
    int64_t _1979_$retval;
    _1980_x = 0;
    _1980_y = &_1980_x;
    _1979_t4 = (function0) _1981_f;
    _1979_t6 = 1;
    _1979_t8 = *_1980_y==_1979_t6;
    if (_1979_t8) {
        goto BB2178;
    } else {
        goto BB2181;
    }
BB2178:
    _1979_t7 = 1;
    goto BB2179;
BB2181:
    _1979_t7 = 0;
    goto BB2179;
BB2179:
    _1979_t9 = !_1979_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1979_t5 = _1979_t4(_1979_t9);
    $line_idx--;
    _1979_$retval = _1979_t5;
    return _1979_$retval;
}

int64_t _1981_f(uint8_t _1981_b){
    uint8_t _1981_t0;
    uint8_t _1981_t1;
    int64_t _1981_t2;
    int64_t _1981_$retval;
    _1981_t0 = !_1981_b;
    _1981_b = _1981_t0;
    _1981_t1 = !_1981_t0;
    _1981_b = _1981_t1;
    if (_1981_t0) {
        goto BB2175;
    } else {
        goto BB2171;
    }
BB2175:
    _1981_t2 = 10;
    goto BB2174;
BB2171:
    _1981_t2 = 31;
    goto BB2174;
BB2174:
    _1981_$retval = _1981_t2;
    return _1981_$retval;
}


int main(void) {
  printf("%ld",_1979_main());
  return 0;
}
