/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1906_main(void);


/* Function definitions */
int64_t _1906_main(void){
    int64_t _1907_x;
    int64_t* _1907_y;
    int64_t _1906_t5;
    int64_t _1906_t7;
    uint8_t _1906_t9;
    int64_t _1906_t4;
    int64_t _1906_$retval;
    _1907_x = 1;
    _1907_y = &_1907_x;
    _1906_t5 = $negate_int64_t(*_1907_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1906_t7 = -1;
    _1906_t9 = _1906_t5==_1906_t7;
    if (_1906_t9) {
        goto BB2124;
    } else {
        goto BB2128;
    }
BB2124:
    _1906_t4 = 32;
    goto BB2127;
BB2128:
    _1906_t4 = 10;
    goto BB2127;
BB2127:
    _1906_$retval = _1906_t4;
    return _1906_$retval;
}


int main(void) {
  printf("%ld",_1906_main());
  return 0;
}
