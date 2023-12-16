/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _899_main(void);
uint8_t _904_f(int64_t _904_x);

/* Function definitions */
int64_t _899_main(void){
    function0 _899_t1;
    int64_t _899_t3;
    uint8_t _899_t2;
    int64_t _899_t0;
    int64_t _899_$retval;
    _899_t1 = _904_f;
    _899_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _899_t2 = _899_t1(_899_t3);
    $line_idx--;
    if (_899_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _899_t0 = 184;
    goto BB4;
BB5:
    _899_t0 = 4;
    goto BB4;
BB4:
    _899_$retval = _899_t0;
    return _899_$retval;
}

uint8_t _904_f(int64_t _904_x){
    uint8_t _904_$retval;
    uint8_t _904_t8;
    int64_t _904_t6;
    int64_t _904_t7;
    uint8_t _904_t9;
    _904_t6 = $negate_int64_t(_904_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _904_t7 = $negate_int64_t(_904_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _904_t9 = _904_t6 == _904_t7;
    if (_904_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _904_t8 = 1;
    goto BB5;
BB8:
    _904_t8 = 0;
    goto BB5;
BB5:
    _904_$retval = _904_t8;
    return _904_$retval;
}

int main(void) {
  printf("%ld",_899_main());
  return 0;
}
