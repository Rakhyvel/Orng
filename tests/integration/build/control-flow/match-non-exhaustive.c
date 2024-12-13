/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _502_main(void);


/* Function definitions */
int64_t _502_main(void){
    goto BB582;
BB582:
    $lines[$line_idx++] = "tests/integration/control-flow/match-non-exhaustive.orng:3:23:\n    let x: Int = match true {\n                     ^";
    $panic("could not match pattern\n");
}


int main(void) {
  printf("%ld",_502_main());
  return 0;
}
