/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
void _3_void(void);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/void-return.orng:3:10:\n    void()\n        ^";
    _3_void();
    $line_idx--;
    _1_$retval = 65;
    return _1_$retval;
}

void _3_void(void) {
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
