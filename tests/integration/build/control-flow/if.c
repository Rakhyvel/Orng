/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _153_main(void);

/* Function definitions */
int64_t _153_main(void) {
    int64_t _154_x;
    uint8_t _153_t2;
    int64_t _153_t3;
    int64_t _153_t0;
    int64_t _153_$retval;
    _154_x = 4;
    _153_t2 = 1;
    if (_153_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _153_t3 = 7;
    _153_t0 = $add_int64_t(_154_x, _153_t3, "tests/integration/control-flow/if.orng:4:12:\n        x + 7\n          ^");
    goto BB4;
BB5:
    _153_t0 = 3;
    goto BB4;
BB4:
    _153_$retval = _153_t0;
    return _153_$retval;
}

int main(void) {
  printf("%ld",_153_main());
  return 0;
}
