/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _51_main(void);

/* Function definitions */
int64_t _51_main(void) {
    int64_t _52_x;
    int64_t* _52_y;
    int64_t _51_t3;
    int64_t _51_t5;
    uint8_t _51_t7;
    uint8_t _51_t6;
    int64_t _51_t2;
    int64_t _51_$retval;
    _52_x = 1;
    _52_y = &_52_x;
    _51_t3 = $negate_int64_t(*_52_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _51_t5 = -1;
    _51_t7 = _51_t3 == _51_t5;
    if (_51_t7) {
        goto BB1;
    } else {
        goto BB9;
    }
BB1:
    _51_t6 = 1;
    goto BB2;
BB9:
    _51_t6 = 0;
    goto BB2;
BB2:
    if (_51_t6) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _51_t2 = 32;
    goto BB6;
BB7:
    _51_t2 = 10;
    goto BB6;
BB6:
    _51_$retval = _51_t2;
    return _51_$retval;
}

int main(void) {
  printf("%ld",_51_main());
  return 0;
}
