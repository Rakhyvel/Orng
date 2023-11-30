/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _814_main(void);
uint8_t _819_f(int64_t _819_x);

/* Function definitions */
int64_t _814_main(void) {
    function0 _814_t1;
    int64_t _814_t3;
    uint8_t _814_t2;
    int64_t _814_t0;
    int64_t _814_$retval;
    _814_t1 = _819_f;
    _814_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _814_t2 = _814_t1(_814_t3);
    $line_idx--;
    if (_814_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _814_t0 = 184;
    goto BB4;
BB5:
    _814_t0 = 4;
    goto BB4;
BB4:
    _814_$retval = _814_t0;
    return _814_$retval;
}

uint8_t _819_f(int64_t _819_x) {
    uint8_t _819_$retval;
    uint8_t _819_t8;
    int64_t _819_t6;
    int64_t _819_t7;
    uint8_t _819_t9;
    _819_t6 = $negate_int64_t(_819_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _819_t7 = $negate_int64_t(_819_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _819_t9 = _819_t6 == _819_t7;
    if (_819_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _819_t8 = 1;
    goto BB5;
BB8:
    _819_t8 = 0;
    goto BB5;
BB5:
    _819_$retval = _819_t8;
    return _819_$retval;
}

int main(void) {
  printf("%ld",_814_main());
  return 0;
}
