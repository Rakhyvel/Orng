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
int64_t _1852_main(void);
int64_t _1854_f(uint8_t _1854_b);


/* Function definitions */
int64_t _1852_main(void){
    int64_t _1853_x;
    int64_t* _1853_y;
    function0 _1852_t4;
    int64_t _1852_t6;
    uint8_t _1852_t8;
    uint8_t _1852_t7;
    uint8_t _1852_t9;
    int64_t _1852_t5;
    int64_t _1852_$retval;
    _1853_x = 0;
    _1853_y = &_1853_x;
    _1852_t4 = (function0) _1854_f;
    _1852_t6 = 1;
    _1852_t8 = *_1853_y==_1852_t6;
    if (_1852_t8) {
        goto BB2114;
    } else {
        goto BB2117;
    }
BB2114:
    _1852_t7 = 1;
    goto BB2115;
BB2117:
    _1852_t7 = 0;
    goto BB2115;
BB2115:
    _1852_t9 = !_1852_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1852_t5 = _1852_t4(_1852_t9);
    $line_idx--;
    _1852_$retval = _1852_t5;
    return _1852_$retval;
}

int64_t _1854_f(uint8_t _1854_b){
    uint8_t _1854_t0;
    uint8_t _1854_t1;
    int64_t _1854_t2;
    int64_t _1854_$retval;
    _1854_t0 = !_1854_b;
    _1854_b = _1854_t0;
    _1854_t1 = !_1854_t0;
    _1854_b = _1854_t1;
    if (_1854_t0) {
        goto BB2111;
    } else {
        goto BB2107;
    }
BB2111:
    _1854_t2 = 10;
    goto BB2110;
BB2107:
    _1854_t2 = 31;
    goto BB2110;
BB2110:
    _1854_$retval = _1854_t2;
    return _1854_$retval;
}


int main(void) {
  printf("%ld",_1852_main());
  return 0;
}
