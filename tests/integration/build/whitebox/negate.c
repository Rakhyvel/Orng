/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1973_main(void);


/* Function definitions */
int64_t _1973_main(void){
    int64_t _1974_x;
    int64_t* _1974_y;
    int64_t _1973_t5;
    int64_t _1973_t7;
    uint8_t _1973_t9;
    int64_t _1973_t4;
    int64_t _1973_$retval;
    _1974_x = 1;
    _1974_y = &_1974_x;
    _1973_t5 = $negate_int64_t(*_1974_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1973_t7 = -1;
    _1973_t9 = _1973_t5==_1973_t7;
    if (_1973_t9) {
        goto BB2159;
    } else {
        goto BB2163;
    }
BB2159:
    _1973_t4 = 32;
    goto BB2162;
BB2163:
    _1973_t4 = 10;
    goto BB2162;
BB2162:
    _1973_$retval = _1973_t4;
    return _1973_$retval;
}


int main(void) {
  printf("%ld",_1973_main());
  return 0;
}
