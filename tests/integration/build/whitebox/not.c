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
int64_t _1926_main(void);
int64_t _1928_f(uint8_t _1928_b);


/* Function definitions */
int64_t _1926_main(void){
    int64_t _1927_x;
    int64_t* _1927_y;
    function0 _1926_t4;
    int64_t _1926_t6;
    uint8_t _1926_t8;
    uint8_t _1926_t7;
    uint8_t _1926_t9;
    int64_t _1926_t5;
    int64_t _1926_$retval;
    _1927_x = 0;
    _1927_y = &_1927_x;
    _1926_t4 = (function0) _1928_f;
    _1926_t6 = 1;
    _1926_t8 = *_1927_y==_1926_t6;
    if (_1926_t8) {
        goto BB2159;
    } else {
        goto BB2162;
    }
BB2159:
    _1926_t7 = 1;
    goto BB2160;
BB2162:
    _1926_t7 = 0;
    goto BB2160;
BB2160:
    _1926_t9 = !_1926_t7;
    $lines[$line_idx++] = "tests/integration/whitebox/not.orng:5:7:\n    f(not (y^ == 1))\n     ^";
    _1926_t5 = _1926_t4(_1926_t9);
    $line_idx--;
    _1926_$retval = _1926_t5;
    return _1926_$retval;
}

int64_t _1928_f(uint8_t _1928_b){
    uint8_t _1928_t0;
    uint8_t _1928_t1;
    int64_t _1928_t2;
    int64_t _1928_$retval;
    _1928_t0 = !_1928_b;
    _1928_b = _1928_t0;
    _1928_t1 = !_1928_t0;
    _1928_b = _1928_t1;
    if (_1928_t0) {
        goto BB2156;
    } else {
        goto BB2152;
    }
BB2156:
    _1928_t2 = 10;
    goto BB2155;
BB2152:
    _1928_t2 = 31;
    goto BB2155;
BB2155:
    _1928_$retval = _1928_t2;
    return _1928_$retval;
}


int main(void) {
  printf("%ld",_1926_main());
  return 0;
}
