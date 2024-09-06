/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1914_main(void);


/* Function definitions */
int64_t _1914_main(void){
    int64_t _1915_x;
    int64_t* _1915_y;
    int64_t _1914_t5;
    int64_t _1914_t7;
    uint8_t _1914_t9;
    int64_t _1914_t4;
    int64_t _1914_$retval;
    _1915_x = 1;
    _1915_y = &_1915_x;
    _1914_t5 = $negate_int64_t(*_1915_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1914_t7 = -1;
    _1914_t9 = _1914_t5==_1914_t7;
    if (_1914_t9) {
        goto BB2135;
    } else {
        goto BB2139;
    }
BB2135:
    _1914_t4 = 32;
    goto BB2138;
BB2139:
    _1914_t4 = 10;
    goto BB2138;
BB2138:
    _1914_$retval = _1914_t4;
    return _1914_$retval;
}


int main(void) {
  printf("%ld",_1914_main());
  return 0;
}
