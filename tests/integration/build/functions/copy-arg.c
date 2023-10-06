/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_g(int64_t _3_x);
int64_t _5_f(int64_t _5_x);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:3:7:\n    g(194)\n     ^";
    $line_idx--;
    _1_$retval = _3_g(194);
    return _1_$retval;
}

int64_t _3_g(int64_t _3_x) {
    int64_t _3_$retval;
    $lines[$line_idx++] = "tests/integration/functions/copy-arg.orng:8:7:\n    f(z)\n     ^";
    $line_idx--;
    _3_$retval = _5_f(_3_x);
    return _3_$retval;
}

int64_t _5_f(int64_t _5_x) {
    int64_t _5_$retval;
    _5_$retval = _5_x;
    return _5_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
