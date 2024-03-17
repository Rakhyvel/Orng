/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1818_main(void);


/* Function definitions */
int64_t _1818_main(void){
    int64_t _1819_x;
    int64_t* _1819_y;
    int64_t _1818_t5;
    int64_t _1818_t7;
    uint8_t _1818_t9;
    int64_t _1818_t4;
    int64_t _1818_$retval;
    _1819_x = 1;
    _1819_y = &_1819_x;
    _1818_t5 = $negate_int64_t(*_1819_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1818_t7 = -1;
    _1818_t9 = _1818_t5==_1818_t7;
    if (_1818_t9) {
        goto BB2039;
    } else {
        goto BB2043;
    }
BB2039:
    _1818_t4 = 32;
    goto BB2042;
BB2043:
    _1818_t4 = 10;
    goto BB2042;
BB2042:
    _1818_$retval = _1818_t4;
    return _1818_$retval;
}


int main(void) {
  printf("%ld",_1818_main());
  return 0;
}
