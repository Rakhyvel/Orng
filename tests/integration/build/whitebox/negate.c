/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1840_main(void);


/* Function definitions */
int64_t _1840_main(void){
    int64_t _1841_x;
    int64_t* _1841_y;
    int64_t _1840_t5;
    int64_t _1840_t7;
    uint8_t _1840_t9;
    int64_t _1840_t4;
    int64_t _1840_$retval;
    _1841_x = 1;
    _1841_y = &_1841_x;
    _1840_t5 = $negate_int64_t(*_1841_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1840_t7 = -1;
    _1840_t9 = _1840_t5==_1840_t7;
    if (_1840_t9) {
        goto BB2086;
    } else {
        goto BB2090;
    }
BB2086:
    _1840_t4 = 32;
    goto BB2089;
BB2090:
    _1840_t4 = 10;
    goto BB2089;
BB2089:
    _1840_$retval = _1840_t4;
    return _1840_$retval;
}


int main(void) {
  printf("%ld",_1840_main());
  return 0;
}
