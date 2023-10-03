/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main();
void _3_f(int64_t* _3_y);

/* Function definitions */
int64_t _1_main() {
    int64_t _2_x;
    int64_t* _2_y;
    int64_t _1_$retval;
    _2_x = 4;
    _2_y = &_2_x;
    $lines[$line_idx++] = "tests/integration/expressions/deref-copy-param.orng:5:7:\n    f(y)\n     ^";
    _3_f(_2_y);
    $line_idx--;
    _1_$retval = *_2_y;
    return _1_$retval;
}

void _3_f(int64_t* _3_y) {
    **&_3_y = 195;
}

int main()
{
  printf("%ld",_1_main());
  return 0;
}
