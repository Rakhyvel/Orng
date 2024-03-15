/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1806_main(void);


/* Function definitions */
int64_t _1806_main(void){
    int64_t _1807_x;
    int64_t* _1807_y;
    int64_t _1806_t5;
    int64_t _1806_t7;
    uint8_t _1806_t9;
    int64_t _1806_t4;
    int64_t _1806_$retval;
    _1807_x = 1;
    _1807_y = &_1807_x;
    _1806_t5 = $negate_int64_t(*_1807_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1806_t7 = -1;
    _1806_t9 = _1806_t5==_1806_t7;
    if (_1806_t9) {
        goto BB2033;
    } else {
        goto BB2037;
    }
BB2033:
    _1806_t4 = 32;
    goto BB2036;
BB2037:
    _1806_t4 = 10;
    goto BB2036;
BB2036:
    _1806_$retval = _1806_t4;
    return _1806_$retval;
}


int main(void) {
  printf("%ld",_1806_main());
  return 0;
}
