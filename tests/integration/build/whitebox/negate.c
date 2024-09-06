/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1946_main(void);


/* Function definitions */
int64_t _1946_main(void){
    int64_t _1947_x;
    int64_t* _1947_y;
    int64_t _1946_t5;
    int64_t _1946_t7;
    uint8_t _1946_t9;
    int64_t _1946_t4;
    int64_t _1946_$retval;
    _1947_x = 1;
    _1947_y = &_1947_x;
    _1946_t5 = $negate_int64_t(*_1947_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1946_t7 = -1;
    _1946_t9 = _1946_t5==_1946_t7;
    if (_1946_t9) {
        goto BB2139;
    } else {
        goto BB2143;
    }
BB2139:
    _1946_t4 = 32;
    goto BB2142;
BB2143:
    _1946_t4 = 10;
    goto BB2142;
BB2142:
    _1946_$retval = _1946_t4;
    return _1946_$retval;
}


int main(void) {
  printf("%ld",_1946_main());
  return 0;
}
