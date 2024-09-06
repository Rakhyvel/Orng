/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _524_main(void);


/* Function definitions */
int64_t _524_main(void){
    int64_t _525_x;
    int64_t _526_i;
    int64_t _524_t5;
    uint8_t _524_t6;
    int64_t _524_t8;
    int64_t _524_$retval;
    _525_x = 0;
    _526_i = 0;
    goto BB594;
BB594:
    _524_t5 = 10;
    _524_t6 = _526_i<=_524_t5;
    if (_524_t6) {
        goto BB595;
    } else {
        goto BB600;
    }
BB595:
    _525_x = $add_int64_t(_525_x, _526_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _524_t8 = 1;
    _526_i = $add_int64_t(_526_i, _524_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB594;
BB600:
    _524_$retval = _525_x;
    return _524_$retval;
}


int main(void) {
  printf("%ld",_524_main());
  return 0;
}
