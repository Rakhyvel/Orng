/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _177_add(int64_t _177_x,int64_t _177_y);
int64_t _175_main(void);

/* Function definitions */
int64_t _177_add(int64_t _177_x,int64_t _177_y){
    int64_t _177_$retval;
    _177_$retval = $add_int64_t(_177_x, _177_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _177_$retval;
}

int64_t _175_main(void){
    int64_t _175_$retval;
    _175_$retval = 238;
    return _175_$retval;
}

int main(void) {
  printf("%ld",_175_main());
  return 0;
}
