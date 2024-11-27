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
int64_t _1963_main(void);
int64_t _1965_f(uint8_t _1965_b);


/* Function definitions */
int64_t _1963_main(void){
    int64_t _1964_x;
    int64_t* _1964_y;
    function0 _1963_t4;
    int64_t _1963_t6;
    uint8_t _1963_t8;
    uint8_t _1963_t7;
    uint8_t _1963_t9;
    int64_t _1963_t5;
    int64_t _1963_$retval;
    _1964_x = 0;
    _1964_y = &_1964_x;
    _1963_t4 = (function0) _1965_f;
    _1963_t6 = 1;
    _1963_t8 = *_1964_y==_1963_t6;
    if (_1963_t8) {
        goto BB2167;
    } else {
        goto BB2170;
    }
BB2167:
    _1963_t7 = 1;
    goto BB2168;
BB2170:
    _1963_t7 = 0;
    goto BB2168;
BB2168:
    _1963_t9 = !_1963_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1963_t5 = _1963_t4(_1963_t9);
    $line_idx--;
    _1963_$retval = _1963_t5;
    return _1963_$retval;
}

int64_t _1965_f(uint8_t _1965_b){
    uint8_t _1965_t0;
    uint8_t _1965_t1;
    int64_t _1965_t2;
    int64_t _1965_$retval;
    _1965_t0 = !_1965_b;
    _1965_b = _1965_t0;
    _1965_t1 = !_1965_t0;
    _1965_b = _1965_t1;
    if (_1965_t0) {
        goto BB2164;
    } else {
        goto BB2160;
    }
BB2164:
    _1965_t2 = 10;
    goto BB2163;
BB2160:
    _1965_t2 = 31;
    goto BB2163;
BB2163:
    _1965_$retval = _1965_t2;
    return _1965_$retval;
}


int main(void) {
  printf("%ld",_1963_main());
  return 0;
}
