/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _16_add(int64_t _16_x,int64_t _16_y);
int64_t _14_main(void);

/* Function definitions */
int64_t _16_add(int64_t _16_x,int64_t _16_y) {
    int64_t _16_$retval;
    _16_$retval = $add_int64_t(_16_x, _16_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _16_$retval;
}

int64_t _14_main(void) {
    int64_t _14_$retval;
    _14_$retval = 238;
    return _14_$retval;
}

int main(void) {
  printf("%ld",_14_main());
  return 0;
}
