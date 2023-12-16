/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _27_add(int64_t _27_x,int64_t _27_y);
int64_t _25_main(void);

/* Function definitions */
int64_t _27_add(int64_t _27_x,int64_t _27_y){
    int64_t _27_$retval;
    _27_$retval = $add_int64_t(_27_x, _27_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _27_$retval;
}

int64_t _25_main(void){
    int64_t _25_$retval;
    _25_$retval = 238;
    return _25_$retval;
}

int main(void) {
  printf("%ld",_25_main());
  return 0;
}
