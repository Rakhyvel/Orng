/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1419_main(void);


/* Function definitions */
int64_t _1419_main(void){
    goto BB1655;
BB1655:
    $lines[$line_idx++] = "tests/integration/pattern/match-unreachable.orng:4:21:\n        {unreachable} => 35\n                   ^";
    $panic("reached unreachable code\n");
}


int main(void) {
  printf("%ld",_1419_main());
  return 0;
}
