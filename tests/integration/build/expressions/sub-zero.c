/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _839_main(void);
uint8_t _844_f(int64_t _844_x);

/* Function definitions */
int64_t _839_main(void){
    function0 _839_t1;
    int64_t _839_t3;
    uint8_t _839_t2;
    int64_t _839_t0;
    int64_t _839_$retval;
    _839_t1 = _844_f;
    _839_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _839_t2 = _839_t1(_839_t3);
    $line_idx--;
    if (_839_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _839_t0 = 184;
    goto BB4;
BB5:
    _839_t0 = 4;
    goto BB4;
BB4:
    _839_$retval = _839_t0;
    return _839_$retval;
}

uint8_t _844_f(int64_t _844_x){
    uint8_t _844_$retval;
    uint8_t _844_t8;
    int64_t _844_t6;
    int64_t _844_t7;
    uint8_t _844_t9;
    _844_t6 = $negate_int64_t(_844_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _844_t7 = $negate_int64_t(_844_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _844_t9 = _844_t6 == _844_t7;
    if (_844_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _844_t8 = 1;
    goto BB5;
BB8:
    _844_t8 = 0;
    goto BB5;
BB5:
    _844_$retval = _844_t8;
    return _844_$retval;
}

int main(void) {
  printf("%ld",_839_main());
  return 0;
}
