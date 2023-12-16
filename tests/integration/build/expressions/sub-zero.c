/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _820_main(void);
uint8_t _825_f(int64_t _825_x);

/* Function definitions */
int64_t _820_main(void) {
    function0 _820_t1;
    int64_t _820_t3;
    uint8_t _820_t2;
    int64_t _820_t0;
    int64_t _820_$retval;
    _820_t1 = _825_f;
    _820_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _820_t2 = _820_t1(_820_t3);
    $line_idx--;
    if (_820_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _820_t0 = 184;
    goto BB4;
BB5:
    _820_t0 = 4;
    goto BB4;
BB4:
    _820_$retval = _820_t0;
    return _820_$retval;
}

uint8_t _825_f(int64_t _825_x) {
    uint8_t _825_$retval;
    uint8_t _825_t8;
    int64_t _825_t6;
    int64_t _825_t7;
    uint8_t _825_t9;
    _825_t6 = $negate_int64_t(_825_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _825_t7 = $negate_int64_t(_825_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _825_t9 = _825_t6 == _825_t7;
    if (_825_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _825_t8 = 1;
    goto BB5;
BB8:
    _825_t8 = 0;
    goto BB5;
BB5:
    _825_$retval = _825_t8;
    return _825_$retval;
}

int main(void) {
  printf("%ld",_820_main());
  return 0;
}
