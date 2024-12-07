/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1981_main(void);


/* Function definitions */
int64_t _1981_main(void){
    int64_t _1982_x;
    int64_t* _1982_y;
    int64_t _1981_t5;
    int64_t _1981_t7;
    uint8_t _1981_t9;
    int64_t _1981_t4;
    int64_t _1981_$retval;
    _1982_x = 1;
    _1982_y = &_1982_x;
    _1981_t5 = $negate_int64_t(*_1982_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _1981_t7 = -1;
    _1981_t9 = _1981_t5==_1981_t7;
    if (_1981_t9) {
        goto BB2169;
    } else {
        goto BB2173;
    }
BB2169:
    _1981_t4 = 32;
    goto BB2172;
BB2173:
    _1981_t4 = 10;
    goto BB2172;
BB2172:
    _1981_$retval = _1981_t4;
    return _1981_$retval;
}


int main(void) {
  printf("%ld",_1981_main());
  return 0;
}
