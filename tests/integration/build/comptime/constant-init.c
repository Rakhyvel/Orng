/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _179_add(int64_t _179_x,int64_t _179_y);
int64_t _177_main(void);

/* Function definitions */
int64_t _179_add(int64_t _179_x,int64_t _179_y) {
    int64_t _179_$retval;
    _179_$retval = $add_int64_t(_179_x, _179_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _179_$retval;
}

int64_t _177_main(void) {
    int64_t _177_$retval;
    _177_$retval = 238;
    return _177_$retval;
}

int main(void) {
  printf("%ld",_177_main());
  return 0;
}
