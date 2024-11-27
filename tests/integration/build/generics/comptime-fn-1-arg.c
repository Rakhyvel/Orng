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
int64_t _5_main(void);
int64_t _7_$anon0(void);


/* Function definitions */
int64_t _5_main(void){
    function0 _5_t0;
    int64_t _5_t1;
    int64_t _5_$retval;
    _5_t0 = (function0) _7_$anon0;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _5_t1 = _5_t0();
    $line_idx--;
    _5_$retval = _5_t1;
    return _5_$retval;
}

int64_t _7_$anon0(void){
    int64_t _7_$retval;
    _7_$retval = 313;
    return _7_$retval;
}


int main(void) {
  printf("%ld",_5_main());
  return 0;
}
