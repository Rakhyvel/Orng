/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _12_add(int64_t _12_x,int64_t _12_y);
int64_t _8_main(void);

/* Function definitions */
int64_t _12_add(int64_t _12_x,int64_t _12_y) {
    int64_t _12_$retval;
    _12_$retval = $add_int64_t(_12_x, _12_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _12_$retval;
}

int64_t _8_main(void) {
    int64_t _8_$retval;
    _8_$retval = 235;
    return _8_$retval;
}

int main(void) {
  printf("%ld",_8_main());
  return 0;
}
