/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _592_main(void);
uint8_t _597_f(int64_t _597_x);

/* Function definitions */
int64_t _592_main(void) {
    function0 _592_t1;
    int64_t _592_t3;
    uint8_t _592_t2;
    int64_t _592_t0;
    int64_t _592_$retval;
    _592_t1 = _597_f;
    _592_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _592_t2 = _592_t1(_592_t3);
    $line_idx--;
    if (_592_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _592_t0 = 184;
    goto BB4;
BB5:
    _592_t0 = 4;
    goto BB4;
BB4:
    _592_$retval = _592_t0;
    return _592_$retval;
}

uint8_t _597_f(int64_t _597_x) {
    uint8_t _597_$retval;
    uint8_t _597_t8;
    int64_t _597_t6;
    int64_t _597_t7;
    uint8_t _597_t9;
    _597_t6 = $negate_int64_t(_597_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _597_t7 = $negate_int64_t(_597_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _597_t9 = _597_t6 == _597_t7;
    if (_597_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _597_t8 = 1;
    goto BB5;
BB8:
    _597_t8 = 0;
    goto BB5;
BB5:
    _597_$retval = _597_t8;
    return _597_$retval;
}

int main(void) {
  printf("%ld",_592_main());
  return 0;
}
