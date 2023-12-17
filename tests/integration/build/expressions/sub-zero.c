/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _984_main(void);
uint8_t _989_f(int64_t _989_x);

/* Function definitions */
int64_t _984_main(void){
    function0 _984_t1;
    int64_t _984_t3;
    uint8_t _984_t2;
    int64_t _984_t0;
    int64_t _984_$retval;
    _984_t1 = _989_f;
    _984_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _984_t2 = _984_t1(_984_t3);
    $line_idx--;
    if (_984_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _984_t0 = 184;
    goto BB4;
BB5:
    _984_t0 = 4;
    goto BB4;
BB4:
    _984_$retval = _984_t0;
    return _984_$retval;
}

uint8_t _989_f(int64_t _989_x){
    uint8_t _989_$retval;
    uint8_t _989_t8;
    int64_t _989_t6;
    int64_t _989_t7;
    uint8_t _989_t9;
    _989_t6 = $negate_int64_t(_989_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _989_t7 = $negate_int64_t(_989_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _989_t9 = _989_t6 == _989_t7;
    if (_989_t9) {
        goto BB4;
    } else {
        goto BB8;
    }
BB4:
    _989_t8 = 1;
    goto BB5;
BB8:
    _989_t8 = 0;
    goto BB5;
BB5:
    _989_$retval = _989_t8;
    return _989_$retval;
}

int main(void) {
  printf("%ld",_984_main());
  return 0;
}
