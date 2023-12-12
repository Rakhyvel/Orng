/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _18_add(int64_t _18_x,int64_t _18_y);
int64_t _16_main(void);

/* Function definitions */
int64_t _18_add(int64_t _18_x,int64_t _18_y) {
    int64_t _18_$retval;
    _18_$retval = $add_int64_t(_18_x, _18_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _18_$retval;
}

int64_t _16_main(void) {
    int64_t _16_$retval;
    _16_$retval = 238;
    return _16_$retval;
}

int main(void) {
  printf("%ld",_16_main());
  return 0;
}
