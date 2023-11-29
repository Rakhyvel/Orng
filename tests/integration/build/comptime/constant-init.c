/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _22_add(int64_t _22_x,int64_t _22_y);
int64_t _20_main(void);

/* Function definitions */
int64_t _22_add(int64_t _22_x,int64_t _22_y) {
    int64_t _22_$retval;
    _22_$retval = $add_int64_t(_22_x, _22_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _22_$retval;
}

int64_t _20_main(void) {
    int64_t _20_$retval;
    _20_$retval = 238;
    return _20_$retval;
}

int main(void) {
  printf("%ld",_20_main());
  return 0;
}
