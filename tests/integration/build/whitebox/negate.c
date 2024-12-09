/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1986_main(void);


/* Function definitions */
int64_t _1986_main(void){
    int64_t _1987_x;
    int64_t* _1987_y;
    int64_t _1986_t5;
    int64_t _1986_t7;
    uint8_t _1986_t9;
    int64_t _1986_t4;
    int64_t _1986_$retval;
    _1987_x = 1;
    _1987_y = &_1987_x;
    _1986_t5 = $negate_int64_t(*_1987_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1986_t7 = -1;
    _1986_t9 = _1986_t5==_1986_t7;
    if (_1986_t9) {
        goto BB2172;
    } else {
        goto BB2176;
    }
BB2172:
    _1986_t4 = 32;
    goto BB2175;
BB2176:
    _1986_t4 = 10;
    goto BB2175;
BB2175:
    _1986_$retval = _1986_t4;
    return _1986_$retval;
}


int main(void) {
  printf("%ld",_1986_main());
  return 0;
}
