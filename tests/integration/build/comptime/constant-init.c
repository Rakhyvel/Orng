/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _28_add(int64_t _28_x,int64_t _28_y);
int64_t _26_main(void);

/* Function definitions */
int64_t _28_add(int64_t _28_x,int64_t _28_y) {
    int64_t _28_$retval;
    _28_$retval = $add_int64_t(_28_x, _28_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _28_$retval;
}

int64_t _26_main(void) {
    int64_t _26_$retval;
    _26_$retval = 238;
    return _26_$retval;
}

int main(void) {
  printf("%ld",_26_main());
  return 0;
}
