/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _633_main(void);
uint8_t _638_f(int64_t _638_x);

/* Function definitions */
int64_t _633_main(void) {
    function0 _633_t1;
    int64_t _633_t3;
    uint8_t _633_t2;
    int64_t _633_t0;
    int64_t _633_$retval;
    _633_t1 = _638_f;
    _633_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _633_t2 = _633_t1(_633_t3);
    $line_idx--;
    if (_633_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _633_t0 = 184;
    goto BB4;
BB5:
    _633_t0 = 4;
    goto BB4;
BB4:
    _633_$retval = _633_t0;
    return _633_$retval;
}

uint8_t _638_f(int64_t _638_x) {
    uint8_t _638_$retval;
    uint8_t _638_t8;
    int64_t _638_t6;
    int64_t _638_t7;
    uint8_t _638_t9;
    _638_t6 = $negate_int64_t(_638_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _638_t7 = $negate_int64_t(_638_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _638_t9 = _638_t6 == _638_t7;
    if (_638_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _638_t8 = 1;
    goto BB5;
BB8:
    _638_t8 = 0;
    goto BB5;
BB5:
    _638_$retval = _638_t8;
    return _638_$retval;
}

int main(void) {
  printf("%ld",_633_main());
  return 0;
}
