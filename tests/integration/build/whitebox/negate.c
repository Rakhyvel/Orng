/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1857_main(void);

/* Function definitions */
int64_t _1857_main(void){
    int64_t _1858_x;
    int64_t* _1858_y;
    int64_t _1857_t3;
    int64_t _1857_t5;
    uint8_t _1857_t7;
    int64_t _1857_t2;
    int64_t _1857_$retval;
    _1858_x = 1;
    _1858_y = &_1858_x;
    _1857_t3 = $negate_int64_t(*_1858_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1857_t5 = -1;
    _1857_t7 = _1857_t3 == _1857_t5;
    if (_1857_t7) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _1857_t2 = 32;
    goto BB6;
BB7:
    _1857_t2 = 10;
    goto BB6;
BB6:
    _1857_$retval = _1857_t2;
    return _1857_$retval;
}

int main(void) {
  printf("%ld",_1857_main());
  return 0;
}
