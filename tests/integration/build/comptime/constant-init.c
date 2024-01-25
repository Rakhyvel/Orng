/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _117_add(int64_t _117_x, int64_t _117_y);
int64_t _115_main(void);


/* Function definitions */
int64_t _117_add(int64_t _117_x, int64_t _117_y){
    int64_t _117_$retval;
    _117_$retval = $add_int64_t(_117_x, _117_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _117_$retval;
}

int64_t _115_main(void){
    int64_t _115_$retval;
    _115_$retval = 238;
    return _115_$retval;
}


int main(void) {
  printf("%ld",_115_main());
  return 0;
}
