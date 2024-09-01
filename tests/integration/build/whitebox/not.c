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
int64_t _1907_main(void);
int64_t _1909_f(uint8_t _1909_b);


/* Function definitions */
int64_t _1907_main(void){
    int64_t _1908_x;
    int64_t* _1908_y;
    function0 _1907_t4;
    int64_t _1907_t6;
    uint8_t _1907_t8;
    uint8_t _1907_t7;
    uint8_t _1907_t9;
    int64_t _1907_t5;
    int64_t _1907_$retval;
    _1908_x = 0;
    _1908_y = &_1908_x;
    _1907_t4 = (function0) _1909_f;
    _1907_t6 = 1;
    _1907_t8 = *_1908_y==_1907_t6;
    if (_1907_t8) {
        goto BB2142;
    } else {
        goto BB2145;
    }
BB2142:
    _1907_t7 = 1;
    goto BB2143;
BB2145:
    _1907_t7 = 0;
    goto BB2143;
BB2143:
    _1907_t9 = !_1907_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1907_t5 = _1907_t4(_1907_t9);
    $line_idx--;
    _1907_$retval = _1907_t5;
    return _1907_$retval;
}

int64_t _1909_f(uint8_t _1909_b){
    uint8_t _1909_t0;
    uint8_t _1909_t1;
    int64_t _1909_t2;
    int64_t _1909_$retval;
    _1909_t0 = !_1909_b;
    _1909_b = _1909_t0;
    _1909_t1 = !_1909_t0;
    _1909_b = _1909_t1;
    if (_1909_t0) {
        goto BB2139;
    } else {
        goto BB2135;
    }
BB2139:
    _1909_t2 = 10;
    goto BB2138;
BB2135:
    _1909_t2 = 31;
    goto BB2138;
BB2138:
    _1909_$retval = _1909_t2;
    return _1909_$retval;
}


int main(void) {
  printf("%ld",_1907_main());
  return 0;
}
