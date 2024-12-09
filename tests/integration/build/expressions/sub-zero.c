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
int64_t _877_main(void);
uint8_t _882_f(int64_t _882_x);


/* Function definitions */
int64_t _877_main(void){
    function0 _877_t1;
    int64_t _877_t3;
    uint8_t _877_t2;
    int64_t _877_t0;
    int64_t _877_$retval;
    _877_t1 = (function0) _882_f;
    _877_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _877_t2 = _877_t1(_877_t3);
    $line_idx--;
    if (_877_t2) {
        goto BB1072;
    } else {
        goto BB1076;
    }
BB1072:
    _877_t0 = 184;
    goto BB1075;
BB1076:
    _877_t0 = 4;
    goto BB1075;
BB1075:
    _877_$retval = _877_t0;
    return _877_$retval;
}

uint8_t _882_f(int64_t _882_x){
    uint8_t _882_$retval;
    uint8_t _882_t0;
    int64_t _882_t6;
    int64_t _882_t7;
    uint8_t _882_t9;
    goto BB1062;
BB1062:
    _882_t6 = $negate_int64_t(_882_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _882_t7 = $negate_int64_t(_882_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _882_t9 = _882_t6==_882_t7;
    if (_882_t9) {
        goto BB1065;
    } else {
        goto BB1068;
    }
BB1065:
    _882_t0 = 1;
    goto BB1067;
BB1068:
    _882_t0 = 0;
    goto BB1067;
BB1067:
    _882_$retval = _882_t0;
    return _882_$retval;
}


int main(void) {
  printf("%ld",_877_main());
  return 0;
}
