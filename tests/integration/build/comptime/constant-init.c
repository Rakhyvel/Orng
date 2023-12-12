/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _101_add(int64_t _101_x,int64_t _101_y);
int64_t _99_main(void);

/* Function definitions */
int64_t _101_add(int64_t _101_x,int64_t _101_y) {
    int64_t _101_$retval;
    _101_$retval = $add_int64_t(_101_x, _101_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _101_$retval;
}

int64_t _99_main(void) {
    int64_t _99_$retval;
    _99_$retval = 238;
    return _99_$retval;
}

int main(void) {
  printf("%ld",_99_main());
  return 0;
}
