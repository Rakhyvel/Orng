/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _561_main(void);
uint8_t _566_f(int64_t _566_x);

/* Function definitions */
int64_t _561_main(void) {
    function0 _561_t1;
    int64_t _561_t3;
    uint8_t _561_t2;
    int64_t _561_t0;
    int64_t _561_$retval;
    _561_t1 = _566_f;
    _561_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _561_t2 = _561_t1(_561_t3);
    $line_idx--;
    if (_561_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _561_t0 = 184;
    goto BB4;
BB5:
    _561_t0 = 4;
    goto BB4;
BB4:
    _561_$retval = _561_t0;
    return _561_$retval;
}

uint8_t _566_f(int64_t _566_x) {
    uint8_t _566_t4;
    uint8_t _566_t3;
    int64_t _566_t6;
    int64_t _566_t7;
    uint8_t _566_t9;
    uint8_t _566_t8;
    uint8_t _566_t0;
    uint8_t _566_$retval;
    _566_t4 = 1;
    if (_566_t4) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _566_t3 = 1;
    goto BB2;
BB10:
    _566_t3 = 0;
    goto BB2;
BB2:
    if (_566_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _566_t6 = $negate_int64_t(_566_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _566_t7 = $negate_int64_t(_566_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _566_t9 = _566_t6 == _566_t7;
    if (_566_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _566_t0 = 0;
    goto BB7;
BB4:
    _566_t8 = 1;
    goto BB5;
BB8:
    _566_t8 = 0;
    goto BB5;
BB7:
    _566_$retval = _566_t0;
    return _566_$retval;
BB5:
    _566_t0 = _566_t8;
    goto BB7;
}

int main(void) {
  printf("%ld",_561_main());
  return 0;
}
