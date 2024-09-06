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
int64_t _872_main(void);
uint8_t _877_f(int64_t _877_x);


/* Function definitions */
int64_t _872_main(void){
    function0 _872_t1;
    int64_t _872_t3;
    uint8_t _872_t2;
    int64_t _872_t0;
    int64_t _872_$retval;
    _872_t1 = (function0) _877_f;
    _872_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _872_t2 = _872_t1(_872_t3);
    $line_idx--;
    if (_872_t2) {
        goto BB1069;
    } else {
        goto BB1073;
    }
BB1069:
    _872_t0 = 184;
    goto BB1072;
BB1073:
    _872_t0 = 4;
    goto BB1072;
BB1072:
    _872_$retval = _872_t0;
    return _872_$retval;
}

uint8_t _877_f(int64_t _877_x){
    uint8_t _877_$retval;
    uint8_t _877_t0;
    int64_t _877_t6;
    int64_t _877_t7;
    uint8_t _877_t9;
    goto BB1059;
BB1059:
    _877_t6 = $negate_int64_t(_877_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _877_t7 = $negate_int64_t(_877_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _877_t9 = _877_t6==_877_t7;
    if (_877_t9) {
        goto BB1062;
    } else {
        goto BB1065;
    }
BB1062:
    _877_t0 = 1;
    goto BB1064;
BB1065:
    _877_t0 = 0;
    goto BB1064;
BB1064:
    _877_$retval = _877_t0;
    return _877_$retval;
}


int main(void) {
  printf("%ld",_872_main());
  return 0;
}
