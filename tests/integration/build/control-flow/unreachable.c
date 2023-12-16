/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _387_main(void);

/* Function definitions */
int64_t _387_main(void) {
    $lines[$line_idx++] = "tests/integration/control-flow/unreachable.orng:2:30:\nfn main() -> Int {unreachable}\n                            ^";
    $panic("reached unreachable code\n");
}

int main(void) {
  printf("%ld",_387_main());
  return 0;
}
