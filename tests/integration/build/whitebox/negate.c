/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1951_main(void);


/* Function definitions */
int64_t _1951_main(void){
    int64_t _1952_x;
    int64_t* _1952_y;
    int64_t _1951_t5;
    int64_t _1951_t7;
    uint8_t _1951_t9;
    int64_t _1951_t4;
    int64_t _1951_$retval;
    _1952_x = 1;
    _1952_y = &_1952_x;
    _1951_t5 = $negate_int64_t(*_1952_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1951_t7 = -1;
    _1951_t9 = _1951_t5==_1951_t7;
    if (_1951_t9) {
        goto BB2139;
    } else {
        goto BB2143;
    }
BB2139:
    _1951_t4 = 32;
    goto BB2142;
BB2143:
    _1951_t4 = 10;
    goto BB2142;
BB2142:
    _1951_$retval = _1951_t4;
    return _1951_$retval;
}


int main(void) {
  printf("%ld",_1951_main());
  return 0;
}
