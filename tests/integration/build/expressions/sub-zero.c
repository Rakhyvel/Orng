/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _625_main(void);
uint8_t _630_f(int64_t _630_x);

/* Function definitions */
int64_t _625_main(void) {
    function0 _625_t1;
    int64_t _625_t3;
    uint8_t _625_t2;
    int64_t _625_t0;
    int64_t _625_$retval;
    _625_t1 = _630_f;
    _625_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _625_t2 = _625_t1(_625_t3);
    $line_idx--;
    if (_625_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _625_t0 = 184;
    goto BB4;
BB5:
    _625_t0 = 4;
    goto BB4;
BB4:
    _625_$retval = _625_t0;
    return _625_$retval;
}

uint8_t _630_f(int64_t _630_x) {
    uint8_t _630_$retval;
    uint8_t _630_t8;
    int64_t _630_t6;
    int64_t _630_t7;
    uint8_t _630_t9;
    _630_t6 = $negate_int64_t(_630_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _630_t7 = $negate_int64_t(_630_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _630_t9 = _630_t6 == _630_t7;
    if (_630_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _630_t8 = 1;
    goto BB5;
BB8:
    _630_t8 = 0;
    goto BB5;
BB5:
    _630_$retval = _630_t8;
    return _630_$retval;
}

int main(void) {
  printf("%ld",_625_main());
  return 0;
}
