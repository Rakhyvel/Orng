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
int64_t _1056_main(void);
int64_t _1058_$anon99(void);


/* Function definitions */
int64_t _1056_main(void){
    function0 _1056_t0;
    int64_t _1056_t1;
    int64_t _1056_$retval;
    _1056_t0 = (function0) _1058_$anon99;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _1056_t1 = _1056_t0();
    $line_idx--;
    _1056_$retval = _1056_t1;
    return _1056_$retval;
}

int64_t _1058_$anon99(void){
    int64_t _1058_$retval;
    _1058_$retval = 313;
    return _1058_$retval;
}


int main(void) {
  printf("%ld",_1056_main());
  return 0;
}
