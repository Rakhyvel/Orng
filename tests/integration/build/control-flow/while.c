/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _516_main(void);


/* Function definitions */
int64_t _516_main(void){
    int64_t _517_x;
    int64_t _518_i;
    int64_t _516_t5;
    uint8_t _516_t6;
    int64_t _516_t8;
    int64_t _516_$retval;
    _517_x = 0;
    _518_i = 0;
    goto BB588;
BB588:
    _516_t5 = 10;
    _516_t6 = _518_i<=_516_t5;
    if (_516_t6) {
        goto BB589;
    } else {
        goto BB594;
    }
BB589:
    _517_x = $add_int64_t(_517_x, _518_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _516_t8 = 1;
    _518_i = $add_int64_t(_518_i, _516_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB588;
BB594:
    _516_$retval = _517_x;
    return _516_$retval;
}


int main(void) {
  printf("%ld",_516_main());
  return 0;
}
