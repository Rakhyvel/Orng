/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1967_main(void);


/* Function definitions */
int64_t _1967_main(void){
    int64_t _1968_x;
    int64_t* _1968_y;
    int64_t _1967_t5;
    int64_t _1967_t7;
    uint8_t _1967_t9;
    int64_t _1967_t4;
    int64_t _1967_$retval;
    _1968_x = 1;
    _1968_y = &_1968_x;
    _1967_t5 = $negate_int64_t(*_1968_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1967_t7 = -1;
    _1967_t9 = _1967_t5==_1967_t7;
    if (_1967_t9) {
        goto BB2150;
    } else {
        goto BB2154;
    }
BB2150:
    _1967_t4 = 32;
    goto BB2153;
BB2154:
    _1967_t4 = 10;
    goto BB2153;
BB2153:
    _1967_$retval = _1967_t4;
    return _1967_$retval;
}


int main(void) {
  printf("%ld",_1967_main());
  return 0;
}
