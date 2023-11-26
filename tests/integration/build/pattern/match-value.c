/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _871_main(void);

/* Function definitions */
int64_t _871_main(void) {
    uint8_t _871_t3;
    int64_t _871_$retval;
    _871_t3 = 1;
    if (_871_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _871_$retval = 166;
    return _871_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-value.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_871_main());
  return 0;
}
