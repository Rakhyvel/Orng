/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _521_main(void);


/* Function definitions */
int64_t _521_main(void){
    int64_t _522_x;
    int64_t _523_i;
    int64_t _521_t5;
    uint8_t _521_t6;
    int64_t _521_t8;
    int64_t _521_$retval;
    _522_x = 0;
    _523_i = 0;
    goto BB591;
BB591:
    _521_t5 = 10;
    _521_t6 = _523_i<=_521_t5;
    if (_521_t6) {
        goto BB592;
    } else {
        goto BB597;
    }
BB592:
    _522_x = $add_int64_t(_522_x, _523_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _521_t8 = 1;
    _523_i = $add_int64_t(_523_i, _521_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB591;
BB597:
    _521_$retval = _522_x;
    return _521_$retval;
}


int main(void) {
  printf("%ld",_521_main());
  return 0;
}
