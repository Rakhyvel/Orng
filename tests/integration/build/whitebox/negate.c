/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1671_main(void);

/* Function definitions */
int64_t _1671_main(void) {
    int64_t _1672_x;
    int64_t* _1672_y;
    int64_t _1671_t3;
    int64_t _1671_t5;
    uint8_t _1671_t7;
    int64_t _1671_t2;
    int64_t _1671_$retval;
    _1672_x = 1;
    _1672_y = &_1672_x;
    _1671_t3 = $negate_int64_t(*_1672_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1671_t5 = -1;
    _1671_t7 = _1671_t3 == _1671_t5;
    if (_1671_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1671_t2 = 32;
    goto BB6;
BB7:
    _1671_t2 = 10;
    goto BB6;
BB6:
    _1671_$retval = _1671_t2;
    return _1671_$retval;
}

int main(void) {
  printf("%ld",_1671_main());
  return 0;
}
