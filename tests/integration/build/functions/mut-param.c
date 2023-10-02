/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();
int64_t _3_sum_down(int64_t _3_x);

/* Function definitions */
int64_t _1_main() {
    int64_t _1_t0;
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/mut-param.orng:2:28:\nfn main() -> Int {sum_down(8) + 2}\n                          ^";
    _1_t0 = _3_sum_down(8);
    $line_idx--;
    _1_$retval = _1_t0 + 2;
    return _1_$retval;
}

int64_t _3_sum_down(int64_t _3_x) {
    int64_t _5_i;
    int64_t _3_$retval;
    _5_i = _3_x;
BB1:
    if (_5_i >= 0) {
        goto BB2;
    } else {
        goto BB7;
    }
BB2:
    _3_x = _3_x + _5_i;
    _5_i = _5_i - 1;
    goto BB1;
BB7:
    _3_$retval = _3_x;
    return _3_$retval;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
