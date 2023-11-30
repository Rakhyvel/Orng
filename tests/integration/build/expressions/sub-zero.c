/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _791_main(void);
uint8_t _796_f(int64_t _796_x);

/* Function definitions */
int64_t _791_main(void) {
    function0 _791_t1;
    int64_t _791_t3;
    uint8_t _791_t2;
    int64_t _791_t0;
    int64_t _791_$retval;
    _791_t1 = _796_f;
    _791_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _791_t2 = _791_t1(_791_t3);
    $line_idx--;
    if (_791_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _791_t0 = 184;
    goto BB4;
BB5:
    _791_t0 = 4;
    goto BB4;
BB4:
    _791_$retval = _791_t0;
    return _791_$retval;
}

uint8_t _796_f(int64_t _796_x) {
    uint8_t _796_$retval;
    uint8_t _796_t8;
    int64_t _796_t6;
    int64_t _796_t7;
    uint8_t _796_t9;
    _796_t6 = $negate_int64_t(_796_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _796_t7 = $negate_int64_t(_796_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _796_t9 = _796_t6 == _796_t7;
    if (_796_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _796_t8 = 1;
    goto BB5;
BB8:
    _796_t8 = 0;
    goto BB5;
BB5:
    _796_$retval = _796_t8;
    return _796_$retval;
}

int main(void) {
  printf("%ld",_791_main());
  return 0;
}
