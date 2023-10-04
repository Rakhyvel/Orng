/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
void _3_f(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/expressions/unit.orng:3:7:\n    f()\n     ^";
    _3_f();
    $line_idx--;
    _1_$retval = 48;
    return _1_$retval;
}

void _3_f(void) {
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
