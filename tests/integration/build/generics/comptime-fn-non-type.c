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
int64_t _1044_main(void);
int64_t _1046_$anon96(void);


/* Function definitions */
int64_t _1044_main(void){
    function0 _1044_t0;
    int64_t _1044_t1;
    int64_t _1044_$retval;
    _1044_t0 = (function0) _1046_$anon96;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1044_t1 = _1044_t0();
    $line_idx--;
    _1044_$retval = _1044_t1;
    return _1044_$retval;
}

int64_t _1046_$anon96(void){
    int64_t _1046_$retval;
    _1046_$retval = 314;
    return _1046_$retval;
}


int main(void) {
  printf("%ld",_1044_main());
  return 0;
}
