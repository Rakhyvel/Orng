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
int64_t _1796_main(void);
int64_t _1798_f(uint8_t _1798_b);


/* Function definitions */
int64_t _1796_main(void){
    int64_t _1797_x;
    int64_t* _1797_y;
    function0 _1796_t2;
    int64_t _1796_t4;
    uint8_t _1796_t6;
    uint8_t _1796_t5;
    uint8_t _1796_t7;
    int64_t _1796_t3;
    int64_t _1796_$retval;
    _1797_x = 0;
    _1797_y = &_1797_x;
    _1796_t2 = (function0) _1798_f;
    _1796_t4 = 1;
    _1796_t6 = *_1797_y==_1796_t4;
    if (_1796_t6) {
        goto BB2062;
    } else {
        goto BB2065;
    }
BB2062:
    _1796_t5 = 1;
    goto BB2063;
BB2065:
    _1796_t5 = 0;
    goto BB2063;
BB2063:
    _1796_t7 = !_1796_t5;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1796_t3 = _1796_t2(_1796_t7);
    $line_idx--;
    _1796_$retval = _1796_t3;
    return _1796_$retval;
}

int64_t _1798_f(uint8_t _1798_b){
    uint8_t _1798_t0;
    uint8_t _1798_t1;
    int64_t _1798_t2;
    int64_t _1798_$retval;
    _1798_t0 = !_1798_b;
    _1798_b = _1798_t0;
    _1798_t1 = !_1798_t0;
    _1798_b = _1798_t1;
    if (_1798_t0) {
        goto BB2059;
    } else {
        goto BB2055;
    }
BB2059:
    _1798_t2 = 10;
    goto BB2058;
BB2055:
    _1798_t2 = 31;
    goto BB2058;
BB2058:
    _1798_$retval = _1798_t2;
    return _1798_$retval;
}


int main(void) {
  printf("%ld",_1796_main());
  return 0;
}
