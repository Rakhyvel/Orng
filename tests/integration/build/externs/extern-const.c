/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _923_main(void);


/* Function definitions */
int64_t _923_main(void){
    int64_t _923_t1;
    uint8_t _923_t3;
    int64_t _923_$retval;
    _923_t1 = 0;
    _923_t3 = EXIT_SUCCESS==_923_t1;
    if (_923_t3) {
        goto BB1103;
    } else {
        goto BB1107;
    }
BB1103:
    _923_$retval = 327;
    return _923_$retval;
BB1107:
    $lines[$line_idx++] = "tests/integration/externs/extern-const.orng:8:20:\n        unreachable\n                  ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_923_main());
  return 0;
}
