/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _106_add(int64_t _106_x, int64_t _106_y);
int64_t _102_main(void);


/* Function definitions */
int64_t _106_add(int64_t _106_x, int64_t _106_y){
    int64_t _106_$retval;
    _106_$retval = $add_int64_t(_106_x, _106_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _106_$retval;
}

int64_t _102_main(void){
    int64_t _102_$retval;
    _102_$retval = 235;
    return _102_$retval;
}


int main(void) {
  printf("%ld",_102_main());
  return 0;
}
