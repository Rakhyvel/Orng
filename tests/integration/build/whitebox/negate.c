/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1609_main(void);

/* Function definitions */
int64_t _1609_main(void){
    int64_t _1610_x;
    int64_t* _1610_y;
    int64_t _1609_t3;
    int64_t _1609_t5;
    uint8_t _1609_t7;
    int64_t _1609_t2;
    int64_t _1609_$retval;
    _1610_x = 1;
    _1610_y = &_1610_x;
    _1609_t3 = $negate_int64_t(*_1610_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1609_t5 = -1;
    _1609_t7 = _1609_t3==_1609_t5;
    if (_1609_t7) {
        goto BB1905;
    } else {
        goto BB1909;
    }
BB1905:
    _1609_t2 = 32;
    goto BB1908;
BB1909:
    _1609_t2 = 10;
    goto BB1908;
BB1908:
    _1609_$retval = _1609_t2;
    return _1609_$retval;
}

int main(void) {
  printf("%ld",_1609_main());
  return 0;
}
