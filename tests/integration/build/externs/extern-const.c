/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _943_main(void);


/* Function definitions */
int64_t _943_main(void){
    int64_t _943_t1;
    uint8_t _943_t3;
    int64_t _943_$retval;
    _943_t1 = 0;
    _943_t3 = EXIT_SUCCESS==_943_t1;
    if (_943_t3) {
        goto BB1122;
    } else {
        goto BB1126;
    }
BB1122:
    _943_$retval = 327;
    return _943_$retval;
BB1126:
    $lines[$line_idx++] = "tests/integration/externs/extern-const.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_943_main());
  return 0;
}
