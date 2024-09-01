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
int64_t _2_main(void);
int64_t _4_$anon0(void);


/* Function definitions */
int64_t _2_main(void){
    function0 _2_t0;
    int64_t _2_t1;
    int64_t _2_$retval;
    _2_t0 = (function0) _4_$anon0;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _2_t1 = _2_t0();
    $line_idx--;
    _2_$retval = _2_t1;
    return _2_$retval;
}

int64_t _4_$anon0(void){
    int64_t _4_$retval;
    _4_$retval = 313;
    return _4_$retval;
}


int main(void) {
  printf("%ld",_2_main());
  return 0;
}
