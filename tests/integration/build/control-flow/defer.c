/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _126_main(void);

/* Function definitions */
int64_t _126_main(void) {
    int64_t _127_x;
    uint8_t _126_t4;
    uint8_t _126_t3;
    int64_t _126_$retval;
    _127_x = 2;
    _126_t4 = 1;
    if (_126_t4) {
        goto BB1;
    } else {
        goto BB11;
    }
BB1:
    _126_t3 = 1;
    goto BB2;
BB11:
    _126_t3 = 0;
    goto BB2;
BB2:
    if (_126_t3) {
        goto BB3;
    } else {
        goto BB9;
    }
BB3:
    _127_x = 4;
    _127_x = 14;
    _127_x = 24;
    _127_x = 34;
    goto BB9;
BB9:
    _126_$retval = _127_x;
    return _126_$retval;
}

int main(void) {
  printf("%ld",_126_main());
  return 0;
}
