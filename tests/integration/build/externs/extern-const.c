/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _945_main(void);


/* Function definitions */
int64_t _945_main(void){
    int64_t _945_t1;
    uint8_t _945_t3;
    int64_t _945_$retval;
    _945_t1 = 0;
    _945_t3 = EXIT_SUCCESS==_945_t1;
    if (_945_t3) {
        goto BB1124;
    } else {
        goto BB1128;
    }
BB1124:
    _945_$retval = 327;
    return _945_$retval;
BB1128:
    $lines[$line_idx++] = "tests/integration/externs/extern-const.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_945_main());
  return 0;
}
