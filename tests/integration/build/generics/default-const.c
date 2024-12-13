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
int64_t _1083_main(void);
int64_t _1085_$anon105(void);


/* Function definitions */
int64_t _1083_main(void){
    function0 _1083_t0;
    int64_t _1083_t1;
    int64_t _1083_$retval;
    _1083_t0 = (function0) _1085_$anon105;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1083_t1 = _1083_t0();
    $line_idx--;
    _1083_$retval = _1083_t1;
    return _1083_$retval;
}

int64_t _1085_$anon105(void){
    int64_t _1085_$retval;
    goto BB1257;
BB1257:
    _1085_$retval = 315;
    return _1085_$retval;
}


int main(void) {
  printf("%ld",_1083_main());
  return 0;
}
