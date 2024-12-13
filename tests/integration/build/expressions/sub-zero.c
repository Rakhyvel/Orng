/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef uint8_t(*function0)(int64_t);

/* Function forward definitions */
int64_t _894_main(void);
uint8_t _899_f(int64_t _899_x);


/* Function definitions */
int64_t _894_main(void){
    function0 _894_t1;
    int64_t _894_t3;
    uint8_t _894_t2;
    int64_t _894_t0;
    int64_t _894_$retval;
    _894_t1 = (function0) _899_f;
    _894_t3 = 4;
    $lines[$line_idx++] = "tests/integration/expressions/sub-zero.orng:3:10:\n    if f(4) {\n        ^";
    _894_t2 = _894_t1(_894_t3);
    $line_idx--;
    if (_894_t2) {
        goto BB1090;
    } else {
        goto BB1094;
    }
BB1090:
    _894_t0 = 184;
    goto BB1093;
BB1094:
    _894_t0 = 4;
    goto BB1093;
BB1093:
    _894_$retval = _894_t0;
    return _894_$retval;
}

uint8_t _899_f(int64_t _899_x){
    uint8_t _899_$retval;
    uint8_t _899_t0;
    int64_t _899_t6;
    int64_t _899_t7;
    uint8_t _899_t9;
    goto BB1080;
BB1080:
    _899_t6 = $negate_int64_t(_899_x, "tests/integration/expressions/sub-zero.orng:11:23:\n    x - 0 == x and 0 - x == -x\n                     ^");
    _899_t7 = $negate_int64_t(_899_x, "tests/integration/expressions/sub-zero.orng:11:30:\n    x - 0 == x and 0 - x == -x\n                            ^");
    _899_t9 = _899_t6==_899_t7;
    if (_899_t9) {
        goto BB1083;
    } else {
        goto BB1086;
    }
BB1083:
    _899_t0 = 1;
    goto BB1085;
BB1086:
    _899_t0 = 0;
    goto BB1085;
BB1085:
    _899_$retval = _899_t0;
    return _899_$retval;
}


int main(void) {
  printf("%ld",_894_main());
  return 0;
}
