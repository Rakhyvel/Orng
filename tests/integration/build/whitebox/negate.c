/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1617_main(void);

/* Function definitions */
int64_t _1617_main(void){
    int64_t _1618_x;
    int64_t* _1618_y;
    int64_t _1617_t3;
    int64_t _1617_t5;
    uint8_t _1617_t7;
    int64_t _1617_t2;
    int64_t _1617_$retval;
    _1618_x = 1;
    _1618_y = &_1618_x;
    _1617_t3 = $negate_int64_t(*_1618_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1617_t5 = -1;
    _1617_t7 = _1617_t3==_1617_t5;
    if (_1617_t7) {
        goto BB1901;
    } else {
        goto BB1905;
    }
BB1901:
    _1617_t2 = 32;
    goto BB1904;
BB1905:
    _1617_t2 = 10;
    goto BB1904;
BB1904:
    _1617_$retval = _1617_t2;
    return _1617_$retval;
}

int main(void) {
  printf("%ld",_1617_main());
  return 0;
}
