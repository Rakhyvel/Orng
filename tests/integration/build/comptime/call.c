/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Function forward definitions */
int64_t _17_add(int64_t _17_x,int64_t _17_y);
int64_t _13_main(void);

/* Function definitions */
int64_t _17_add(int64_t _17_x,int64_t _17_y){
    int64_t _17_$retval;
    _17_$retval = $add_int64_t(_17_x, _17_y, "tests/integration/comptime/call.orng:8:36:\nfn add(x: Int, y: Int) -> Int { x + y }\n                                  ^");
    return _17_$retval;
}

int64_t _13_main(void){
    int64_t _13_$retval;
    _13_$retval = 235;
    return _13_$retval;
}

int main(void) {
  printf("%ld",_13_main());
  return 0;
}
