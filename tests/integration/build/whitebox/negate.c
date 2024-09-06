/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1921_main(void);


/* Function definitions */
int64_t _1921_main(void){
    int64_t _1922_x;
    int64_t* _1922_y;
    int64_t _1921_t5;
    int64_t _1921_t7;
    uint8_t _1921_t9;
    int64_t _1921_t4;
    int64_t _1921_$retval;
    _1922_x = 1;
    _1922_y = &_1922_x;
    _1921_t5 = $negate_int64_t(*_1922_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1921_t7 = -1;
    _1921_t9 = _1921_t5==_1921_t7;
    if (_1921_t9) {
        goto BB2139;
    } else {
        goto BB2143;
    }
BB2139:
    _1921_t4 = 32;
    goto BB2142;
BB2143:
    _1921_t4 = 10;
    goto BB2142;
BB2142:
    _1921_$retval = _1921_t4;
    return _1921_$retval;
}


int main(void) {
  printf("%ld",_1921_main());
  return 0;
}
