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
int64_t _7_main(void);
int64_t _9_$anon1(void);


/* Function definitions */
int64_t _7_main(void){
    function0 _7_t0;
    int64_t _7_t1;
    int64_t _7_$retval;
    _7_t0 = (function0) _9_$anon1;
    $lines[$line_idx++] = "tests/integration/generics/comptime-fn-non-type.orng:6:12:\n    getval(300, 14)\n          ^";
    _7_t1 = _7_t0();
    $line_idx--;
    _7_$retval = _7_t1;
    return _7_$retval;
}

int64_t _9_$anon1(void){
    int64_t _9_$retval;
    _9_$retval = 314;
    return _9_$retval;
}


int main(void) {
  printf("%ld",_7_main());
  return 0;
}
