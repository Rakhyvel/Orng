/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1961_main(void);


/* Function definitions */
int64_t _1961_main(void){
    int64_t _1962_x;
    int64_t* _1962_y;
    int64_t _1961_t5;
    int64_t _1961_t7;
    uint8_t _1961_t9;
    int64_t _1961_t4;
    int64_t _1961_$retval;
    _1962_x = 1;
    _1962_y = &_1962_x;
    _1961_t5 = $negate_int64_t(*_1962_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1961_t7 = -1;
    _1961_t9 = _1961_t5==_1961_t7;
    if (_1961_t9) {
        goto BB2147;
    } else {
        goto BB2151;
    }
BB2147:
    _1961_t4 = 32;
    goto BB2150;
BB2151:
    _1961_t4 = 10;
    goto BB2150;
BB2150:
    _1961_$retval = _1961_t4;
    return _1961_$retval;
}


int main(void) {
  printf("%ld",_1961_main());
  return 0;
}
