/* Code generated using the Orng compiler https://ornglang.org */
#include <math.h>
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "debug.inc"

/* Forward struct, union, and function declarations */

/* Struct, union, and function definitions */
typedef int64_t(*function0)(void);

/* Function forward definitions */
int64_t _1064_main(void);
int64_t _1066_$anon101(void);


/* Function definitions */
int64_t _1064_main(void){
    function0 _1064_t0;
    int64_t _1064_t1;
    int64_t _1064_$retval;
    _1064_t0 = (function0) _1066_$anon101;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1064_t1 = _1064_t0();
    $line_idx--;
    _1064_$retval = _1064_t1;
    return _1064_$retval;
}

int64_t _1066_$anon101(void){
    int64_t _1066_$retval;
    _1066_$retval = 314;
    return _1066_$retval;
}


int main(void) {
  printf("%ld",_1064_main());
  return 0;
}
