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
int64_t _1034_main(void);
int64_t _1036_$anon94(void);


/* Function definitions */
int64_t _1034_main(void){
    function0 _1034_t0;
    int64_t _1034_t1;
    int64_t _1034_$retval;
    _1034_t0 = (function0) _1036_$anon94;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-1-arg.orng:6:12:\n    getval(Int)\n          ^";
    _1034_t1 = _1034_t0();
    $line_idx--;
    _1034_$retval = _1034_t1;
    return _1034_$retval;
}

int64_t _1036_$anon94(void){
    int64_t _1036_$retval;
    _1036_$retval = 313;
    return _1036_$retval;
}


int main(void) {
  printf("%ld",_1034_main());
  return 0;
}
