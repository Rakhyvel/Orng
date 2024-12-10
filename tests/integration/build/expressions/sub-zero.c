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
int64_t _892_main(void);
uint8_t _897_f(int64_t _897_x);


/* Function definitions */
int64_t _892_main(void){
    function0 _892_t1;
    int64_t _892_t3;
    uint8_t _892_t2;
    int64_t _892_t0;
    int64_t _892_$retval;
    _892_t1 = (function0) _897_f;
    _892_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _892_t2 = _892_t1(_892_t3);
    $line_idx--;
    if (_892_t2) {
        goto BB1088;
    } else {
        goto BB1092;
    }
BB1088:
    _892_t0 = 184;
    goto BB1091;
BB1092:
    _892_t0 = 4;
    goto BB1091;
BB1091:
    _892_$retval = _892_t0;
    return _892_$retval;
}

uint8_t _897_f(int64_t _897_x){
    uint8_t _897_$retval;
    uint8_t _897_t0;
    int64_t _897_t6;
    int64_t _897_t7;
    uint8_t _897_t9;
    goto BB1078;
BB1078:
    _897_t6 = $negate_int64_t(_897_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _897_t7 = $negate_int64_t(_897_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _897_t9 = _897_t6==_897_t7;
    if (_897_t9) {
        goto BB1081;
    } else {
        goto BB1084;
    }
BB1081:
    _897_t0 = 1;
    goto BB1083;
BB1084:
    _897_t0 = 0;
    goto BB1083;
BB1083:
    _897_$retval = _897_t0;
    return _897_$retval;
}


int main(void) {
  printf("%ld",_892_main());
  return 0;
}
