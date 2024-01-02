/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1612_main(void);

/* Function definitions */
int64_t _1612_main(void){
    int64_t _1613_x;
    int64_t* _1613_y;
    int64_t _1612_t3;
    int64_t _1612_t5;
    uint8_t _1612_t7;
    int64_t _1612_t2;
    int64_t _1612_$retval;
    _1613_x = 1;
    _1613_y = &_1613_x;
    _1612_t3 = $negate_int64_t(*_1613_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1612_t5 = -1;
    _1612_t7 = _1612_t3==_1612_t5;
    if (_1612_t7) {
        goto BB1897;
    } else {
        goto BB1901;
    }
BB1897:
    _1612_t2 = 32;
    goto BB1900;
BB1901:
    _1612_t2 = 10;
    goto BB1900;
BB1900:
    _1612_$retval = _1612_t2;
    return _1612_$retval;
}

int main(void) {
  printf("%ld",_1612_main());
  return 0;
}
