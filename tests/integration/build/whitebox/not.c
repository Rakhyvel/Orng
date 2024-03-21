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
int64_t _1854_main(void);
int64_t _1856_f(uint8_t _1856_b);


/* Function definitions */
int64_t _1854_main(void){
    int64_t _1855_x;
    int64_t* _1855_y;
    function0 _1854_t4;
    int64_t _1854_t6;
    uint8_t _1854_t8;
    uint8_t _1854_t7;
    uint8_t _1854_t9;
    int64_t _1854_t5;
    int64_t _1854_$retval;
    _1855_x = 0;
    _1855_y = &_1855_x;
    _1854_t4 = (function0) _1856_f;
    _1854_t6 = 1;
    _1854_t8 = *_1855_y==_1854_t6;
    if (_1854_t8) {
        goto BB2084;
    } else {
        goto BB2087;
    }
BB2084:
    _1854_t7 = 1;
    goto BB2085;
BB2087:
    _1854_t7 = 0;
    goto BB2085;
BB2085:
    _1854_t9 = !_1854_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1854_t5 = _1854_t4(_1854_t9);
    $line_idx--;
    _1854_$retval = _1854_t5;
    return _1854_$retval;
}

int64_t _1856_f(uint8_t _1856_b){
    uint8_t _1856_t0;
    uint8_t _1856_t1;
    int64_t _1856_t2;
    int64_t _1856_$retval;
    _1856_t0 = !_1856_b;
    _1856_b = _1856_t0;
    _1856_t1 = !_1856_t0;
    _1856_b = _1856_t1;
    if (_1856_t0) {
        goto BB2081;
    } else {
        goto BB2077;
    }
BB2081:
    _1856_t2 = 10;
    goto BB2080;
BB2077:
    _1856_t2 = 31;
    goto BB2080;
BB2080:
    _1856_$retval = _1856_t2;
    return _1856_$retval;
}


int main(void) {
  printf("%ld",_1854_main());
  return 0;
}
