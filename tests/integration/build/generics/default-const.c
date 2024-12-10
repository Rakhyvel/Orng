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
int64_t _1081_main(void);
int64_t _1083_$anon105(void);


/* Function definitions */
int64_t _1081_main(void){
    function0 _1081_t0;
    int64_t _1081_t1;
    int64_t _1081_$retval;
    _1081_t0 = (function0) _1083_$anon105;
    $lines[$line_idx++] = "tests/integration/generics/default-const.orng:12:12:\n    getval()\n          ^";
    _1081_t1 = _1081_t0();
    $line_idx--;
    _1081_$retval = _1081_t1;
    return _1081_$retval;
}

int64_t _1083_$anon105(void){
    int64_t _1083_$retval;
    goto BB1255;
BB1255:
    _1083_$retval = 315;
    return _1083_$retval;
}


int main(void) {
  printf("%ld",_1081_main());
  return 0;
}
