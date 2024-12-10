/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _536_main(void);


/* Function definitions */
int64_t _536_main(void){
    int64_t _537_x;
    int64_t _538_i;
    int64_t _536_t5;
    uint8_t _536_t6;
    int64_t _536_t8;
    int64_t _536_$retval;
    _537_x = 0;
    _538_i = 0;
    goto BB607;
BB607:
    _536_t5 = 10;
    _536_t6 = _538_i<=_536_t5;
    if (_536_t6) {
        goto BB608;
    } else {
        goto BB613;
    }
BB608:
    _537_x = $add_int64_t(_537_x, _538_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _536_t8 = 1;
    _538_i = $add_int64_t(_538_i, _536_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB607;
BB613:
    _536_$retval = _537_x;
    return _536_$retval;
}


int main(void) {
  printf("%ld",_536_main());
  return 0;
}
