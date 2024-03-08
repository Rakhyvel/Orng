/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1784_main(void);


/* Function definitions */
int64_t _1784_main(void){
    int64_t _1785_x;
    int64_t* _1785_y;
    int64_t _1784_t3;
    int64_t _1784_t5;
    uint8_t _1784_t7;
    int64_t _1784_t2;
    int64_t _1784_$retval;
    _1785_x = 1;
    _1785_y = &_1785_x;
    _1784_t3 = $negate_int64_t(*_1785_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1784_t5 = -1;
    _1784_t7 = _1784_t3==_1784_t5;
    if (_1784_t7) {
        goto BB2034;
    } else {
        goto BB2038;
    }
BB2034:
    _1784_t2 = 32;
    goto BB2037;
BB2038:
    _1784_t2 = 10;
    goto BB2037;
BB2037:
    _1784_$retval = _1784_t2;
    return _1784_$retval;
}


int main(void) {
  printf("%ld",_1784_main());
  return 0;
}
