/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _10_add(int64_t _10_x,int64_t _10_y);
int64_t _7_main(void);

/* Function definitions */
int64_t _10_add(int64_t _10_x,int64_t _10_y) {
    int64_t _10_$retval;
    _10_$retval = $add_int64_t(_10_x, _10_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _10_$retval;
}

int64_t _7_main(void) {
    int64_t _7_$retval;
    _7_$retval = 235;
    return _7_$retval;
}

int main(void) {
  printf("%ld",_7_main());
  return 0;
}
