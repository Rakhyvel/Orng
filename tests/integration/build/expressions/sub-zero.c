/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _991_main(void);
uint8_t _996_f(int64_t _996_x);

/* Function definitions */
int64_t _991_main(void){
    function0 _991_t1;
    int64_t _991_t3;
    uint8_t _991_t2;
    int64_t _991_t0;
    int64_t _991_$retval;
    _991_t1 = _996_f;
    _991_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _991_t2 = _991_t1(_991_t3);
    $line_idx--;
    if (_991_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _991_t0 = 184;
    goto BB4;
BB5:
    _991_t0 = 4;
    goto BB4;
BB4:
    _991_$retval = _991_t0;
    return _991_$retval;
}

uint8_t _996_f(int64_t _996_x){
    uint8_t _996_$retval;
    uint8_t _996_t8;
    int64_t _996_t6;
    int64_t _996_t7;
    uint8_t _996_t9;
    _996_t6 = $negate_int64_t(_996_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _996_t7 = $negate_int64_t(_996_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _996_t9 = _996_t6 == _996_t7;
    if (_996_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _996_t8 = 1;
    goto BB5;
BB8:
    _996_t8 = 0;
    goto BB5;
BB5:
    _996_$retval = _996_t8;
    return _996_$retval;
}

int main(void) {
  printf("%ld",_991_main());
  return 0;
}
