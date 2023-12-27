/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1579_main(void);

/* Function definitions */
int64_t _1579_main(void){
    int64_t _1580_x;
    int64_t* _1580_y;
    int64_t _1579_t3;
    int64_t _1579_t5;
    uint8_t _1579_t7;
    int64_t _1579_t2;
    int64_t _1579_$retval;
    _1580_x = 1;
    _1580_y = &_1580_x;
    _1579_t3 = $negate_int64_t(*_1580_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1579_t5 = -1;
    _1579_t7 = _1579_t3==_1579_t5;
    if (_1579_t7) {
        goto BB1904;
    } else {
        goto BB1908;
    }
BB1904:
    _1579_t2 = 32;
    goto BB1907;
BB1908:
    _1579_t2 = 10;
    goto BB1907;
BB1907:
    _1579_$retval = _1579_t2;
    return _1579_$retval;
}

int main(void) {
  printf("%ld",_1579_main());
  return 0;
}
