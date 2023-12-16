/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _167_add(int64_t _167_x,int64_t _167_y);
int64_t _163_main(void);

/* Function definitions */
int64_t _167_add(int64_t _167_x,int64_t _167_y) {
    int64_t _167_$retval;
    _167_$retval = $add_int64_t(_167_x, _167_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _167_$retval;
}

int64_t _163_main(void) {
    int64_t _163_$retval;
    _163_$retval = 235;
    return _163_$retval;
}

int main(void) {
  printf("%ld",_163_main());
  return 0;
}
