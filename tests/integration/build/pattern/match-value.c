/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _156_main(void);

/* Function definitions */
int64_t _156_main(void) {
    uint8_t _156_t3;
    int64_t _156_$retval;
    _156_t3 = 1;
    if (_156_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _156_$retval = 166;
    return _156_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/pattern/match-value.orng:5:28:\n        else => unreachable\n                          ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_156_main());
  return 0;
}
