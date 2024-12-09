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
int64_t _1039_main(void);
int64_t _1041_$anon96(void);


/* Function definitions */
int64_t _1039_main(void){
    function0 _1039_t0;
    int64_t _1039_t1;
    int64_t _1039_$retval;
    _1039_t0 = (function0) _1041_$anon96;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _1039_t1 = _1039_t0();
    $line_idx--;
    _1039_$retval = _1039_t1;
    return _1039_$retval;
}

int64_t _1041_$anon96(void){
    int64_t _1041_$retval;
    _1041_$retval = 313;
    return _1041_$retval;
}


int main(void) {
  printf("%ld",_1039_main());
  return 0;
}
