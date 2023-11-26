/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _49_main(void);

/* Function definitions */
int64_t _49_main(void) {
    int64_t _50_x;
    uint8_t _49_t2;
    int64_t _49_t3;
    int64_t _49_t0;
    int64_t _49_t5;
    int64_t _49_$retval;
    _50_x = 4;
    _49_t2 = 0;
    if (_49_t2) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _49_t3 = 3;
    _49_t0 = $add_int64_t(_50_x, _49_t3, "tests/integration/control-flow/if-else.orng:4:12:\n        x + 3\n          ^");
    goto BB4;
BB5:
    _49_t5 = 7;
    _49_t0 = $add_int64_t(_50_x, _49_t5, "tests/integration/control-flow/if-else.orng:6:12:\n        x + 7\n          ^");
    goto BB4;
BB4:
    _49_$retval = _49_t0;
    return _49_$retval;
}

int main(void) {
  printf("%ld",_49_main());
  return 0;
}
