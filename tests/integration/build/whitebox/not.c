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
int64_t _1958_main(void);
int64_t _1960_f(uint8_t _1960_b);


/* Function definitions */
int64_t _1958_main(void){
    int64_t _1959_x;
    int64_t* _1959_y;
    function0 _1958_t4;
    int64_t _1958_t6;
    uint8_t _1958_t8;
    uint8_t _1958_t7;
    uint8_t _1958_t9;
    int64_t _1958_t5;
    int64_t _1958_$retval;
    _1959_x = 0;
    _1959_y = &_1959_x;
    _1958_t4 = (function0) _1960_f;
    _1958_t6 = 1;
    _1958_t8 = *_1959_y==_1958_t6;
    if (_1958_t8) {
        goto BB2167;
    } else {
        goto BB2170;
    }
BB2167:
    _1958_t7 = 1;
    goto BB2168;
BB2170:
    _1958_t7 = 0;
    goto BB2168;
BB2168:
    _1958_t9 = !_1958_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1958_t5 = _1958_t4(_1958_t9);
    $line_idx--;
    _1958_$retval = _1958_t5;
    return _1958_$retval;
}

int64_t _1960_f(uint8_t _1960_b){
    uint8_t _1960_t0;
    uint8_t _1960_t1;
    int64_t _1960_t2;
    int64_t _1960_$retval;
    _1960_t0 = !_1960_b;
    _1960_b = _1960_t0;
    _1960_t1 = !_1960_t0;
    _1960_b = _1960_t1;
    if (_1960_t0) {
        goto BB2164;
    } else {
        goto BB2160;
    }
BB2164:
    _1960_t2 = 10;
    goto BB2163;
BB2160:
    _1960_t2 = 31;
    goto BB2163;
BB2163:
    _1960_$retval = _1960_t2;
    return _1960_$retval;
}


int main(void) {
  printf("%ld",_1958_main());
  return 0;
}
