/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _183_add(int64_t _183_x,int64_t _183_y);
int64_t _181_main(void);

/* Function definitions */
int64_t _183_add(int64_t _183_x,int64_t _183_y){
    int64_t _183_$retval;
    _183_$retval = $add_int64_t(_183_x, _183_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _183_$retval;
}

int64_t _181_main(void){
    int64_t _181_$retval;
    _181_$retval = 238;
    return _181_$retval;
}

int main(void) {
  printf("%ld",_181_main());
  return 0;
}
