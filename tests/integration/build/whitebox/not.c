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
int64_t _1868_main(void);
int64_t _1870_f(uint8_t _1870_b);


/* Function definitions */
int64_t _1868_main(void){
    int64_t _1869_x;
    int64_t* _1869_y;
    function0 _1868_t4;
    int64_t _1868_t6;
    uint8_t _1868_t8;
    uint8_t _1868_t7;
    uint8_t _1868_t9;
    int64_t _1868_t5;
    int64_t _1868_$retval;
    _1869_x = 0;
    _1869_y = &_1869_x;
    _1868_t4 = (function0) _1870_f;
    _1868_t6 = 1;
    _1868_t8 = *_1869_y==_1868_t6;
    if (_1868_t8) {
        goto BB2094;
    } else {
        goto BB2097;
    }
BB2094:
    _1868_t7 = 1;
    goto BB2095;
BB2097:
    _1868_t7 = 0;
    goto BB2095;
BB2095:
    _1868_t9 = !_1868_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1868_t5 = _1868_t4(_1868_t9);
    $line_idx--;
    _1868_$retval = _1868_t5;
    return _1868_$retval;
}

int64_t _1870_f(uint8_t _1870_b){
    uint8_t _1870_t0;
    uint8_t _1870_t1;
    int64_t _1870_t2;
    int64_t _1870_$retval;
    _1870_t0 = !_1870_b;
    _1870_b = _1870_t0;
    _1870_t1 = !_1870_t0;
    _1870_b = _1870_t1;
    if (_1870_t0) {
        goto BB2091;
    } else {
        goto BB2087;
    }
BB2091:
    _1870_t2 = 10;
    goto BB2090;
BB2087:
    _1870_t2 = 31;
    goto BB2090;
BB2090:
    _1870_$retval = _1870_t2;
    return _1870_$retval;
}


int main(void) {
  printf("%ld",_1868_main());
  return 0;
}
