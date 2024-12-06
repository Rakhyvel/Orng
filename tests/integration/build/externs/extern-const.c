/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _2_main(void);


/* Function definitions */
int64_t _2_main(void){
    int64_t _2_t1;
    uint8_t _2_t3;
    int64_t _2_$retval;
    _2_t1 = 0;
    _2_t3 = EXIT_SUCCESS==_2_t1;
    if (_2_t3) {
        goto BB3;
    } else {
        goto BB7;
    }
BB3:
    _2_$retval = 327;
    return _2_$retval;
BB7:
    $lines[$line_idx++] = "tests/integration/externs/extern-const.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
