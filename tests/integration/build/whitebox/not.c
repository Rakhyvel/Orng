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
int64_t _1933_main(void);
int64_t _1935_f(uint8_t _1935_b);


/* Function definitions */
int64_t _1933_main(void){
    int64_t _1934_x;
    int64_t* _1934_y;
    function0 _1933_t4;
    int64_t _1933_t6;
    uint8_t _1933_t8;
    uint8_t _1933_t7;
    uint8_t _1933_t9;
    int64_t _1933_t5;
    int64_t _1933_$retval;
    _1934_x = 0;
    _1934_y = &_1934_x;
    _1933_t4 = (function0) _1935_f;
    _1933_t6 = 1;
    _1933_t8 = *_1934_y==_1933_t6;
    if (_1933_t8) {
        goto BB2167;
    } else {
        goto BB2170;
    }
BB2167:
    _1933_t7 = 1;
    goto BB2168;
BB2170:
    _1933_t7 = 0;
    goto BB2168;
BB2168:
    _1933_t9 = !_1933_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1933_t5 = _1933_t4(_1933_t9);
    $line_idx--;
    _1933_$retval = _1933_t5;
    return _1933_$retval;
}

int64_t _1935_f(uint8_t _1935_b){
    uint8_t _1935_t0;
    uint8_t _1935_t1;
    int64_t _1935_t2;
    int64_t _1935_$retval;
    _1935_t0 = !_1935_b;
    _1935_b = _1935_t0;
    _1935_t1 = !_1935_t0;
    _1935_b = _1935_t1;
    if (_1935_t0) {
        goto BB2164;
    } else {
        goto BB2160;
    }
BB2164:
    _1935_t2 = 10;
    goto BB2163;
BB2160:
    _1935_t2 = 31;
    goto BB2163;
BB2163:
    _1935_$retval = _1935_t2;
    return _1935_$retval;
}


int main(void) {
  printf("%ld",_1933_main());
  return 0;
}
