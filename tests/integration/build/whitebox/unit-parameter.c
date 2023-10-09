/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _4_f(int64_t _4_x);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/whitebox/unit-parameter.orng:3:7:\n    f({}, 219)\n     ^";
    $line_idx--;
    _1_$retval = _4_f(219);
    return _1_$retval;
}

int64_t _4_f(int64_t _4_x) {
    int64_t _4_$retval;
    _4_$retval = _4_x;
    return _4_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
