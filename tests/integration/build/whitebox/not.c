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
int64_t _1830_main(void);
int64_t _1832_f(uint8_t _1832_b);


/* Function definitions */
int64_t _1830_main(void){
    int64_t _1831_x;
    int64_t* _1831_y;
    function0 _1830_t4;
    int64_t _1830_t6;
    uint8_t _1830_t8;
    uint8_t _1830_t7;
    uint8_t _1830_t9;
    int64_t _1830_t5;
    int64_t _1830_$retval;
    _1831_x = 0;
    _1831_y = &_1831_x;
    _1830_t4 = (function0) _1832_f;
    _1830_t6 = 1;
    _1830_t8 = *_1831_y==_1830_t6;
    if (_1830_t8) {
        goto BB2067;
    } else {
        goto BB2070;
    }
BB2067:
    _1830_t7 = 1;
    goto BB2068;
BB2070:
    _1830_t7 = 0;
    goto BB2068;
BB2068:
    _1830_t9 = !_1830_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1830_t5 = _1830_t4(_1830_t9);
    $line_idx--;
    _1830_$retval = _1830_t5;
    return _1830_$retval;
}

int64_t _1832_f(uint8_t _1832_b){
    uint8_t _1832_t0;
    uint8_t _1832_t1;
    int64_t _1832_t2;
    int64_t _1832_$retval;
    _1832_t0 = !_1832_b;
    _1832_b = _1832_t0;
    _1832_t1 = !_1832_t0;
    _1832_b = _1832_t1;
    if (_1832_t0) {
        goto BB2064;
    } else {
        goto BB2060;
    }
BB2064:
    _1832_t2 = 10;
    goto BB2063;
BB2060:
    _1832_t2 = 31;
    goto BB2063;
BB2063:
    _1832_$retval = _1832_t2;
    return _1832_$retval;
}


int main(void) {
  printf("%ld",_1830_main());
  return 0;
}
