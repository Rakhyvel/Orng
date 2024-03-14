/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _906_main(void);
uint8_t _911_f(int64_t _911_x);


/* Function definitions */
int64_t _906_main(void){
    function0 _906_t1;
    int64_t _906_t3;
    uint8_t _906_t2;
    int64_t _906_t0;
    int64_t _906_$retval;
    _906_t1 = (function0) _911_f;
    _906_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _906_t2 = _906_t1(_906_t3);
    $line_idx--;
    if (_906_t2) {
        goto BB1122;
    } else {
        goto BB1126;
    }
BB1122:
    _906_t0 = 184;
    goto BB1125;
BB1126:
    _906_t0 = 4;
    goto BB1125;
BB1125:
    _906_$retval = _906_t0;
    return _906_$retval;
}

uint8_t _911_f(int64_t _911_x){
    uint8_t _911_$retval;
    uint8_t _911_t0;
    int64_t _911_t6;
    int64_t _911_t7;
    uint8_t _911_t9;
    _911_t6 = $negate_int64_t(_911_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _911_t7 = $negate_int64_t(_911_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _911_t9 = _911_t6==_911_t7;
    if (_911_t9) {
        goto BB1115;
    } else {
        goto BB1118;
    }
BB1115:
    _911_t0 = 1;
    goto BB1117;
BB1118:
    _911_t0 = 0;
    goto BB1117;
BB1117:
    _911_$retval = _911_t0;
    return _911_$retval;
}


int main(void) {
  printf("%ld",_906_main());
  return 0;
}
