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
int64_t _1968_main(void);
int64_t _1970_f(uint8_t _1970_b);


/* Function definitions */
int64_t _1968_main(void){
    int64_t _1969_x;
    int64_t* _1969_y;
    function0 _1968_t4;
    int64_t _1968_t6;
    uint8_t _1968_t8;
    uint8_t _1968_t7;
    uint8_t _1968_t9;
    int64_t _1968_t5;
    int64_t _1968_$retval;
    _1969_x = 0;
    _1969_y = &_1969_x;
    _1968_t4 = (function0) _1970_f;
    _1968_t6 = 1;
    _1968_t8 = *_1969_y==_1968_t6;
    if (_1968_t8) {
        goto BB2171;
    } else {
        goto BB2174;
    }
BB2171:
    _1968_t7 = 1;
    goto BB2172;
BB2174:
    _1968_t7 = 0;
    goto BB2172;
BB2172:
    _1968_t9 = !_1968_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1968_t5 = _1968_t4(_1968_t9);
    $line_idx--;
    _1968_$retval = _1968_t5;
    return _1968_$retval;
}

int64_t _1970_f(uint8_t _1970_b){
    uint8_t _1970_t0;
    uint8_t _1970_t1;
    int64_t _1970_t2;
    int64_t _1970_$retval;
    _1970_t0 = !_1970_b;
    _1970_b = _1970_t0;
    _1970_t1 = !_1970_t0;
    _1970_b = _1970_t1;
    if (_1970_t0) {
        goto BB2168;
    } else {
        goto BB2164;
    }
BB2168:
    _1970_t2 = 10;
    goto BB2167;
BB2164:
    _1970_t2 = 31;
    goto BB2167;
BB2167:
    _1970_$retval = _1970_t2;
    return _1970_$retval;
}


int main(void) {
  printf("%ld",_1968_main());
  return 0;
}
