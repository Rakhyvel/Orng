/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _54_main(void);


/* Function definitions */
int64_t _54_main(void){
    int64_t _55_x;
    int64_t* _55_y;
    int64_t _54_t5;
    int64_t _54_t7;
    uint8_t _54_t9;
    int64_t _54_t4;
    int64_t _54_$retval;
    _55_x = 1;
    _55_y = &_55_x;
    _54_t5 = $negate_int64_t(*_55_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _54_t7 = -1;
    _54_t9 = _54_t5==_54_t7;
    if (_54_t9) {
        goto BB82;
    } else {
        goto BB86;
    }
BB82:
    _54_t4 = 32;
    goto BB85;
BB86:
    _54_t4 = 10;
    goto BB85;
BB85:
    _54_$retval = _54_t4;
    return _54_$retval;
}


int main(void) {
  printf("%ld",_54_main());
  return 0;
}
