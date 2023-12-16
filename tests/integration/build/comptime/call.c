/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _173_add(int64_t _173_x,int64_t _173_y);
int64_t _169_main(void);

/* Function definitions */
int64_t _173_add(int64_t _173_x,int64_t _173_y){
    int64_t _173_$retval;
    _173_$retval = $add_int64_t(_173_x, _173_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _173_$retval;
}

int64_t _169_main(void){
    int64_t _169_$retval;
    _169_$retval = 235;
    return _169_$retval;
}

int main(void) {
  printf("%ld",_169_main());
  return 0;
}
