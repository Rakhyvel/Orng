/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _538_main(void);


/* Function definitions */
int64_t _538_main(void){
    int64_t _539_x;
    int64_t _540_i;
    int64_t _538_t5;
    uint8_t _538_t6;
    int64_t _538_t8;
    int64_t _538_$retval;
    _539_x = 0;
    _540_i = 0;
    goto BB609;
BB609:
    _538_t5 = 10;
    _538_t6 = _540_i<=_538_t5;
    if (_538_t6) {
        goto BB610;
    } else {
        goto BB615;
    }
BB610:
    _539_x = $add_int64_t(_539_x, _540_i, "tests/integration/control-flow/while.orng:5:16:\n        x = x + i\n              ^");
    _538_t8 = 1;
    _540_i = $add_int64_t(_540_i, _538_t8, "tests/integration/control-flow/while.orng:4:47:\n    while let mut i: Int = 0; i <= 10; i = i + 1 {\n                                             ^");
    goto BB609;
BB615:
    _538_$retval = _539_x;
    return _538_$retval;
}


int main(void) {
  printf("%ld",_538_main());
  return 0;
}
