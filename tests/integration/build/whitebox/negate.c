/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2003_main(void);


/* Function definitions */
int64_t _2003_main(void){
    int64_t _2004_x;
    int64_t* _2004_y;
    int64_t _2003_t5;
    int64_t _2003_t7;
    uint8_t _2003_t9;
    int64_t _2003_t4;
    int64_t _2003_$retval;
    _2004_x = 1;
    _2004_y = &_2004_x;
    _2003_t5 = $negate_int64_t(*_2004_y, "tests/integration/whitebox/negate.orng:5:9:\n    if -y^ == -1 {\n       ^");
    _2003_t7 = -1;
    _2003_t9 = _2003_t5==_2003_t7;
    if (_2003_t9) {
        goto BB2190;
    } else {
        goto BB2194;
    }
BB2190:
    _2003_t4 = 32;
    goto BB2193;
BB2194:
    _2003_t4 = 10;
    goto BB2193;
BB2193:
    _2003_$retval = _2003_t4;
    return _2003_$retval;
}


int main(void) {
  printf("%ld",_2003_main());
  return 0;
}
