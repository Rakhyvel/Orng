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
int64_t _1030_main(void);
int64_t _1032_$anon96(void);


/* Function definitions */
int64_t _1030_main(void){
    function0 _1030_t0;
    int64_t _1030_t1;
    int64_t _1030_$retval;
    _1030_t0 = (function0) _1032_$anon96;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1030_t1 = _1030_t0();
    $line_idx--;
    _1030_$retval = _1030_t1;
    return _1030_$retval;
}

int64_t _1032_$anon96(void){
    int64_t _1032_$retval;
    _1032_$retval = 314;
    return _1032_$retval;
}


int main(void) {
  printf("%ld",_1030_main());
  return 0;
}
