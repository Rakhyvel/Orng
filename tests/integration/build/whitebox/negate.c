/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2001_main(void);


/* Function definitions */
int64_t _2001_main(void){
    int64_t _2002_x;
    int64_t* _2002_y;
    int64_t _2001_t5;
    int64_t _2001_t7;
    uint8_t _2001_t9;
    int64_t _2001_t4;
    int64_t _2001_$retval;
    _2002_x = 1;
    _2002_y = &_2002_x;
    _2001_t5 = $negate_int64_t(*_2002_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _2001_t7 = -1;
    _2001_t9 = _2001_t5==_2001_t7;
    if (_2001_t9) {
        goto BB2188;
    } else {
        goto BB2192;
    }
BB2188:
    _2001_t4 = 32;
    goto BB2191;
BB2192:
    _2001_t4 = 10;
    goto BB2191;
BB2191:
    _2001_$retval = _2001_t4;
    return _2001_$retval;
}


int main(void) {
  printf("%ld",_2001_main());
  return 0;
}
