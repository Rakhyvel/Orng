/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _93_add(int64_t _93_x,int64_t _93_y);
int64_t _90_main(void);

/* Function definitions */
int64_t _93_add(int64_t _93_x,int64_t _93_y) {
    int64_t _93_$retval;
    _93_$retval = $add_int64_t(_93_x, _93_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _93_$retval;
}

int64_t _90_main(void) {
    int64_t _90_$retval;
    _90_$retval = 235;
    return _90_$retval;
}

int main(void) {
  printf("%ld",_90_main());
  return 0;
}
