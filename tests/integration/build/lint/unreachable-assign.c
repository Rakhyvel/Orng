/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1157_main(void);


/* Function definitions */
int64_t _1157_main(void){
    $lines[$line_idx++] = "tests/integration/lint/unreachable-assign.orng:3:24:\n    let x = unreachable\n                      ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1157_main());
  return 0;
}
