/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1842_main(void);


/* Function definitions */
int64_t _1842_main(void){
    int64_t _1843_x;
    int64_t* _1843_y;
    int64_t _1842_t5;
    int64_t _1842_t7;
    uint8_t _1842_t9;
    int64_t _1842_t4;
    int64_t _1842_$retval;
    _1843_x = 1;
    _1843_y = &_1843_x;
    _1842_t5 = $negate_int64_t(*_1843_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1842_t7 = -1;
    _1842_t9 = _1842_t5==_1842_t7;
    if (_1842_t9) {
        goto BB2056;
    } else {
        goto BB2060;
    }
BB2056:
    _1842_t4 = 32;
    goto BB2059;
BB2060:
    _1842_t4 = 10;
    goto BB2059;
BB2059:
    _1842_$retval = _1842_t4;
    return _1842_$retval;
}


int main(void) {
  printf("%ld",_1842_main());
  return 0;
}
