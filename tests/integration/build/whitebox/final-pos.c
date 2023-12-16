/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1661_main(void);

/* Function definitions */
int64_t _1661_main(void){
    int64_t _1662_x;
    int64_t _1661_t2;
    uint8_t _1661_t3;
    int64_t _1661_t5;
    uint8_t _1661_t7;
    int64_t _1661_t10;
    int64_t _1661_$retval;
    int64_t _1661_t8;
    _1662_x = 0;
    goto BB1;
BB1:
    _1661_t2 = 100;
    _1661_t3 = _1662_x < _1661_t2;
    if (_1661_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1661_t5 = 40;
    _1661_t7 = _1662_x == _1661_t5;
    if (_1661_t7) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1661_$retval = _1662_x;
    return _1661_$retval;
BB5:
    _1661_t8 = 1;
    _1662_x = $add_int64_t(_1662_x, _1661_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _1661_t10 = 1;
    _1662_x = $add_int64_t(_1662_x, _1661_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1661_main());
  return 0;
}
