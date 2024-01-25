/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1716_main(void);


/* Function definitions */
int64_t _1716_main(void){
    int64_t _1717_x;
    int64_t* _1717_y;
    int64_t _1716_t3;
    int64_t _1716_t5;
    uint8_t _1716_t7;
    int64_t _1716_t2;
    int64_t _1716_$retval;
    _1717_x = 1;
    _1717_y = &_1717_x;
    _1716_t3 = $negate_int64_t(*_1717_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1716_t5 = -1;
    _1716_t7 = _1716_t3==_1716_t5;
    if (_1716_t7) {
        goto BB1982;
    } else {
        goto BB1986;
    }
BB1982:
    _1716_t2 = 32;
    goto BB1985;
BB1986:
    _1716_t2 = 10;
    goto BB1985;
BB1985:
    _1716_$retval = _1716_t2;
    return _1716_$retval;
}


int main(void) {
  printf("%ld",_1716_main());
  return 0;
}
