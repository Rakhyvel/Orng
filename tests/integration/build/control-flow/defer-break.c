/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _404_main(void);

/* Function definitions */
int64_t _404_main(void){
    int64_t _405_x;
    int64_t _404_t2;
    uint8_t _404_t3;
    int64_t _404_t5;
    uint8_t _404_t6;
    int64_t _404_$retval;
    int64_t _404_t9;
    int64_t _404_t7;
    int64_t _404_t13;
    _405_x = 0;
    goto BB468;
BB468:
    _404_t2 = 100;
    _404_t3 = _405_x<_404_t2;
    if (_404_t3) {
        goto BB469;
    } else {
        goto BB473;
    }
BB469:
    _404_t5 = 36;
    _404_t6 = _405_x>=_404_t5;
    if (_404_t6) {
        goto BB471;
    } else {
        goto BB476;
    }
BB473:
    _404_$retval = _405_x;
    return _404_$retval;
BB471:
    _404_t9 = 2;
    _405_x = $add_int64_t(_405_x, _404_t9, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    goto BB473;
BB476:
    _404_t7 = 2;
    _405_x = $add_int64_t(_405_x, _404_t7, "tests/integration/control-flow/defer-break.orng:5:19:\n        defer x += 2\n                 ^");
    _404_t13 = 1;
    _405_x = $add_int64_t(_405_x, _404_t13, "tests/integration/control-flow/defer-break.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB468;
}

int main(void) {
  printf("%ld",_404_main());
  return 0;
}
