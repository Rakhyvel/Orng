/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _452_main(void);


/* Function definitions */
int64_t _452_main(void){
    int64_t _453_x;
    int64_t _452_t3;
    uint8_t _452_t4;
    int64_t _452_t7;
    uint8_t _452_t8;
    int64_t _452_$retval;
    int64_t _452_t11;
    int64_t _452_t9;
    int64_t _452_t15;
    _453_x = 0;
    goto BB501;
BB501:
    _452_t3 = 100;
    _452_t4 = _453_x<_452_t3;
    if (_452_t4) {
        goto BB502;
    } else {
        goto BB506;
    }
BB502:
    _452_t7 = 36;
    _452_t8 = _453_x>=_452_t7;
    if (_452_t8) {
        goto BB504;
    } else {
        goto BB509;
    }
BB506:
    _452_$retval = _453_x;
    return _452_$retval;
BB504:
    _452_t11 = 2;
    _453_x = $add_int64_t(_453_x, _452_t11, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB506;
BB509:
    _452_t9 = 2;
    _453_x = $add_int64_t(_453_x, _452_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _452_t15 = 1;
    _453_x = $add_int64_t(_453_x, _452_t15, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB501;
}


int main(void) {
  printf("%ld",_452_main());
  return 0;
}
