/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1956_main(void);


/* Function definitions */
int64_t _1956_main(void){
    int64_t _1957_x;
    int64_t* _1957_y;
    int64_t _1956_t5;
    int64_t _1956_t7;
    uint8_t _1956_t9;
    int64_t _1956_t4;
    int64_t _1956_$retval;
    _1957_x = 1;
    _1957_y = &_1957_x;
    _1956_t5 = $negate_int64_t(*_1957_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1956_t7 = -1;
    _1956_t9 = _1956_t5==_1956_t7;
    if (_1956_t9) {
        goto BB2143;
    } else {
        goto BB2147;
    }
BB2143:
    _1956_t4 = 32;
    goto BB2146;
BB2147:
    _1956_t4 = 10;
    goto BB2146;
BB2146:
    _1956_$retval = _1956_t4;
    return _1956_$retval;
}


int main(void) {
  printf("%ld",_1956_main());
  return 0;
}
