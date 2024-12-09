/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _928_main(void);


/* Function definitions */
int64_t _928_main(void){
    int64_t _928_t1;
    uint8_t _928_t3;
    int64_t _928_$retval;
    _928_t1 = 0;
    _928_t3 = EXIT_SUCCESS==_928_t1;
    if (_928_t3) {
        goto BB1106;
    } else {
        goto BB1110;
    }
BB1106:
    _928_$retval = 327;
    return _928_$retval;
BB1110:
    $lines[$line_idx++] = "tests/integration/externs/extern-const.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_928_main());
  return 0;
}
