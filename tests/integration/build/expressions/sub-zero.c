/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _828_main(void);
uint8_t _833_f(int64_t _833_x);

/* Function definitions */
int64_t _828_main(void){
    function0 _828_t1;
    int64_t _828_t3;
    uint8_t _828_t2;
    int64_t _828_t0;
    int64_t _828_$retval;
    _828_t1 = _833_f;
    _828_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _828_t2 = _828_t1(_828_t3);
    $line_idx--;
    if (_828_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _828_t0 = 184;
    goto BB4;
BB5:
    _828_t0 = 4;
    goto BB4;
BB4:
    _828_$retval = _828_t0;
    return _828_$retval;
}

uint8_t _833_f(int64_t _833_x){
    uint8_t _833_$retval;
    uint8_t _833_t8;
    int64_t _833_t6;
    int64_t _833_t7;
    uint8_t _833_t9;
    _833_t6 = $negate_int64_t(_833_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _833_t7 = $negate_int64_t(_833_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _833_t9 = _833_t6 == _833_t7;
    if (_833_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _833_t8 = 1;
    goto BB5;
BB8:
    _833_t8 = 0;
    goto BB5;
BB5:
    _833_$retval = _833_t8;
    return _833_$retval;
}

int main(void) {
  printf("%ld",_828_main());
  return 0;
}
