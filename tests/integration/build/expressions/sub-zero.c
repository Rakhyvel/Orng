/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward typedefs */

/* Typedefs */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _879_main(void);
uint8_t _884_f(int64_t _884_x);

/* Function definitions */
int64_t _879_main(void){
    function0 _879_t1;
    int64_t _879_t3;
    uint8_t _879_t2;
    int64_t _879_t0;
    int64_t _879_$retval;
    _879_t1 = _884_f;
    _879_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _879_t2 = _879_t1(_879_t3);
    $line_idx--;
    if (_879_t2) {
        goto BB1117;
    } else {
        goto BB1121;
    }
BB1117:
    _879_t0 = 184;
    goto BB1120;
BB1121:
    _879_t0 = 4;
    goto BB1120;
BB1120:
    _879_$retval = _879_t0;
    return _879_$retval;
}

uint8_t _884_f(int64_t _884_x){
    uint8_t _884_$retval;
    uint8_t _884_t0;
    int64_t _884_t6;
    int64_t _884_t7;
    uint8_t _884_t9;
    _884_t6 = $negate_int64_t(_884_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _884_t7 = $negate_int64_t(_884_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _884_t9 = _884_t6==_884_t7;
    if (_884_t9) {
        goto BB1110;
    } else {
        goto BB1113;
    }
BB1110:
    _884_t0 = 1;
    goto BB1112;
BB1113:
    _884_t0 = 0;
    goto BB1112;
BB1112:
    _884_$retval = _884_t0;
    return _884_$retval;
}

int main(void) {
  printf("%ld",_879_main());
  return 0;
}
