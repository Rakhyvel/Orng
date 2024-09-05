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
int64_t _1918_main(void);
int64_t _1920_f(uint8_t _1920_b);


/* Function definitions */
int64_t _1918_main(void){
    int64_t _1919_x;
    int64_t* _1919_y;
    function0 _1918_t4;
    int64_t _1918_t6;
    uint8_t _1918_t8;
    uint8_t _1918_t7;
    uint8_t _1918_t9;
    int64_t _1918_t5;
    int64_t _1918_$retval;
    _1919_x = 0;
    _1919_y = &_1919_x;
    _1918_t4 = (function0) _1920_f;
    _1918_t6 = 1;
    _1918_t8 = *_1919_y==_1918_t6;
    if (_1918_t8) {
        goto BB2153;
    } else {
        goto BB2156;
    }
BB2153:
    _1918_t7 = 1;
    goto BB2154;
BB2156:
    _1918_t7 = 0;
    goto BB2154;
BB2154:
    _1918_t9 = !_1918_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1918_t5 = _1918_t4(_1918_t9);
    $line_idx--;
    _1918_$retval = _1918_t5;
    return _1918_$retval;
}

int64_t _1920_f(uint8_t _1920_b){
    uint8_t _1920_t0;
    uint8_t _1920_t1;
    int64_t _1920_t2;
    int64_t _1920_$retval;
    _1920_t0 = !_1920_b;
    _1920_b = _1920_t0;
    _1920_t1 = !_1920_t0;
    _1920_b = _1920_t1;
    if (_1920_t0) {
        goto BB2150;
    } else {
        goto BB2146;
    }
BB2150:
    _1920_t2 = 10;
    goto BB2149;
BB2146:
    _1920_t2 = 31;
    goto BB2149;
BB2149:
    _1920_$retval = _1920_t2;
    return _1920_$retval;
}


int main(void) {
  printf("%ld",_1918_main());
  return 0;
}
