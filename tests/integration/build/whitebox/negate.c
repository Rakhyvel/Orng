/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1604_main(void);

/* Function definitions */
int64_t _1604_main(void){
    int64_t _1605_x;
    int64_t* _1605_y;
    int64_t _1604_t3;
    int64_t _1604_t5;
    uint8_t _1604_t7;
    int64_t _1604_t2;
    int64_t _1604_$retval;
    _1605_x = 1;
    _1605_y = &_1605_x;
    _1604_t3 = $negate_int64_t(*_1605_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1604_t5 = -1;
    _1604_t7 = _1604_t3==_1604_t5;
    if (_1604_t7) {
        goto BB1901;
    } else {
        goto BB1905;
    }
BB1901:
    _1604_t2 = 32;
    goto BB1904;
BB1905:
    _1604_t2 = 10;
    goto BB1904;
BB1904:
    _1604_$retval = _1604_t2;
    return _1604_$retval;
}

int main(void) {
  printf("%ld",_1604_main());
  return 0;
}
