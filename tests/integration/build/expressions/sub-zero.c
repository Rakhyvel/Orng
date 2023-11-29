/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _812_main(void);
uint8_t _817_f(int64_t _817_x);

/* Function definitions */
int64_t _812_main(void) {
    function0 _812_t1;
    int64_t _812_t3;
    uint8_t _812_t2;
    int64_t _812_t0;
    int64_t _812_$retval;
    _812_t1 = _817_f;
    _812_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _812_t2 = _812_t1(_812_t3);
    $line_idx--;
    if (_812_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _812_t0 = 184;
    goto BB4;
BB5:
    _812_t0 = 4;
    goto BB4;
BB4:
    _812_$retval = _812_t0;
    return _812_$retval;
}

uint8_t _817_f(int64_t _817_x) {
    uint8_t _817_$retval;
    uint8_t _817_t8;
    int64_t _817_t6;
    int64_t _817_t7;
    uint8_t _817_t9;
    _817_t6 = $negate_int64_t(_817_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _817_t7 = $negate_int64_t(_817_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _817_t9 = _817_t6 == _817_t7;
    if (_817_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _817_t8 = 1;
    goto BB5;
BB8:
    _817_t8 = 0;
    goto BB5;
BB5:
    _817_$retval = _817_t8;
    return _817_$retval;
}

int main(void) {
  printf("%ld",_812_main());
  return 0;
}
