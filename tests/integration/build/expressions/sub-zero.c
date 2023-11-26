/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _256_main(void);
uint8_t _261_f(int64_t _261_x);

/* Function definitions */
int64_t _256_main(void) {
    function0 _256_t1;
    int64_t _256_t3;
    uint8_t _256_t2;
    int64_t _256_t0;
    int64_t _256_$retval;
    _256_t1 = _261_f;
    _256_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _256_t2 = _256_t1(_256_t3);
    $line_idx--;
    if (_256_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _256_t0 = 184;
    goto BB4;
BB5:
    _256_t0 = 4;
    goto BB4;
BB4:
    _256_$retval = _256_t0;
    return _256_$retval;
}

uint8_t _261_f(int64_t _261_x) {
    uint8_t _261_t4;
    uint8_t _261_t3;
    int64_t _261_t6;
    int64_t _261_t7;
    uint8_t _261_t9;
    uint8_t _261_t8;
    uint8_t _261_t0;
    uint8_t _261_$retval;
    _261_t4 = 1;
    if (_261_t4) {
        goto BB1;
    } else {
        goto BB10;
    }
BB1:
    _261_t3 = 1;
    goto BB2;
BB10:
    _261_t3 = 0;
    goto BB2;
BB2:
    if (_261_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _261_t6 = $negate_int64_t(_261_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _261_t7 = $negate_int64_t(_261_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _261_t9 = _261_t6 == _261_t7;
    if (_261_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB9:
    _261_t0 = 0;
    goto BB7;
BB4:
    _261_t8 = 1;
    goto BB5;
BB8:
    _261_t8 = 0;
    goto BB5;
BB7:
    _261_$retval = _261_t0;
    return _261_$retval;
BB5:
    _261_t0 = _261_t8;
    goto BB7;
}

int main(void) {
  printf("%ld",_256_main());
  return 0;
}
