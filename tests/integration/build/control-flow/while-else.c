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
    int64_t _526_x;
    int64_t _524_t3;
    uint8_t _524_t4;
    int64_t _524_t5;
    int64_t _524_t8;
    int64_t _524_$retval;
    _526_x = 0;
    goto BB593;
BB593:
    _524_t3 = 10;
    _524_t4 = _526_x<_524_t3;
    if (_524_t4) {
        goto BB594;
    } else {
        goto BB598;
    }
BB594:
    _524_t5 = 1;
    _526_x = $add_int64_t(_526_x, _524_t5, "tests/integration/control-flow/while-else.orng:4:13:\n        x += 1\n           ^");
    _524_t8 = 1;
    _526_x = $add_int64_t(_526_x, _524_t8, "tests/integration/control-flow/while-else.orng:3:43:\n    while let mut x: Int = 0; x < 10; x += 1 {\n                                         ^");
    goto BB593;
BB598:
    _524_$retval = _526_x;
    return _524_$retval;
}


int main(void) {
  printf("%ld",_524_main());
  return 0;
}
