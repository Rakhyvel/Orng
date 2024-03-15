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
int64_t _1818_main(void);
int64_t _1820_f(uint8_t _1820_b);


/* Function definitions */
int64_t _1818_main(void){
    int64_t _1819_x;
    int64_t* _1819_y;
    function0 _1818_t4;
    int64_t _1818_t6;
    uint8_t _1818_t8;
    uint8_t _1818_t7;
    uint8_t _1818_t9;
    int64_t _1818_t5;
    int64_t _1818_$retval;
    _1819_x = 0;
    _1819_y = &_1819_x;
    _1818_t4 = (function0) _1820_f;
    _1818_t6 = 1;
    _1818_t8 = *_1819_y==_1818_t6;
    if (_1818_t8) {
        goto BB2061;
    } else {
        goto BB2064;
    }
BB2061:
    _1818_t7 = 1;
    goto BB2062;
BB2064:
    _1818_t7 = 0;
    goto BB2062;
BB2062:
    _1818_t9 = !_1818_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1818_t5 = _1818_t4(_1818_t9);
    $line_idx--;
    _1818_$retval = _1818_t5;
    return _1818_$retval;
}

int64_t _1820_f(uint8_t _1820_b){
    uint8_t _1820_t0;
    uint8_t _1820_t1;
    int64_t _1820_t2;
    int64_t _1820_$retval;
    _1820_t0 = !_1820_b;
    _1820_b = _1820_t0;
    _1820_t1 = !_1820_t0;
    _1820_b = _1820_t1;
    if (_1820_t0) {
        goto BB2058;
    } else {
        goto BB2054;
    }
BB2058:
    _1820_t2 = 10;
    goto BB2057;
BB2054:
    _1820_t2 = 31;
    goto BB2057;
BB2057:
    _1820_$retval = _1820_t2;
    return _1820_$retval;
}


int main(void) {
  printf("%ld",_1818_main());
  return 0;
}
