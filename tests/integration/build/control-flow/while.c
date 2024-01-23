/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _490_main(void);


/* Function definitions */
int64_t _490_main(void){
    int64_t _491_x;
    int64_t _492_i;
    int64_t _490_t3;
    uint8_t _490_t4;
    int64_t _490_t6;
    int64_t _490_$retval;
    _491_x = 0;
    _492_i = 0;
    goto BB576;
BB576:
    _490_t3 = 10;
    _490_t4 = _492_i<=_490_t3;
    if (_490_t4) {
        goto BB577;
    } else {
        goto BB582;
    }
BB577:
    _491_x = $add_int64_t(_491_x, _492_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _490_t6 = 1;
    _492_i = $add_int64_t(_492_i, _490_t6, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB576;
BB582:
    _490_$retval = _491_x;
    return _490_$retval;
}


int main(void) {
  printf("%ld",_490_main());
  return 0;
}
