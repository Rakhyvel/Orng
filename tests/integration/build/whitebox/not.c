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
int64_t _1985_main(void);
int64_t _1987_f(uint8_t _1987_b);


/* Function definitions */
int64_t _1985_main(void){
    int64_t _1986_x;
    int64_t* _1986_y;
    function0 _1985_t4;
    int64_t _1985_t6;
    uint8_t _1985_t8;
    uint8_t _1985_t7;
    uint8_t _1985_t9;
    int64_t _1985_t5;
    int64_t _1985_$retval;
    _1986_x = 0;
    _1986_y = &_1986_x;
    _1985_t4 = (function0) _1987_f;
    _1985_t6 = 1;
    _1985_t8 = *_1986_y==_1985_t6;
    if (_1985_t8) {
        goto BB2187;
    } else {
        goto BB2190;
    }
BB2187:
    _1985_t7 = 1;
    goto BB2188;
BB2190:
    _1985_t7 = 0;
    goto BB2188;
BB2188:
    _1985_t9 = !_1985_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1985_t5 = _1985_t4(_1985_t9);
    $line_idx--;
    _1985_$retval = _1985_t5;
    return _1985_$retval;
}

int64_t _1987_f(uint8_t _1987_b){
    uint8_t _1987_t0;
    uint8_t _1987_t1;
    int64_t _1987_t2;
    int64_t _1987_$retval;
    _1987_t0 = !_1987_b;
    _1987_b = _1987_t0;
    _1987_t1 = !_1987_t0;
    _1987_b = _1987_t1;
    if (_1987_t0) {
        goto BB2184;
    } else {
        goto BB2180;
    }
BB2184:
    _1987_t2 = 10;
    goto BB2183;
BB2180:
    _1987_t2 = 31;
    goto BB2183;
BB2183:
    _1987_$retval = _1987_t2;
    return _1987_$retval;
}


int main(void) {
  printf("%ld",_1985_main());
  return 0;
}
