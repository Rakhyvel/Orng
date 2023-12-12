/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _652_main(void);
uint8_t _657_f(int64_t _657_x);

/* Function definitions */
int64_t _652_main(void) {
    function0 _652_t1;
    int64_t _652_t3;
    uint8_t _652_t2;
    int64_t _652_t0;
    int64_t _652_$retval;
    _652_t1 = _657_f;
    _652_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _652_t2 = _652_t1(_652_t3);
    $line_idx--;
    if (_652_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _652_t0 = 184;
    goto BB4;
BB5:
    _652_t0 = 4;
    goto BB4;
BB4:
    _652_$retval = _652_t0;
    return _652_$retval;
}

uint8_t _657_f(int64_t _657_x) {
    uint8_t _657_$retval;
    uint8_t _657_t8;
    int64_t _657_t6;
    int64_t _657_t7;
    uint8_t _657_t9;
    _657_t6 = $negate_int64_t(_657_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _657_t7 = $negate_int64_t(_657_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _657_t9 = _657_t6 == _657_t7;
    if (_657_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _657_t8 = 1;
    goto BB5;
BB8:
    _657_t8 = 0;
    goto BB5;
BB5:
    _657_$retval = _657_t8;
    return _657_$retval;
}

int main(void) {
  printf("%ld",_652_main());
  return 0;
}
