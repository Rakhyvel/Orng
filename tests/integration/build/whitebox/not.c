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
int64_t _1965_main(void);
int64_t _1967_f(uint8_t _1967_b);


/* Function definitions */
int64_t _1965_main(void){
    int64_t _1966_x;
    int64_t* _1966_y;
    function0 _1965_t4;
    int64_t _1965_t6;
    uint8_t _1965_t8;
    uint8_t _1965_t7;
    uint8_t _1965_t9;
    int64_t _1965_t5;
    int64_t _1965_$retval;
    _1966_x = 0;
    _1966_y = &_1966_x;
    _1965_t4 = (function0) _1967_f;
    _1965_t6 = 1;
    _1965_t8 = *_1966_y==_1965_t6;
    if (_1965_t8) {
        goto BB2169;
    } else {
        goto BB2172;
    }
BB2169:
    _1965_t7 = 1;
    goto BB2170;
BB2172:
    _1965_t7 = 0;
    goto BB2170;
BB2170:
    _1965_t9 = !_1965_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1965_t5 = _1965_t4(_1965_t9);
    $line_idx--;
    _1965_$retval = _1965_t5;
    return _1965_$retval;
}

int64_t _1967_f(uint8_t _1967_b){
    uint8_t _1967_t0;
    uint8_t _1967_t1;
    int64_t _1967_t2;
    int64_t _1967_$retval;
    _1967_t0 = !_1967_b;
    _1967_b = _1967_t0;
    _1967_t1 = !_1967_t0;
    _1967_b = _1967_t1;
    if (_1967_t0) {
        goto BB2166;
    } else {
        goto BB2162;
    }
BB2166:
    _1967_t2 = 10;
    goto BB2165;
BB2162:
    _1967_t2 = 31;
    goto BB2165;
BB2165:
    _1967_$retval = _1967_t2;
    return _1967_$retval;
}


int main(void) {
  printf("%ld",_1965_main());
  return 0;
}
