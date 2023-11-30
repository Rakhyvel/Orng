/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _16_add(int64_t _16_x,int64_t _16_y);
int64_t _12_main(void);

/* Function definitions */
int64_t _16_add(int64_t _16_x,int64_t _16_y) {
    int64_t _16_$retval;
    _16_$retval = $add_int64_t(_16_x, _16_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _16_$retval;
}

int64_t _12_main(void) {
    int64_t _12_$retval;
    _12_$retval = 235;
    return _12_$retval;
}

int main(void) {
  printf("%ld",_12_main());
  return 0;
}
