/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1645_main(void);

/* Function definitions */
int64_t _1645_main(void){
    int64_t _1646_x;
    int64_t* _1646_y;
    int64_t _1645_t3;
    int64_t _1645_t5;
    uint8_t _1645_t7;
    int64_t _1645_t2;
    int64_t _1645_$retval;
    _1646_x = 1;
    _1646_y = &_1646_x;
    _1645_t3 = $negate_int64_t(*_1646_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1645_t5 = -1;
    _1645_t7 = _1645_t3==_1645_t5;
    if (_1645_t7) {
        goto BB1920;
    } else {
        goto BB1924;
    }
BB1920:
    _1645_t2 = 32;
    goto BB1923;
BB1924:
    _1645_t2 = 10;
    goto BB1923;
BB1923:
    _1645_$retval = _1645_t2;
    return _1645_$retval;
}

int main(void) {
  printf("%ld",_1645_main());
  return 0;
}
