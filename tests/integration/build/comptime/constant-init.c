/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _113_add(int64_t _113_x, int64_t _113_y);
int64_t _111_main(void);

/* Function definitions */
int64_t _113_add(int64_t _113_x, int64_t _113_y){
    int64_t _113_$retval;
    _113_$retval = $add_int64_t(_113_x, _113_y, "tests/integration/comptime/constant-init.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _113_$retval;
}

int64_t _111_main(void){
    int64_t _111_$retval;
    _111_$retval = 238;
    return _111_$retval;
}

int main(void) {
  printf("%ld",_111_main());
  return 0;
}
