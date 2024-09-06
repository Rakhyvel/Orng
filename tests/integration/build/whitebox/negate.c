/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1953_main(void);


/* Function definitions */
int64_t _1953_main(void){
    int64_t _1954_x;
    int64_t* _1954_y;
    int64_t _1953_t5;
    int64_t _1953_t7;
    uint8_t _1953_t9;
    int64_t _1953_t4;
    int64_t _1953_$retval;
    _1954_x = 1;
    _1954_y = &_1954_x;
    _1953_t5 = $negate_int64_t(*_1954_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1953_t7 = -1;
    _1953_t9 = _1953_t5==_1953_t7;
    if (_1953_t9) {
        goto BB2141;
    } else {
        goto BB2145;
    }
BB2141:
    _1953_t4 = 32;
    goto BB2144;
BB2145:
    _1953_t4 = 10;
    goto BB2144;
BB2144:
    _1953_$retval = _1953_t4;
    return _1953_$retval;
}


int main(void) {
  printf("%ld",_1953_main());
  return 0;
}
