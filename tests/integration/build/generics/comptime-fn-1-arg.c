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
int64_t _1025_main(void);
int64_t _1027_$anon94(void);


/* Function definitions */
int64_t _1025_main(void){
    function0 _1025_t0;
    int64_t _1025_t1;
    int64_t _1025_$retval;
    _1025_t0 = (function0) _1027_$anon94;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _1025_t1 = _1025_t0();
    $line_idx--;
    _1025_$retval = _1025_t1;
    return _1025_$retval;
}

int64_t _1027_$anon94(void){
    int64_t _1027_$retval;
    _1027_$retval = 313;
    return _1027_$retval;
}


int main(void) {
  printf("%ld",_1025_main());
  return 0;
}
