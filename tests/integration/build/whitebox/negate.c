/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1148_main(void);

/* Function definitions */
int64_t _1148_main(void) {
    int64_t _1149_x;
    int64_t* _1149_y;
    int64_t _1148_t3;
    int64_t _1148_t5;
    uint8_t _1148_t7;
    uint8_t _1148_t6;
    int64_t _1148_t2;
    int64_t _1148_$retval;
    _1149_x = 1;
    _1149_y = &_1149_x;
    _1148_t3 = $negate_int64_t(*_1149_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1148_t5 = -1;
    _1148_t7 = _1148_t3 == _1148_t5;
    if (_1148_t7) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _1148_t6 = 1;
    goto BB2;
BB9:
    _1148_t6 = 0;
    goto BB2;
BB2:
    if (_1148_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1148_t2 = 32;
    goto BB6;
BB7:
    _1148_t2 = 10;
    goto BB6;
BB6:
    _1148_$retval = _1148_t2;
    return _1148_$retval;
}

int main(void) {
  printf("%ld",_1148_main());
  return 0;
}
