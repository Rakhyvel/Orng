/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1895_main(void);


/* Function definitions */
int64_t _1895_main(void){
    int64_t _1896_x;
    int64_t* _1896_y;
    int64_t _1895_t5;
    int64_t _1895_t7;
    uint8_t _1895_t9;
    int64_t _1895_t4;
    int64_t _1895_$retval;
    _1896_x = 1;
    _1896_y = &_1896_x;
    _1895_t5 = $negate_int64_t(*_1896_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1895_t7 = -1;
    _1895_t9 = _1895_t5==_1895_t7;
    if (_1895_t9) {
        goto BB2114;
    } else {
        goto BB2118;
    }
BB2114:
    _1895_t4 = 32;
    goto BB2117;
BB2118:
    _1895_t4 = 10;
    goto BB2117;
BB2117:
    _1895_$retval = _1895_t4;
    return _1895_$retval;
}


int main(void) {
  printf("%ld",_1895_main());
  return 0;
}
