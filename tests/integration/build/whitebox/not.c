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
int64_t _1863_main(void);
int64_t _1865_f(uint8_t _1865_b);


/* Function definitions */
int64_t _1863_main(void){
    int64_t _1864_x;
    int64_t* _1864_y;
    function0 _1863_t4;
    int64_t _1863_t6;
    uint8_t _1863_t8;
    uint8_t _1863_t7;
    uint8_t _1863_t9;
    int64_t _1863_t5;
    int64_t _1863_$retval;
    _1864_x = 0;
    _1864_y = &_1864_x;
    _1863_t4 = (function0) _1865_f;
    _1863_t6 = 1;
    _1863_t8 = *_1864_y==_1863_t6;
    if (_1863_t8) {
        goto BB2090;
    } else {
        goto BB2093;
    }
BB2090:
    _1863_t7 = 1;
    goto BB2091;
BB2093:
    _1863_t7 = 0;
    goto BB2091;
BB2091:
    _1863_t9 = !_1863_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1863_t5 = _1863_t4(_1863_t9);
    $line_idx--;
    _1863_$retval = _1863_t5;
    return _1863_$retval;
}

int64_t _1865_f(uint8_t _1865_b){
    uint8_t _1865_t0;
    uint8_t _1865_t1;
    int64_t _1865_t2;
    int64_t _1865_$retval;
    _1865_t0 = !_1865_b;
    _1865_b = _1865_t0;
    _1865_t1 = !_1865_t0;
    _1865_b = _1865_t1;
    if (_1865_t0) {
        goto BB2087;
    } else {
        goto BB2083;
    }
BB2087:
    _1865_t2 = 10;
    goto BB2086;
BB2083:
    _1865_t2 = 31;
    goto BB2086;
BB2086:
    _1865_$retval = _1865_t2;
    return _1865_$retval;
}


int main(void) {
  printf("%ld",_1863_main());
  return 0;
}
