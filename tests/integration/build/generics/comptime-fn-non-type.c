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
int64_t _1036_main(void);
int64_t _1038_$anon96(void);


/* Function definitions */
int64_t _1036_main(void){
    function0 _1036_t0;
    int64_t _1036_t1;
    int64_t _1036_$retval;
    _1036_t0 = (function0) _1038_$anon96;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _1036_t1 = _1036_t0();
    $line_idx--;
    _1036_$retval = _1036_t1;
    return _1036_$retval;
}

int64_t _1038_$anon96(void){
    int64_t _1038_$retval;
    _1038_$retval = 314;
    return _1038_$retval;
}


int main(void) {
  printf("%ld",_1036_main());
  return 0;
}
