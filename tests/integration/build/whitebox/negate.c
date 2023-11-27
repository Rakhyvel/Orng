/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1179_main(void);

/* Function definitions */
int64_t _1179_main(void) {
    int64_t _1180_x;
    int64_t* _1180_y;
    int64_t _1179_t3;
    int64_t _1179_t5;
    uint8_t _1179_t7;
    int64_t _1179_t2;
    int64_t _1179_$retval;
    _1180_x = 1;
    _1180_y = &_1180_x;
    _1179_t3 = $negate_int64_t(*_1180_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1179_t5 = -1;
    _1179_t7 = _1179_t3 == _1179_t5;
    if (_1179_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1179_t2 = 32;
    goto BB6;
BB7:
    _1179_t2 = 10;
    goto BB6;
BB6:
    _1179_$retval = _1179_t2;
    return _1179_$retval;
}

int main(void) {
  printf("%ld",_1179_main());
  return 0;
}
