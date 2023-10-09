/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _1_main(void);
int64_t _3_add(int64_t _3_x,int64_t _3_y);

/* Function definitions */
int64_t _1_main(void) {
    int64_t _1_$retval;
    $lines[$line_idx++] = "tests/integration/functions/default-named.orng:3:9:\n    add(.x = 4)\n       ^";
    $line_idx--;
    _1_$retval = _3_add(4, 50);
    return _1_$retval;
}

int64_t _3_add(int64_t _3_x,int64_t _3_y) {
    int64_t _3_$retval;
    _3_$retval = $add_int64_t(_3_x, _3_y, "tests/integration/functions/default-named.orng:6:40:\nfn add(x: Int, y: Int = 50) -> Int {x + y}\n                                      ^");
    return _3_$retval;
}

int main(void)
{
  printf("%ld",_1_main());
  return 0;
}
