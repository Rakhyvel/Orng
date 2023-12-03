/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1217_main(void);

/* Function definitions */
int64_t _1217_main(void) {
    int64_t _1218_x;
    int64_t* _1218_y;
    int64_t _1217_t3;
    int64_t _1217_t5;
    uint8_t _1217_t7;
    int64_t _1217_t2;
    int64_t _1217_$retval;
    _1218_x = 1;
    _1218_y = &_1218_x;
    _1217_t3 = $negate_int64_t(*_1218_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1217_t5 = -1;
    _1217_t7 = _1217_t3 == _1217_t5;
    if (_1217_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1217_t2 = 32;
    goto BB6;
BB7:
    _1217_t2 = 10;
    goto BB6;
BB6:
    _1217_$retval = _1217_t2;
    return _1217_$retval;
}

int main(void) {
  printf("%ld",_1217_main());
  return 0;
}
