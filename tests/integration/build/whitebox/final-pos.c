/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1157_main(void);

/* Function definitions */
int64_t _1157_main(void) {
    int64_t _1158_x;
    int64_t _1157_t2;
    uint8_t _1157_t3;
    int64_t _1157_t5;
    uint8_t _1157_t7;
    int64_t _1157_t10;
    int64_t _1157_$retval;
    int64_t _1157_t8;
    _1158_x = 0;
    goto BB1;
BB1:
    _1157_t2 = 100;
    _1157_t3 = _1158_x < _1157_t2;
    if (_1157_t3) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _1157_t5 = 40;
    _1157_t7 = _1158_x == _1157_t5;
    if (_1157_t7) {
        goto BB5;
    } else {
        goto BB11;
    }
BB7:
    _1157_$retval = _1158_x;
    return _1157_$retval;
BB5:
    _1157_t8 = 1;
    _1158_x = $add_int64_t(_1158_x, _1157_t8, "tests/integration/whitebox/final-pos.orng:6:17:\n            x += 1\n               ^");
    goto BB7;
BB11:
    _1157_t10 = 1;
    _1158_x = $add_int64_t(_1158_x, _1157_t10, "tests/integration/whitebox/final-pos.orng:4:24:\n    while x < 100; x += 1 {\n                      ^");
    goto BB1;
}

int main(void) {
  printf("%ld",_1157_main());
  return 0;
}
