/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _103_add(int64_t _103_x,int64_t _103_y);
int64_t _99_main(void);

/* Function definitions */
int64_t _103_add(int64_t _103_x,int64_t _103_y){
    int64_t _103_$retval;
    _103_$retval = $add_int64_t(_103_x, _103_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _103_$retval;
}

int64_t _99_main(void){
    int64_t _99_$retval;
    _99_$retval = 235;
    return _99_$retval;
}

int main(void) {
  printf("%ld",_99_main());
  return 0;
}
