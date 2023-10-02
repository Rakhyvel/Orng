/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();
int64_t _3_f(int64_t _3_x);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_t0;
    int64_t _1_$retval;
$lines[$line_idx++] = "tests/integration/expressions/neq-0-rhs.orng:3:7:\n    f(1)\n     ^";    _1_t0 = _3_f(1);
    $line_idx--;
    _1_$retval = _1_t0;
    return _1_$retval;
}

int64_t _3_f(int64_t _3_x) {
    int64_t _3_t0;
    int64_t _3_$retval;
    if (_3_x) {
        goto BB1;
    } else {
        goto BB5;
    }
BB1:
    _3_t0 = 173;
    goto BB4;
BB5:
    _3_t0 = 3;
BB4:
    _3_$retval = _3_t0;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
