/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _61_main(void);

/* Function definitions */
int64_t _61_main(void) {
    int64_t _62_x;
    uint8_t _61_t2;
    int64_t _61_t3;
    int64_t _61_t0;
    int64_t _61_$retval;
    _62_x = 4;
    _61_t2 = 1;
    if (_61_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _61_t3 = 7;
    _61_t0 = $add_int64_t(_62_x, _61_t3, "tests/integration/control-flow/if.orng:4:12:\n        x + 7\n          ^");
    goto BB4;
BB5:
    _61_t0 = 3;
    goto BB4;
BB4:
    _61_$retval = _61_t0;
    return _61_$retval;
}

int main(void) {
  printf("%ld",_61_main());
  return 0;
}
