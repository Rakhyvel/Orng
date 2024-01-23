/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1689_main(void);


/* Function definitions */
int64_t _1689_main(void){
    int64_t _1690_x;
    int64_t* _1690_y;
    int64_t _1689_t3;
    int64_t _1689_t5;
    uint8_t _1689_t7;
    int64_t _1689_t2;
    int64_t _1689_$retval;
    _1690_x = 1;
    _1690_y = &_1690_x;
    _1689_t3 = $negate_int64_t(*_1690_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1689_t5 = -1;
    _1689_t7 = _1689_t3==_1689_t5;
    if (_1689_t7) {
        goto BB1960;
    } else {
        goto BB1964;
    }
BB1960:
    _1689_t2 = 32;
    goto BB1963;
BB1964:
    _1689_t2 = 10;
    goto BB1963;
BB1963:
    _1689_$retval = _1689_t2;
    return _1689_$retval;
}


int main(void) {
  printf("%ld",_1689_main());
  return 0;
}
