/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_id(int64_t _3_x);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/named-1arg.orng:3:8:\n    id(.x = 52)\n      ^";
    $line_idx--;
    _1_$retval = _3_id(52);
    return _1_$retval;
}

int64_t _3_id(int64_t _3_x) {
    int64_t _3_$retval;
    _3_$retval = _3_x;
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
