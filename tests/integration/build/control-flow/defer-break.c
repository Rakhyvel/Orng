/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _450_main(void);


/* Function definitions */
int64_t _450_main(void){
    int64_t _451_x;
    int64_t _450_t3;
    uint8_t _450_t4;
    int64_t _450_t7;
    uint8_t _450_t8;
    int64_t _450_$retval;
    int64_t _450_t11;
    int64_t _450_t9;
    int64_t _450_t15;
    _451_x = 0;
    goto BB499;
BB499:
    _450_t3 = 100;
    _450_t4 = _451_x<_450_t3;
    if (_450_t4) {
        goto BB500;
    } else {
        goto BB504;
    }
BB500:
    _450_t7 = 36;
    _450_t8 = _451_x>=_450_t7;
    if (_450_t8) {
        goto BB502;
    } else {
        goto BB507;
    }
BB504:
    _450_$retval = _451_x;
    return _450_$retval;
BB502:
    _450_t11 = 2;
    _451_x = $add_int64_t(_451_x, _450_t11, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB504;
BB507:
    _450_t9 = 2;
    _451_x = $add_int64_t(_451_x, _450_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _450_t15 = 1;
    _451_x = $add_int64_t(_451_x, _450_t15, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB499;
}


int main(void) {
  printf("%ld",_450_main());
  return 0;
}
